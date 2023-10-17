#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> v(N+1);
    for(int i = 1; i < N+1; ++i)
    {
        cin >> v[i];
        v[i] += v[i-1];
    }

    int ret = -987654321;
    for(int i = 1; i <= N-K+1; ++i)
    {
        ret = max(ret, v[i+K-1] - v[i-1]);
    }

    cout << ret;
    return 0;
}
