// CompositeMode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Leaf.h"
#include "Composite.h"
#include "ComponentRegistry.h"

int main()
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

