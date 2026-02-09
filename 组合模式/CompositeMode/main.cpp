// CompositeMode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Leaf.h"
#include "Composite.h"
#include "ComponentRegistry.h"
#include "第二个例子.h"

// 客户端代码
int main() {
    // 创建根目录
    auto root = std::make_shared<Directory>("root");

    // 创建子目录
    auto documents = std::make_shared<Directory>("Documents");
    auto photos = std::make_shared<Directory>("Photos");
    auto work = std::make_shared<Directory>("Work");

    // 创建文件
    auto file1 = std::make_shared<File>("resume.pdf", 120);
    auto file2 = std::make_shared<File>("letter.docx", 50);
    auto file3 = std::make_shared<File>("vacation.jpg", 2048);
    auto file4 = std::make_shared<File>("family.jpg", 1024);
    auto file5 = std::make_shared<File>("report.pdf", 300);
    auto file6 = std::make_shared<File>("notes.txt", 15);
    auto file7 = std::make_shared<File>("report.pdf", 250); // 重名文件

    // 构建树形结构
    documents->add(file1);
    documents->add(file2);
    documents->add(file6);

    photos->add(file3);
    photos->add(file4);

    work->add(file5);
    work->add(file7);

    root->add(documents);
    root->add(photos);
    root->add(work);
    root->add(std::make_shared<File>("README.txt", 10));

    // 显示文件系统结构
    std::cout << "===== 文件系统结构 =====" << std::endl;
    root->display();
    std::cout << std::endl;

    // 1. 按名称查找单个文件
    std::cout << "===== 测试1: 按名称查找 =====" << std::endl;
    auto found1 = FileSystemFinder::findByName(root, "vacation.jpg");
    if (found1) {
        std::cout << "✅ 找到文件: " << found1->getName() << std::endl;
    }
    else {
        std::cout << "❌ 未找到文件" << std::endl;
    }

    // 2. 查找目录
    auto found2 = FileSystemFinder::findByName(root, "Photos");
    if (found2) {
        std::cout << "✅ 找到目录: " << found2->getName() << std::endl;
    }
    std::cout << std::endl;

    // 3. 查找所有同名文件
    std::cout << "===== 测试2: 查找所有同名文件 =====" << std::endl;
    auto allReports = FileSystemFinder::findAllByName(root, "report.pdf");
    std::cout << "找到 " << allReports.size() << " 个名为 'report.pdf' 的文件" << std::endl;
    std::cout << std::endl;

    // 4. 按条件查找：查找大于1000KB的文件
    std::cout << "===== 测试3: 按条件查找 (大于1000KB) =====" << std::endl;
    auto largeFiles = FileSystemFinder::findAllIf(root,
        [](std::shared_ptr<FileSystemComponent> comp) {
            auto file = std::dynamic_pointer_cast<File>(comp);
            return file && file->getSize() > 1000;
        });

    std::cout << "找到 " << largeFiles.size() << " 个大文件:" << std::endl;
    for (const auto& file : largeFiles) {
        auto f = std::dynamic_pointer_cast<File>(file);
        std::cout << "  - " << f->getName() << " (" << f->getSize() << " KB)" << std::endl;
    }
    std::cout << std::endl;

    // 5. 查找PDF文件
    std::cout << "===== 测试4: 查找所有PDF文件 =====" << std::endl;
    auto pdfFiles = FileSystemFinder::findAllIf(root,
        [](std::shared_ptr<FileSystemComponent> comp) {
            std::string name = comp->getName();
            return name.size() >= 4 && name.substr(name.size() - 4) == ".pdf";
        });

    std::cout << "找到 " << pdfFiles.size() << " 个PDF文件:" << std::endl;
    for (const auto& file : pdfFiles) {
        std::cout << "  - " << file->getName() << std::endl;
    }
    std::cout << std::endl;

    // 6. 获取文件路径
    std::cout << "===== 测试5: 获取文件路径 =====" << std::endl;
    auto targetFile = FileSystemFinder::findByName(root, "vacation.jpg");
    if (targetFile) {
        std::string path = FileSystemFinder::getPath(root, targetFile);
        std::cout << "文件 'vacation.jpg' 的完整路径: " << path << std::endl;
    }

    auto targetDir = FileSystemFinder::findByName(root, "Work");
    if (targetDir) {
        std::string path = FileSystemFinder::getPath(root, targetDir);
        std::cout << "目录 'Work' 的完整路径: " << path << std::endl;
    }

    return 0;
}

