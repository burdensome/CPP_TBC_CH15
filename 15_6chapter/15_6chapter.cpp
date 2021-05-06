#include <iostream>
#include "Resource.h"

//void soSomething(std::unique_ptr<Resource> res)
//{
//
//}

int main()
{
    //soSomething(std::unique_ptr<Resource>(new Resource(10000000)));
    //soSomething(std::make_unique<Resource>(100000));
    //Resource* res = new Resource(3);
    //res->setAll(1);

    {
        //std::shared_ptr<Resource> ptr1(res);

        auto ptr1 = std::make_shared<Resource>(3);
        ptr1->setAll(1);

        ptr1->print();

        {
            //std::shared_ptr<Resource> ptr2(ptr1);
            
            // ptr1을 share하는게 아니고 res를 바로 넣으면 문제가생김. 이렇게 사용하면 안됨
            // ptr2 입장에서 ptr1이 소유권을 갖고 있다는 것을 알 방법이 없기 때문임.
            // 그래서 이렇게 하면 안되는 것이고 포인터로 초기화를 해주는 것이 좋음
            //std::shared_ptr<Resource> ptr2(res);    
            auto ptr2 = ptr1;

            ptr2->setAll(3);
            ptr2->print();

            std::cout << "Going out of the block" << std::endl;
        }

        ptr1->print();

        std::cout << "Going out of the outer block" << std::endl;
    }


    return 0;

}