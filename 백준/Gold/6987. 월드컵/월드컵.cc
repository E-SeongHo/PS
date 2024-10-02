#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using tup = tuple<int, int, int>;

vector<pair<int, int>> MatchUps;

vector<vector<tup>> Examples(4);
vector<bool> Ans(4, false);
vector<tup> Results(6);

#define WIN 0
#define DRAW 1
#define LOSE 2

void dfs(int cur)
{
    if(cur == MatchUps.size())
    {
        for(int i = 0; i < 4; ++i)
        {
            if(Results == Examples[i])
            {
                Ans[i] = true;
            }
        }
        return;
    }

    auto [a, b] = MatchUps[cur];

    auto& [a_win, a_draw, a_lose] = Results[a];
    auto& [b_win, b_draw, b_lose] = Results[b];

    // a wins
    a_win++; b_lose++;
    dfs(cur+1);
    a_win--; b_lose--;

    // b wins
    b_win++; a_lose++;
    dfs(cur+1);
    b_win--; a_lose--;

    // draw
    a_draw++; b_draw++;
    dfs(cur+1);
    a_draw--; b_draw--;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for(int i = 0; i < 6; ++i)
        for(int j = i+1; j < 6; ++j)
            MatchUps.push_back({i, j});

    for(int i = 0; i < 4; ++i)
    {
        int win, draw, lose;
        Examples[i].resize(6);
        for(int j = 0; j < 6; ++j)
        {
            cin >> win >> draw >> lose;
            Examples[i][j] = {win, draw, lose};
        }
    }

    dfs(0);

    for(bool ans : Ans)
    {
        cout << ans << " ";
    }

    return 0;
}