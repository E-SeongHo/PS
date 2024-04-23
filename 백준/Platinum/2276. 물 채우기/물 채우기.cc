
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pos = pair<int, pair<int, int>>;

int N, M;
vector<vector<int>> Board;
vector<vector<bool>> Visited;
priority_queue<pos, vector<pos>, greater<pos>> PQ;

vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};

int Accumulate = 0;

void fallThrough(int y, int x, int height)
{
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny > N-1 || nx < 0 || nx > M-1) continue;
        if(Visited[ny][nx]) continue;

        Visited[ny][nx] = true;
        if(Board[ny][nx] < height) 
        {
            Accumulate += height - Board[ny][nx];
            Board[ny][nx] = height;
            fallThrough(ny, nx, height);
        }
        else
        {
            PQ.push({Board[ny][nx], {ny, nx}});
        } 
    }
}

int main()
{
    cin >> M >> N;
    Board.resize(N, vector<int>(M));
    Visited.resize(N, vector<bool>(M));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> Board[i][j];
            if(i == 0 || j == 0 || i == N-1 || j == M-1) 
                PQ.push({Board[i][j], {i, j}});
        }
    }

    while(!PQ.empty())
    {
        auto p = PQ.top(); PQ.pop();
        int height = p.first;
        pair<int, int> pos = p.second;
        Visited[pos.first][pos.second] = true;

        fallThrough(pos.first, pos.second, height);
    }   
    
    cout << Accumulate;

    return 0;
}