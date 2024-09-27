#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> Map;
vector<int> ans(3, 0);

int dfs(int y, int x, int n)
{
    if(n == 1)
    {
        if(Map[y][x] == -1) ++ans[0];
        if(Map[y][x] == 0) ++ans[1];
        if(Map[y][x] == 1) ++ans[2];
        return Map[y][x];
    }

    vector<int> rets(9);
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            rets[i*3 + j] = dfs(y+(n/3)*i, x+(n/3)*j, n/3);
        }
    }

    bool flag = equal(rets.begin()+1, rets.end(), rets.begin()) && rets[0] != 99;
    if(flag)
    {
        if(Map[y][x] == -1) ans[0]-=8;
        if(Map[y][x] == 0) ans[1]-=8;
        if(Map[y][x] == 1) ans[2]-=8;
        return Map[y][x];
    }
    else
    {
        return 99;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    Map.resize(N, vector<int>(N));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> Map[i][j];

    dfs(0, 0, N);

    cout << ans[0] << '\n';
    cout << ans[1] << '\n';
    cout << ans[2] << '\n';

    return 0;
}