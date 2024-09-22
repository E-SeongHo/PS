#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> V;

void dfs(vector<bool>& issued, vector<int>& v)
{
    if(v.size() == M)
    {
        for(int n : v) cout << n << " ";
        cout << '\n';
        return;
    }
    
    for(int i = 1; i < N+1; ++i)
    {
        if(!issued[i])
        {
            v.push_back(i);
            issued[i] = true;
            dfs(issued, v);
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

    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        v[i] = i+1;

    do
    {
        for(int i = 0; i < M; ++i) 
            cout << v[i] << " ";
        cout << '\n';

        reverse(v.begin() + M, v.end());
        
    } while (next_permutation(v.begin(), v.end()));
    
    
    
    return 0;
}