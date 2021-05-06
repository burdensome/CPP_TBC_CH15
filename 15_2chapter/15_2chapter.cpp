// move semantics�� ������� ���� Ȥ�� ����� �� ������ ����ϸ� �ȵ����� �Ǻ��� �� �ִ�
// R-value reference�� ����.
#include <iostream>
using namespace std;

void doSomething(int& lref)
{
    // ������ �͵��� �ܺο��� �޸𸮰� �ְ� �ٸ� ������ ��� �� �� 
    // �ִ� ���̱� ������ move-semantics�� ��� �� �� ����.
    // ���������� ������ ����� �� �ֱ��ѵ� �̰� ��� ���α׷��Ӱ� Ư���ϰ�
    // �ڵ��� �� ����̹Ƿ� �ϴ� �Ϲ����� ��Ȳ������ �����ϴ� ���̴�.
    cout << "L-value ref" << endl;
}

void doSomething(int&& ref)
{
    // �� �Լ����� ������ ������ R-value reference�̱� ������
    // ��¥�� � �������� ���� ���� �����̱� ������
    // move-semantics�� �ᵵ �ƹ� ����� ���ٴ� �ǹ��̴�~!
    cout << "R-value ref" << endl;
}

int getResult()
{
    return 100 * 100;
}

int main()
{
    int x = 5;  // x�� �޸𸮰����� �ְ� 5�� ����� �޸� ����
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
    int&& rr3 = 5;      // R-values, ����� ����� 5�� ���� �������ش�. �� ����� ��鸸 ���尡��
    int&& rrr = getResult();    // ����� ����� �ִ� ������ �������ش�. ��� ��. �ƹ��� ã�� �ʴ´�.

    cout << rr3 << endl;
    rr3 = 10;
    cout << rr3 << endl;    // �� �ƴϸ� ���� ����!! 

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