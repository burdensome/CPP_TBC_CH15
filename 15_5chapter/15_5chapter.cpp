#include <iostream>
#include <memory>
#include "Resource.h"

auto doSomething()
{
    // ��� 2
    // res1 = std::make_unique<Resource>(5);
    //return res1;

    // ��� 1
    //return std::unique_ptr<Resource>(new Resource(5));

    // ���3
    return std::make_unique<Resource>(5);
}

//auto doSomething2(std::unique_ptr<Resource> res)
void doSomething2(Resource* res)
{
    res->setAll(100);
    res->print();
    
    //return res;
}

int main()
{
    //// ���� 1)
    //{
    //    //   Resource* res = new Resource(10000000);
    //    
    //    std::unique_ptr<Resource> res(new Resource(10000000));
    //    // early return or throw

    //    //delete res;
    //}
    
    //// ���� 2)
    //{
    //    std::unique_ptr<int> upi(new int);

    //    // �ʱ�ȭ�ϴ� ��� 4����
    //    //auto* ptr = new Resource(5);
    //    //std::unique_ptr<Resource> res1(new Resource(5););
    //    //auto res1 = std::make_unique<Resource>(5);    // make_unique�� �ʱ�ȭ���
    //    auto res1 = doSomething();  // �Լ��� �ʱ�ȭ �ϴ� ���

    //    res1->setAll(5);
    //    res1->print();

    //    std::unique_ptr<Resource> res2;

    //    std::cout << std::boolalpha;
    //    std::cout << static_cast<bool>(res1) << std::endl;
    //    std::cout << static_cast<bool>(res2) << std::endl;

    //    //res2 = res1;  // unique_point�� ���簡 �ȵ�. �������� ���� �ϳ��� ���簡 �ȵȴ�?���� 
    //    res2 = std::move(res1); // ���� copy-semantic�� �ȵǰ� move-semantic�� ����

    //    std::cout << std::boolalpha;
    //    std::cout << static_cast<bool>(res1) << std::endl;
    //    std::cout << static_cast<bool>(res2) << std::endl;

    //    if (res1 != nullptr) res1->print();
    //    if (res2 != nullptr) res2->print(); // (*res2).print();
    //}

    //// ���� 3)
    //{
    //    auto res1 = std::make_unique<Resource>(5);
    //    res1->setAll(1);
    //    res1->print();

    //    std::cout << std::boolalpha;
    //    std::cout << static_cast<bool>(res1) << std::endl;

    //    //res1 = doSomething2(std::move(res1));
    //    doSomething2(res1.get());   // get�Լ��� res1�̶�� resource�� �����͸� �������� ��

    //    std::cout << std::boolalpha;
    //    std::cout << static_cast<bool>(res1) << std::endl;

    //    res1->print();
    //}

    // ���� 4), ���� ���ƾ� �� ��
    {
        Resource* res = new Resource;
        std::unique_ptr<Resource> res1(res);
        std::unique_ptr<Resource> res2(res);    // X �������� 2������ �ִ� ��

        delete res; // X, unique pointer�� �˾Ƽ� delete�� ���ִµ� ���� ���� �Ϸ����ϸ� 2�� delete�� �ϴ� �ϸ� �ȵȴ�.
    }
    return 0;
}