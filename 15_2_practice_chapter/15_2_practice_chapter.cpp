// move semantics를 사용할지 말지 혹은 사용할 수 있을지 사용하면 안될지를 판별할 수 있는
// R-value reference를 배운다.
#include <iostream>
using namespace std;

void doSomething(int& lref)
{
    // 들어오는 것들이 외부에서 메모리가 있고 다른 곳에서 사용 할 수 
    // 있는 것이기 때문에 move-semantics를 사용 할 수 없다.
    // 문법적으로 강제로 사용할 수 있긴한데 이건 고급 프로그래머가 특별하게
    // 코딩을 할 경우이므로 일단 일반적인 상황에서만 적용하는 것이다.
    cout << "L-value ref" << endl;
}

void doSomething(int&& ref)
{
    // 이 함수에서 가져온 값들은 R-value reference이기 때문에
    // 어짜피 어떤 곳에서도 쓰지 않을 값들이기 때문에
    // move-semantics를 써도 아무 상관이 없다는 의미이다~!
    cout << "R-value ref" << endl;
}

int getResult()
{
    return 100 * 100;
}

int main()
{
    int x = 5;  // x는 메모리공간이 있고 5는 사라질 메모리 공간
    int y = getResult();
    const int cx = 6;
    const int cy = getResult();

    // L-value references

    int& lr1 = x;           // Modifiable l-values
    //int& lr2 = cx;        // Non-modifiable l-value
    //int& lr3 = 5;         // R-values

    const int& lr4 = x;     // Modifiable l-values
    const int& lr5 = cx;    // Non-modifiable l-values
    const int& lr6 = 5;     // R-values

    // R-value references

    //int &&rr1 = x;    // Modifiable l-values
    //int &&rr2 = cx;   // Non-modifiable l-values
    int&& rr3 = 5;      // R-values, 사라질 운명인 5의 값을 보관해준다. 즉 사라질 놈들만 저장가능
    int&& rrr = getResult();    // 사라질 운명이 있는 값들은 보관해준다. 라는 것. 아무도 찾지 않는다.

    cout << rr3 << endl;
    rr3 = 10;
    cout << rr3 << endl;    // 나 아니면 접근 못해!! 

    //const int&& rr4 = x;      // Modifiable l-values
    //const int&& rr5 = cx;     // Non-modifiable l-values
    const int&& rr6 = 5;        // R-values

    // L/R-value reference parameters
    doSomething(x);
    //doSomething(cx);
    doSomething(5);
    doSomething(getResult());

    return 0;
}