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
    cin >> N >> M;
    V.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    vector<int> v;
    vector<int> issued(N, 0);
    //dfs(v, issued);

    do
    {
        for(int i = 0; i < M; ++i)
            cout << V[i] << " ";
        cout << '\n';
        
        reverse(V.begin()+M, V.end());

    } while (next_permutation(V.begin(), V.end()));
    

    return 0;
}