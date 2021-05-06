#include "Timer.h"
#include "AutoPtr.h"
#include "Resource.h"

AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(10000000));
    std::cout << "�����Ҵ� ��" << std::endl;
    return res;
}

int main()
{
    using namespace std;
    streambuf* orig_buf = cout.rdbuf();
    //cout.rdbuf(NULL); //disconnect cout from buffer

    Timer timer;

    {
        AutoPtr<Resource> main_res;
        cout << " ���� of main_res" << endl;
        main_res = generateResource();
    }

    cout.rdbuf(orig_buf);
    timer.elapsed();
    //std::cout << timer.elapsed() << std::endl;

    return 0;
 }