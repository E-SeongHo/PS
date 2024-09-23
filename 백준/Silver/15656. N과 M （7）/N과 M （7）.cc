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

    for(int i = 0; i < N; ++i)
    {
        v.push_back(V[i]);
        dfs(v);
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    V.resize(N);
    
    for(int i = 0; i < N; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    vector<int> v;
    dfs(v);

    return 0;
}