#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Fib;

int main()
{
    cin >> N;
    int n = abs(N);
    Fib.resize(n+1);
    Fib[0] = 0;
    Fib[1] = 1;

    for(int i = 2; i < n+1; ++i)
    {
        Fib[i] = (Fib[i-1] + Fib[i-2]) % 1000000000;
    }

    if(N > 0)
    {
        cout << 1 << '\n';
    }
    else if(N == 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        if(n%2 == 0) cout << -1 << '\n';
        else cout << 1 << '\n';
    }

    cout << Fib[n];


    return 0;
}