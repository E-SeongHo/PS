#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, K;
vector<vector<int>> Map;

vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};

int search_area(vector<vector<bool>>& visited, int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    int cnt = 0;
    while(!q.empty())
    {
        auto [cy, cx] = q.front(); q.pop();
        cnt++;
        
        for(int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < M && nx >= 0 && nx < N)
            {
                if(!visited[ny][nx] && !Map[ny][nx])
                {
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N >> K;
    Map.resize(M, vector<int>(N, 0));

    for(int k = 0; k < K; ++k)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x2--; y2--;
        for(int y = y1; y <= y2; ++y)
        {
            for(int x = x1; x <= x2; ++x)
            {
                Map[y][x] = 1;
            }
        }
    }

    vector<vector<bool>> visited(M, vector<bool>(N, false));
    vector<int> areas;

    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(!visited[i][j] && !Map[i][j])
            {
                int area = search_area(visited, i, j);
                areas.push_back(area);
            }
        }
    }

    sort(areas.begin(), areas.end());
    
    cout << areas.size() << '\n';
    for(int area : areas)
        cout << area << " ";

    return 0;
}