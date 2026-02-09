#include <iostream>

/**
 * 抽象类 (AbstractClass)
 * 定义了算法的骨架
 */
class CaffeineBeverage {
public:
    // 模版方法 (Template Method)
    // 采用 NVI (Non-Virtual Interface) 惯用法：
    // 将模版方法定义为非虚函数。这样子类就无法重写(override)它，
    // 从而保证了算法骨架(步骤顺序)的稳定性，无需 explicit 'final'。
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    // 具体方法 (Concrete Operation) -所有子类通用的步骤
    void boilWater() {
        std::cout << "1. 烧开水 (Boiling water)" << std::endl;
    }

    // 抽象方法 (Primitive Operation) - 需要子类实现的步骤
    // protected 权限：只允许子类实现，不允许外部直接调用这些步骤
    virtual void brew() = 0;

    // 具体方法
    void pourInCup() {
        std::cout << "3. 倒入杯子 (Pouring into cup)" << std::endl;
    }

    // 抽象方法
    virtual void addCondiments() = 0;

    virtual ~CaffeineBeverage() = default;
};

/**
 * 具体类 (ConcreteClass) - 茶
 */
class Tea : public CaffeineBeverage {
protected:
    void brew() override {
        std::cout << "2. 浸泡茶叶 (Steeping the tea)" << std::endl;
    }

    void addCondiments() override {
        std::cout << "4. 加柠檬 (Adding lemon)" << std::endl;
    }
};

/**
 * 具体类 (ConcreteClass) - 咖啡
 */
class Coffee : public CaffeineBeverage {
protected:
    void brew() override {
        std::cout << "2. 冲泡咖啡 (Dripping coffee through filter)" << std::endl;
    }

    void addCondiments() override {
        std::cout << "4. 加糖和牛奶 (Adding sugar and milk)" << std::endl;
    }
};

int main() {
    std::cout << "=== 制作茶 (Making Tea) ===" << std::endl;
    Tea tea;
    tea.prepareRecipe();

    std::cout << "\n=== 制作咖啡 (Making Coffee) ===" << std::endl;
    Coffee coffee;
    coffee.prepareRecipe();

    return 0;
}
