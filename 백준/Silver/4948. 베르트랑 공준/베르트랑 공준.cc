#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n)
{
    if(n == 1) return true;
    if(n == 2) return true;

    for(int i = 2; i*i <= n; ++i)
    {
        if(n%i == 0) return false;
    }

    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = -1;
    while(true)
    {
        cin >> n;
        if(n == 0) break;

        int cnt = 0;
        for(int i = n+1; i <= 2*n; ++i)
        {
            if(is_prime(i)) cnt++;
        }

        cout << cnt << '\n';
    }
    
    return 0;
}