#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> visited;

vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};

void BFS(pair<int, int>& start)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 0;

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i)
        {
            int y = p.first + dy[i];
            int x = p.second + dx[i];

            if(y >= N || y < 0 || x >= M || x < 0) continue;
            if(y == start.first && x == start.second) continue;
            if(map[y][x] == 0) continue;
            if(visited[y][x]) continue;

            q.push({y, x});
            visited[y][x] = visited[p.first][p.second] + 1;
        }
    }
}

int main()
{
    cin >> N >> M;
    map.resize(N, vector<int>(M));
    visited.resize(N, vector<int>(M));

    pair<int, int> start;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
            if(map[i][j] == 2) start = make_pair(i, j);
        }
    }

    BFS(start);
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(!visited[i][j] && map[i][j] == 1) cout << -1 << " ";
            else if(!map[i][j]) cout << 0 << " ";
            else cout << visited[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}