#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<vector<int>> Map;
vector<vector<bool>> Visited;
vector<vector<int>> IsReachable;

vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};

int dfs(int curY, int curX)
{
    if(curY == M-1 && curX == N-1)
    {
        return 1;
    }

    if(Visited[curY][curX])
    {
        return IsReachable[curY][curX];
    }

    Visited[curY][curX] = true;

    for(int i = 0; i < 4; ++i)
    {
        int ny = curY + dy[i];
        int nx = curX + dx[i];

        if(ny >= 0 && ny < M && nx >= 0 && nx < N)
        {
            int curHeight = Map[curY][curX];
            int nextHeight = Map[ny][nx];

            if(curHeight <= nextHeight) continue;
            
            IsReachable[curY][curX] += dfs(ny, nx);
        }
    }
    
    return IsReachable[curY][curX];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N;
    Map.resize(M, vector<int>(N));
    Visited.resize(M, vector<bool>(N, false));
    IsReachable.resize(M, vector<int>(N, 0));

    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
            cin >> Map[i][j];

    cout << dfs(0, 0);

    // dfs -> optimize
    return 0;
}