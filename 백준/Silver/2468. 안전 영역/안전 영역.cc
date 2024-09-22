#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> Area;

vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};

void visit_area(int y, int x, int h, vector<vector<bool>>& visited)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while(!q.empty())
    {
        auto [cy, cx] = q.front(); q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < N && nx >= 0 && nx < N)
            {
                if(Area[ny][nx] > h && !visited[ny][nx])
                {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
}

int count_area(int h)
{
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    int cnt = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(Area[i][j] > h && !visited[i][j])
            {
                visit_area(i, j, h, visited);
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    Area.resize(N, vector<int>(N));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> Area[i][j];

    int max_area = 0;
    for(int h = 0; h < 100; ++h)
    {
        max_area = max(max_area, count_area(h));
    }

    cout << max_area;

    return 0;
}