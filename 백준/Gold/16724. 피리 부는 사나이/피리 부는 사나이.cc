#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> Map;

// U D L R
vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};

vector<vector<bool>> Discovered;
vector<vector<bool>> Visited;
int Cycles = 0;

void dfs(int y, int x)
{
    if(Discovered[y][x] && !Visited[y][x])
    {
        Cycles++;
        return;
    }

    Discovered[y][x] = true;
    
    int ny = y + dy[Map[y][x]];
    int nx = x + dx[Map[y][x]];
    if(!Visited[ny][nx])
    {
        dfs(ny, nx);
    }
    Visited[y][x] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    Map.resize(N, vector<int>(M));
    Visited.resize(N, vector<bool>(M, false));
    Discovered.resize(N, vector<bool>(M, false));

    for(int i = 0; i < N; ++i) 
    {
        for(int j = 0; j < M; ++j)
        {
            char dir;
            cin >> dir;
            vector<char> v = {'U', 'D', 'L', 'R'};
            
            for(int k = 0; k < 4; ++k)
                if(v[k] == dir) Map[i][j] = k;
        }
    }

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(!Visited[i][j]) dfs(i, j);
        }
    }

    cout << Cycles;
    return 0;
}