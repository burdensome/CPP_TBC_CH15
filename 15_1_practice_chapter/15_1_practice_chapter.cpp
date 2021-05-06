#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

// RAII : resource acquisition is initalization
// RAII�� �����Ҵ��� �� ������ delete�� ������Ѵٴ� �ǹ�

//void doSomething()
//{
//    try
//    {
//        //Resource* res = new Resource;   // dull pointer
//
//        //AutoPtr<Resource> res = new Resource;
//        //AutoPtr<Resource> res{ new Resource };  // smart pointer
//        AutoPtr<Resource> res( new Resource );
//        // ���� ��� �Ǵ°��� ��Ȯ�� �𸣰ڳ�.
//        return;
//
//        // work with res
//        if (true)
//        {
//            //delete res;   // �������� �ذ���
//            //return;   // early return(delete�� ��� ���ϰ� ����)
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

        // doSomething(res1); �� ���ٰ�ġ��
        // res1�� �Լ����� move semantics�� �ǰ� �����Ҵ��� �ȿ��� delete�Ǹ鼭 ��������
        // ����Ʈ�������� AutoPtr�� �̷��� �������Ǳ� ������ ������.


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
    //// ���ڳ��� ���ϴ°� �׷��� ���ڳ��� ���ϴ°�? append�Ѵٴ� ���ε�
    //// + �� ��ȣ�� ������ �ǹ̰� �ٸ��� �̷��� semantics��� �Ҹ����.
    //// ���α׷��� ��� ������ ��� �� semantics�� �ڼ��� ����.

    //doSomething(res1);  // �̷��� �ִ°� semantics�� �����ϸ� �ƿ� �ٸ���.
    //// value semantics (copy semantics)
    //// reference semantics (pointer)
    //// move semantics (move)
    //// ������ res2 = res1; �� copy semantics�� �ƴ� move semantics��!!


    return 0;
}