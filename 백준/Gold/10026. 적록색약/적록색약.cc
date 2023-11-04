#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<char>> board;
vector<vector<bool>> visited;

bool CheckBound(int y, int x)
{
    if(y >= N || y < 0) return false;
    if(x >= N || x < 0) return false;
    if(visited[y][x]) return false;
    return true;
}

void DFS(int y, int x, const char color, const bool isWeak)
{
    visited[y][x] = true;

    if(isWeak && (color == 'R' || color == 'G'))
    {
        //cout << y << " " << x << "search" << endl;
        if(CheckBound(y+1, x) && (board[y+1][x] == 'R' || board[y+1][x] == 'G'))
            DFS(y+1, x, color, isWeak);
        if(CheckBound(y-1, x) && (board[y-1][x] == 'R' || board[y-1][x] == 'G'))
            DFS(y-1, x, color, isWeak);
        if(CheckBound(y, x+1) && (board[y][x+1] == 'R' || board[y][x+1] == 'G'))
            DFS(y, x+1, color, isWeak);
        if(CheckBound(y, x-1) && (board[y][x-1] == 'R' || board[y][x-1] == 'G'))
            DFS(y, x-1, color, isWeak);
    }
    else
    {
        if(CheckBound(y+1, x) && board[y+1][x] == color)
            DFS(y+1, x, color, isWeak);
        if(CheckBound(y-1, x) && board[y-1][x] == color)
            DFS(y-1, x, color, isWeak);
        if(CheckBound(y, x+1) && board[y][x+1] == color)
            DFS(y, x+1, color, isWeak);
        if(CheckBound(y, x-1) && board[y][x-1] == color)
            DFS(y, x-1, color, isWeak);
    }

    
}

int main()
{
    cin >> N;
    board.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> board[i][j];

    int weak = 0;
    int normal = 0;

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(visited[i][j]) continue;

            normal++;
            DFS(i, j, board[i][j], false);
        }
    }

    fill(visited.begin(), visited.end(), vector<bool>(N, false));

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(visited[i][j]) continue;

            weak++;
            DFS(i, j, board[i][j], true);
        }
    }
    cout << normal << " " << weak;

    return 0;
}