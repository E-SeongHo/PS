#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<long long> v;
    v.resize(M);
    
    int sum = 0;
    for(int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        x %= M;
        sum += x;
        v[sum%M]++;
    }

    long long ret = 0;
    ret += v[0] * (v[0] + 1) * 0.5;
    for(int i = 1; i < M; ++i)
    {
        ret+= (v[i] * (v[i] + 1) * 0.5) - v[i];
    }

    cout << ret;

}