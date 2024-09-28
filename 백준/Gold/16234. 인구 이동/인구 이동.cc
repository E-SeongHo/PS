#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
vector<vector<int>> Map;

vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};

bool transfer(int y, int x, vector<vector<bool>>& visited)
{
    bool ret = false;

    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    vector<pair<int, int>> v;
    int sum = 0;

    while(!q.empty())
    {
        auto [cy, cx] = q.front(); q.pop();
        sum += Map[cy][cx];
        v.push_back({cy, cx});

        for(int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < N && nx >= 0 && nx < N && !visited[ny][nx])
            {
                int gap = abs(Map[cy][cx] - Map[ny][nx]);
                if(L <= gap && gap <= R)
                {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    ret = true;
                }
            }
        }
    }

    for(auto [cy, cx] : v)
    {
        Map[cy][cx] = sum / (int)v.size();
    }

    return ret;
}   

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> L >> R;
    Map.resize(N, vector<int>(N));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> Map[i][j];

    int time = 0;
    while(true)
    {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        bool flag = false;
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(!visited[i][j])
                {
                    bool ret = transfer(i, j, visited);
                    if(ret) flag = true;
                }
            }
        }

        if(!flag) break;
        time++;
    }

    cout << time;

    return 0;
}