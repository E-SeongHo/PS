#include <iostream>
#include <vector>
#include <set>

using namespace std;

int R, C;
vector<vector<char>> board;
vector<bool> visited(26);
int count = 0;

vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};

void visit(int y, int x, int depth)
{
    count = max(depth, count);

    visited[board[y][x] - 'A'] = true;

    for(int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= R) continue;
        if(nx < 0 || nx >= C) continue;
        if(visited[board[ny][nx] - 'A']) continue;

        visit(ny, nx, depth+1);
        visited[board[ny][nx] - 'A'] = false;
    }
}

int main()
{
    cin >> R >> C;
    board.resize(R, vector<char>(C));
    
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            cin >> board[i][j];

    visit(0, 0, 1);

    cout << count;

    return 0;
}