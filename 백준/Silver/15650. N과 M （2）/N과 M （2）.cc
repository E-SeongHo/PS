#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void dfs(int start, vector<int>& v)
{
    if(v.size() == M)
    {
        for(int n : v) cout << n << " ";
        cout << endl;

        return;
    }

    for(int i = start; i < N; ++i)
    {
        v.push_back(i+1);
        dfs(i+1, v);
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    vector<int> v;
    //dfs(0, v);

    vector<int> mask(N, 1);
    for(int i = 0; i < M; ++i)
        mask[i] = 0;

    do
    {
        for(int i = 0; i < N; ++i)
        {
            if(!mask[i]) cout << i+1 << " ";
        }
        cout << endl;

    } while (next_permutation(mask.begin(), mask.end()));
    

    return 0;
}