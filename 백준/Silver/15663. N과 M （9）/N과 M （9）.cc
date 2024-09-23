#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> V;

void dfs(vector<int>& v, vector<int>& issued)
{
    if(v.size() == M)
    {
        for(int n : v) cout << n << " ";
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; ++i)
    {
        if(!issued[i])
        {
            bool flag = false;
            for(int j = 0; j < i; ++j)
            {
                if(!issued[j] && V[j] == V[i])
                {
                    flag = true;
                    break;
                }
            }

            if(flag) continue;
            
            issued[i] = true;
            v.push_back(V[i]);

            dfs(v, issued);

            issued[i] = false;
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
    vector<int> issued(N+1);
    
    dfs(v, issued);

    return 0;
}