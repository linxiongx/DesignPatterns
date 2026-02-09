#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>

// 抽象组件类
class FileSystemComponent {
protected:
    std::string name;

public:
    FileSystemComponent(const std::string& name) : name(name) {}
    virtual ~FileSystemComponent() = default;

    virtual void display(int depth = 0) const = 0;
    virtual void add(std::shared_ptr<FileSystemComponent> component) {
        throw std::runtime_error("不支持此操作");
    }
    virtual void remove(std::shared_ptr<FileSystemComponent> component) {
        throw std::runtime_error("不支持此操作");
    }
    virtual std::shared_ptr<FileSystemComponent> getChild(int index) {
        throw std::runtime_error("不支持此操作");
    }

    std::string getName() const { return name; }

    virtual int getChildCount() const { return 0; }
};

// 叶子节点：文件
class File : public FileSystemComponent {
private:
    int size; //文件大小

public:
    File(const std::string& name, int size)
        : FileSystemComponent(name), size(size) {
    }

    void display(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "📄 文件: " << name
            << " (" << size << " KB)" << std::endl;
    }

    int getSize() const { return size; }
};

// 组合节点：目录
class Directory : public FileSystemComponent {
private:
    std::vector<std::shared_ptr<FileSystemComponent>> children;

public:
    Directory(const std::string& name) : FileSystemComponent(name) {}

    void add(std::shared_ptr<FileSystemComponent> component) override {
        children.push_back(component);
    }

    void remove(std::shared_ptr<FileSystemComponent> component) override {
        auto it = std::find(children.begin(), children.end(), component);
        if (it != children.end()) {
            children.erase(it);
        }
    }

    std::shared_ptr<FileSystemComponent> getChild(int index) override {
        if (index >= 0 && index < children.size()) {
            return children[index];
        }
        return nullptr;
    }

    int getChildCount() const override {
        return children.size();
    }

    void display(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "📁 目录: " << name << std::endl;

        for (const auto& child : children) {
            child->display(depth + 1);
        }
    }
};

// ============================================
// 查找辅助类 - 负责所有查找操作
// ============================================
class FileSystemFinder {
public:
    // 按名称查找第一个匹配项
    static std::shared_ptr<FileSystemComponent> findByName(
        std::shared_ptr<FileSystemComponent> root,
        const std::string& targetName) {

        if (!root) return nullptr;

        // 检查当前节点
        if (root->getName() == targetName) {
            return root;
        }

        // 递归查找子节点
        int childCount = root->getChildCount();
        for (int i = 0; i < childCount; ++i) {
            auto child = root->getChild(i);
            auto result = findByName(child, targetName);
            if (result) {
                return result;
            }
        }

        return nullptr;
    }

    // 查找所有匹配项
    static std::vector<std::shared_ptr<FileSystemComponent>> findAllByName(
        std::shared_ptr<FileSystemComponent> root,
        const std::string& targetName) {

        std::vector<std::shared_ptr<FileSystemComponent>> results;
        findAllByNameHelper(root, targetName, results);
        return results;
    }

    // 按条件查找
    static std::shared_ptr<FileSystemComponent> findIf(
        std::shared_ptr<FileSystemComponent> root,
        std::function<bool(std::shared_ptr<FileSystemComponent>)> predicate) {

        if (!root) return nullptr;

        // 检查当前节点
        if (predicate(root)) {
            return root;
        }

        // 递归查找子节点
        int childCount = root->getChildCount();
        for (int i = 0; i < childCount; ++i) {
            auto child = root->getChild(i);
            auto result = findIf(child, predicate);
            if (result) {
                return result;
            }
        }

        return nullptr;
    }

    // 按条件查找所有
    static std::vector<std::shared_ptr<FileSystemComponent>> findAllIf(
        std::shared_ptr<FileSystemComponent> root,
        std::function<bool(std::shared_ptr<FileSystemComponent>)> predicate) {

        std::vector<std::shared_ptr<FileSystemComponent>> results;
        findAllIfHelper(root, predicate, results);
        return results;
    }

    // 获取路径
    static std::string getPath(
        std::shared_ptr<FileSystemComponent> root,
        std::shared_ptr<FileSystemComponent> target) {

        std::vector<std::string> path;
        if (findPath(root, target, path)) {
            std::string result;
            for (const auto& name : path) {
                result += "/" + name;
            }
            return result.empty() ? "/" : result;
        }
        return "";
    }

private:
    // 辅助函数：查找所有匹配项
    static void findAllByNameHelper(
        std::shared_ptr<FileSystemComponent> node,
        const std::string& targetName,
        std::vector<std::shared_ptr<FileSystemComponent>>& results) {

        if (!node) return;

        if (node->getName() == targetName) {
            results.push_back(node);
        }

        int childCount = node->getChildCount();
        for (int i = 0; i < childCount; ++i) {
            findAllByNameHelper(node->getChild(i), targetName, results);
        }
    }

    // 辅助函数：按条件查找所有
    static void findAllIfHelper(
        std::shared_ptr<FileSystemComponent> node,
        std::function<bool(std::shared_ptr<FileSystemComponent>)> predicate,
        std::vector<std::shared_ptr<FileSystemComponent>>& results) {

        if (!node) return;

        if (predicate(node)) {
            results.push_back(node);
        }

        int childCount = node->getChildCount();
        for (int i = 0; i < childCount; ++i) {
            findAllIfHelper(node->getChild(i), predicate, results);
        }
    }

    // 辅助函数：查找路径
    static bool findPath(
        std::shared_ptr<FileSystemComponent> node,
        std::shared_ptr<FileSystemComponent> target,
        std::vector<std::string>& path) {

        if (!node) return false;

        path.push_back(node->getName());

        if (node == target) {
            return true;
        }

        int childCount = node->getChildCount();
        for (int i = 0; i < childCount; ++i) {
            if (findPath(node->getChild(i), target, path)) {
                return true;
            }
        }

        path.pop_back();
        return false;
    }
};

