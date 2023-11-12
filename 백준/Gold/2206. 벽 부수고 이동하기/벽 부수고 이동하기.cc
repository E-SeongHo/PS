#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};

vector<vector<char>> map;

vector<pair<int, int>> walls;
int N, M;
vector<vector<int>> visited;
vector<vector<int>> crashVisited;

struct status
{
    int y;
    int x;
    int depth;
    bool crashed = false;
};

int BFS()
{
    queue<status> q;
    q.push({0, 0, 1, false});
    visited[0][0] = 1;

    while(!q.empty())
    {
        auto p = q.front(); 
        q.pop();

        int y = p.y;
        int x = p.x;
        int depth = p.depth;
        bool crashed = p.crashed;

        if(y == N-1 && x == M-1)
            return depth;

        for(int i = 0; i < 4; ++i)
        {
            int ny, nx;
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny >= 0 && ny < N && nx >= 0 && nx < M)
            {
                if(crashed)
                {
                    if(map[ny][nx] == '1') continue;
                    else
                    {
                        if(!crashVisited[ny][nx] || depth+1 < crashVisited[ny][nx] ) 
                        {
                            q.push({ny, nx, depth+1, crashed});
                            crashVisited[ny][nx] = depth+1;
                        }
                    }
                }
                else
                {
                    if(map[ny][nx] == '0')
                    {
                        if(!visited[ny][nx] || depth+1 < visited[ny][nx])
                        {
                            q.push({ny, nx, depth+1, crashed});
                            visited[ny][nx] = depth+1;
                        }
                    }
                    else
                    {
                        if(!crashVisited[ny][nx] || depth+1 < crashVisited[ny][nx] ) 
                        {
                            q.push({ny, nx, depth+1, !crashed});
                            crashVisited[ny][nx] = depth+1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}


int main()
{
    cin >> N >> M;
    map.resize(N, vector<char>(M));
    visited.resize(N, vector<int>(M));
    crashVisited.resize(N, vector<int>(M));

    for(int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        for(int j = 0; j < M; ++j)
        {
            map[i][j] = s[j];
            if(map[i][j] == '1') walls.push_back({i, j});
        }
    }

    int ret = BFS();
    cout << ret;

    return 0;
}
