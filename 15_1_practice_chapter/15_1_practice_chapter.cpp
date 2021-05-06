#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

// RAII : resource acquisition is initalization
// RAII는 동적할당을 한 곳에서 delete를 해줘야한다는 의미

//void doSomething()
//{
//    try
//    {
//        //Resource* res = new Resource;   // dull pointer
//
//        //AutoPtr<Resource> res = new Resource;
//        //AutoPtr<Resource> res{ new Resource };  // smart pointer
//        AutoPtr<Resource> res( new Resource );
//        // 위에 어떻게 되는건지 정확히 모르겠네.
//        return;
//
//        // work with res
//        if (true)
//        {
//            //delete res;   // 전통적인 해결방법
//            //return;   // early return(delete를 사용 안하고 리턴)
//            throw - 1;  // exception
//        }
//
//        //delete res;
//    }
//    catch (...)
//    {
//
//    }
//
//
//    return;
//}

int main()
{
    //doSomething();

    {
        AutoPtr<Resource> res1(new Resource);   // int i; int *ptr1(&i); int *ptr2 = nullptr;
        AutoPtr<Resource> res2;

        // doSomething(res1); 을 쓴다고치면
        // res1이 함수내에 move semantics가 되고 동적할당이 안에서 delete되면서 문제가됨
        // 스마트포인터인 AutoPtr이 이래서 문제가되기 때문에 삭제됨.


        cout << std::boolalpha;

        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;


        res2 = res1;    // move semantics

        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
    }



    //// syntax vs. semantics
    //int x = 1, y = 1; 
    //x + y;     

    //string str1("Hello"), str2("World");
    //str1 + str2;    // append
    //// 숫자끼리 더하는건 그런데 문자끼리 더하는건? append한다는 것인데
    //// + 의 기호는 같으나 의미가 다른데 이런걸 semantics라고 불리운다.
    //// 프로그래밍 언어 과목을 배울 떄 semantics를 자세히 배운다.

    //doSomething(res1);  // 이렇게 넣는게 semantics로 생각하면 아예 다르다.
    //// value semantics (copy semantics)
    //// reference semantics (pointer)
    //// move semantics (move)
    //// 위에서 res2 = res1; 이 copy semantics가 아닌 move semantics다!!


    return 0;
}