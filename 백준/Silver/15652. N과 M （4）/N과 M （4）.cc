#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;

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
        v.push_back(i+1);
        dfs(i, v);
        v.pop_back();
    }
}
int main()
{
    cin >> N >> M;
    // cout << (pow(N, M) < 100000000);

    vector<int> v;
    dfs(0, v);

    return 0;
}