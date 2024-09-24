#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> V;

void dfs(vector<int>& v)
{
    if(v.size() == M)
    {
        for(int n : v) cout << n << " ";
        cout << '\n';

        return;
    }

    int prev = 0;
    for(int i = 0; i < N; ++i)
    {
        if(V[i] != prev)
        {
            prev = V[i];
            v.push_back(V[i]);
            dfs(v);
            v.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    V.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    vector<int> v;
    dfs(v);
    
    return 0;
}