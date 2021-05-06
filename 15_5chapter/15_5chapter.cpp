#include <iostream>
#include <memory>
#include "Resource.h"

auto doSomething()
{
    // 방법 2
    // res1 = std::make_unique<Resource>(5);
    //return res1;

    // 방법 1
    //return std::unique_ptr<Resource>(new Resource(5));

    // 방법3
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
    //// 예제 1)
    //{
    //    //   Resource* res = new Resource(10000000);
    //    
    //    std::unique_ptr<Resource> res(new Resource(10000000));
    //    // early return or throw

    //    //delete res;
    //}
    
    //// 예제 2)
    //{
    //    std::unique_ptr<int> upi(new int);

    //    // 초기화하는 방법 4가지
    //    //auto* ptr = new Resource(5);
    //    //std::unique_ptr<Resource> res1(new Resource(5););
    //    //auto res1 = std::make_unique<Resource>(5);    // make_unique로 초기화방법
    //    auto res1 = doSomething();  // 함수로 초기화 하는 방법

    //    res1->setAll(5);
    //    res1->print();

    //    std::unique_ptr<Resource> res2;

    //    std::cout << std::boolalpha;
    //    std::cout << static_cast<bool>(res1) << std::endl;
    //    std::cout << static_cast<bool>(res2) << std::endl;

    //    //res2 = res1;  // unique_point는 복사가 안됨. 유니콘은 뿔이 하나니 복사가 안된다?ㅎㅎ 
    //    res2 = std::move(res1); // 위의 copy-semantic은 안되고 move-semantic만 가능

    //    std::cout << std::boolalpha;
    //    std::cout << static_cast<bool>(res1) << std::endl;
    //    std::cout << static_cast<bool>(res2) << std::endl;

    //    if (res1 != nullptr) res1->print();
    //    if (res2 != nullptr) res2->print(); // (*res2).print();
    //}

    //// 예제 3)
    //{
    //    auto res1 = std::make_unique<Resource>(5);
    //    res1->setAll(1);
    //    res1->print();

    //    std::cout << std::boolalpha;
    //    std::cout << static_cast<bool>(res1) << std::endl;

    //    //res1 = doSomething2(std::move(res1));
    //    doSomething2(res1.get());   // get함수는 res1이라는 resource의 포인터를 가져오는 것

    //    std::cout << std::boolalpha;
    //    std::cout << static_cast<bool>(res1) << std::endl;

    //    res1->print();
    //}

    // 예제 4), 하지 말아야 할 것
    {
        Resource* res = new Resource;
        std::unique_ptr<Resource> res1(res);
        std::unique_ptr<Resource> res2(res);    // X 소유권을 2곳에다 주는 것

        delete res; // X, unique pointer는 알아서 delete를 해주는데 내가 직접 하려고하면 2번 delete을 하니 하면 안된다.
    }
    return 0;
}