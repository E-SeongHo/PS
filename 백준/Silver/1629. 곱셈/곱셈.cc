#include <iostream>
#include <vector>

using namespace std;

long long A, B, C;

long long Func(int e)
{   
    if (e == 1) return A % C;

    long long ret = Func(e / 2);
    if(e % 2 == 0)
        return (ret * ret) % C;
    else 
        return (((ret * ret) % C) * Func(1)) % C;
}

int main()
{
    cin >> A >> B >> C;

    cout << Func(B);
    return 0;
}
