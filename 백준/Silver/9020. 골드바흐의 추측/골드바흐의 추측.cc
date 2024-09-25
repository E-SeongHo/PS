#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<bool> IsPrime(10001, false);

bool is_prime(int n)
{
    if(n == 1) return true;
    if(IsPrime[n]) return true;
    
    for(int i = 2; i*i <= n; ++i)
    {
        if(n%i == 0) return false;
    }

    return true;
}

int main()
{
    for(int i = 1; i <= 10000; ++i)
    {
        if(is_prime(i)) 
        {
            IsPrime[i] = true;
            for(int j = 2; i*j <= 10000; ++j)
            {
                IsPrime[i*j] = false;
            }
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> N;

        int n = 1;
        for(int i = 1; i <= N/2; ++i)
        {
            if(IsPrime[i] && IsPrime[N-i])
                n = i;
        }

        cout << n << " " << N-n << '\n';
    }

    return 0;
}