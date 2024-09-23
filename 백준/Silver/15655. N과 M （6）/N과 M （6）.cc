#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> V;

void dfs(int start, vector<int>& v)
{
    if(v.size() == M)
    {
        for(int n : v) cout << n << " ";
        cout << '\n';

        return;
    }

    for(int i = start; i < N; ++i)
    {
        v.push_back(V[i]);
        dfs(i+1, v);
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
    //dfs(0, v);

    vector<int> mask(N, 1);
    for(int i = 0; i < M; ++i)
        mask[i] = 0;

    do
    {
        for(int i = 0; i < N; ++i)
        {
            if(!mask[i]) cout << V[i] << " ";
        } 
        cout << '\n';

    } while (next_permutation(mask.begin(), mask.end()));
    

    return 0;
}