#include <iostream>
#include <vector>

using namespace std;

vector<bool> is_primes;
int M, N;

bool is_prime(int n)
{
    if(n == 1) return false;
    if(n == 2) return true;

    if(!is_primes[n]) return false;

    bool ret = true;
    for(int i = 2; i*i <= n; ++i)
    {
        if(n % i == 0) 
        {
            ret = false;
            break;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N;
    is_primes.resize(N+1, true);

    for(int i = M; i < N+1; ++i)
    {
        if(is_prime(i)) cout << i << '\n';

        if(i != 1)
        {
            for(int j = 2; i*j <= N; ++j)
                is_primes[i*j] = false;
        }
    }

    return 0;
}