//### 输出结果
//```
//==== = 文件系统结构 ==== =
//📁 目录 : root
//   📁 目录 : Documents
//      📄 文件 : resume.pdf(120 KB)
//      📄 文件 : letter.docx(50 KB)
//      📄 文件 : notes.txt(15 KB)
//   📁 目录 : Photos
//      📄 文件 : vacation.jpg(2048 KB)
//      📄 文件 : family.jpg(1024 KB)
//   📁 目录 : Work
//      📄 文件 : report.pdf(300 KB)
//      📄 文件 : report.pdf(250 KB)
//      📄 文件 : README.txt(10 KB)
//
//==== = 测试1 : 按名称查找 ==== =
//✅ 找到文件 : vacation.jpg
//✅ 找到目录 : Photos
//
//==== = 测试2 : 查找所有同名文件 ==== =
//找到 2 个名为 'report.pdf' 的文件
//
//==== = 测试3 : 按条件查找(大于1000KB) ==== =
//找到 2 个大文件 :
//    -vacation.jpg(2048 KB)
//    - family.jpg(1024 KB)
//
//    ==== = 测试4 : 查找所有PDF文件 ==== =
//    找到 3 个PDF文件 :
//    -resume.pdf
//    - report.pdf
//    - report.pdf
//
//    ==== = 测试5 : 获取文件路径 ==== =
//    文件 'vacation.jpg' 的完整路径 : / root / Photos / vacation.jpg
//    目录 'Work' 的完整路径 : / root / Work

int main2()
{
    //Composite root("1");

    do
    {
        auto pRoot = std::make_shared<Composite>("1");


        pRoot->add(std::make_shared<Leaf>("2"));
        pRoot->add(std::make_shared<Composite>("3"));
        pRoot->add(std::make_shared<Composite>("4"));

        auto pComposite2 = pRoot->find("4");
        if (pComposite2)
        {
            pComposite2->add(std::make_shared<Composite>("5"));
            pComposite2->add(std::make_shared<Composite>("6"));
        }


        pRoot->operation();

        if (auto pFind = pRoot->find("5"); pFind != nullptr)
            std::cout << "I'm find!" << std::endl;


        Composite* pTest = new Composite("xx");
        pTest->operation();
        pTest->find("xx");
    } while (0);

    std::cout << "\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";

    do
    {
        auto pRoot = std::make_shared<Composite>("1");

        std::shared_ptr<Leaf> pLeaf = std::make_shared<Leaf>("2");

        pRoot->add(pLeaf);


        auto pComposite1 = std::make_shared<Composite>("3");
        auto pComposite2 = std::make_shared<Composite>("4");



        pRoot->add(pComposite1);
        pRoot->add(pComposite2);

        auto pComposite3 = std::make_shared<Composite>("5");
        auto pComposite4 = std::make_shared<Composite>("6");

        pComposite2->add(pComposite3);
        pComposite2->add(pComposite4);

        pRoot->operation();

        if (auto pFind = pRoot->find("5"); pFind != nullptr)
            std::cout << "I'm find!" << std::endl;


        Composite* pTest = new Composite("xx");
        pTest->operation();
        pTest->find("xx");

        std::cout << "\n\n\n开始查找测试................" << std::endl;

        ComponentRegistry stuRegister;
        stuRegister.registerComponent("3", pComposite1);
        stuRegister.registerComponent("4", pComposite2);
        stuRegister.registerComponent("5", pComposite3);
        stuRegister.registerComponent("6", pComposite4);

        auto ptr = stuRegister.findComponent("3");
        if (ptr)
        {
            ptr->operation();
        }

    } while (0);

    return 0;
}

