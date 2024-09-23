#include <iostream>
#include <vector>

using namespace std;

int N, M;

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
        v.push_back(i+1);
        dfs(v);
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    vector<int> v;
    dfs(v);

    return 0;
}