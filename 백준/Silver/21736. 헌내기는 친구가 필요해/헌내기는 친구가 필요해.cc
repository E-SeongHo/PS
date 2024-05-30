#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<char>> Campus;

vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    Campus.resize(N, vector<char>(M, 'O'));

    pair<int, int> start;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> Campus[i][j];
            if(Campus[i][j] == 'I') start = {i, j};
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    q.push(start);
    visited[start.first][start.second] = true;

    int cnt = 0;
    while(!q.empty())
    {
        auto p = q.front(); q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(nx >= 0 && nx < M && ny >= 0 && ny < N && Campus[ny][nx] != 'X')
            {
                if(!visited[ny][nx])
                {
                    if(Campus[ny][nx] == 'P') cnt++;
                    
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
    }

    cnt ? cout << cnt : cout << "TT";

    return 0;
}