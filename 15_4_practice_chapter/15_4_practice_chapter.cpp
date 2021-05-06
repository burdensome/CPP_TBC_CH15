#include "AutoPtr.h"
#include "Resource.h"
#include <vector>

using namespace std;

template<class T>
void MySwap(T& a, T& b)
{
    /*T tmp = a;
    a = b;
    b = tmp;*/

    T tmp{ std::move(a) };
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{
    //// 예제 1, res2 = res1 --> res2 = std::move(res1) 로 move semantic만들기
    //{
    //    AutoPtr<Resource> res1(new Resource(10000000));

    //    cout << res1.m_ptr << endl;

    //    //AutoPtr<Resource> res2 = res1;
    //    AutoPtr<Resource> res2 = std::move(res1);   // std::mover를 붙여서 r-value reference로 만든다. 즉 move semantic를 만든다

    //    cout << res1.m_ptr << endl;
    //    cout << res2.m_ptr << endl;
    //}

    //// 예제 2, 교수님께서 직접 구현한 swap
    //{
    //    AutoPtr<Resource> res1(new Resource(3));
    //    res1->setAll(3);

    //    AutoPtr<Resource> res2(new Resource(5));
    //    res2->setAll(5);

    //    res1->print();
    //    res2->print();

    //    MySwap(res1, res2);

    //    res1->print();
    //    res2->print();
    //}

    //// 예제3, 재밌는사례? move semantic사례, 알아서 구현이 되어있다. 
    //{
    //    vector<string> v;
    //    string str = "Hello";

    //    v.push_back(str);
    //    
    //    cout << str << endl;
    //    cout << v[0] << endl;

    //    v.push_back(std::move(str));

    //    cout << str << endl;
    //    cout << v[0] << " " << v[1] << endl;
    //}

    // 예제4
    {
        std::string x{ "abc" };
        std::string y{ "de" };

        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;

        MySwap(x, y);

        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
    }

    return 0;
}