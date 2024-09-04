#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N, C, M;
vector<tuple<int, int, int>> V;

int find_available(vector<int>& v, int begin, int end)
{
    int ret = 99999;
    for(int i = begin; i <= end; ++i)
    {
        ret = min(ret, v[i]);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C >> M;
    V.resize(M);
    
    for(int i = 0; i < M; ++i)
    {
        int from, to, capacity;
        cin >> from >> to >> capacity;
        V[i] = {to, from, capacity};
    }

    sort(V.begin(), V.end());
    vector<int> availables(N+1, C);
    
    int ans = 0;
    for(auto[to, from, capacity] : V)
    {
        int max_load = find_available(availables, from, to-1);
        int load = capacity < max_load ? capacity : max_load;

        ans += load;
        for(int i = from; i < to; ++i)
        {
            availables[i] -= load;
        }
    }

    cout << ans;
    return 0;
}