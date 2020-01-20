#include <iostream>
using namespace std;

int call(int n)
{
    if(n <= 1)
    {
        cout<<"Base : "<<n<<endl;
        return n + 1;
    }

    int cnt = 0;

    cout<<"Pre : "<<n<<endl;
    cnt += call(n-1);

    cout<<"In : "<<n<<endl;

    cnt += call(n-2);
    cout<<"Post : "<<n<<endl;

    return cnt + 3;

}

int main()
{
    cout<<call(5);
}