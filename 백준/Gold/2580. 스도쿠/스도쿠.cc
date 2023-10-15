#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<vector<int>> board(9, vector<int>(9));
vector<pair<int, int>> blank;
bool findFlag = false;

bool IsAvailable(int y, int x, int value)
{
    // Check y
    for(int i = 0; i < 9; ++i)
        if(value == board[y][i]) return false;

    // Check x
    for(int i = 0; i < 9; ++i)
        if(value == board[i][x]) return false;

    // Check 3x3 Grid
    int sy = (y/3) * 3;
    int sx = (x/3) * 3;
    for(int j = sy; j < sy+3; ++j)
        for(int i = sx; i < sx+3; ++i)
            if(value == board[j][i]) return false;

    return true;
}

void DFS(int idx)
{
    if(idx == blank.size())
    {
        findFlag = true;
        return;
    }

    auto p = blank[idx];
    //cout << p.first << " " << p.second << endl;

    for(int n = 1; n < 10; ++n)
    {
        if(IsAvailable(p.first, p.second, n))
        {
            board[p.first][p.second] = n;
            DFS(idx + 1);
            if(findFlag) return;
            board[p.first][p.second] = 0;
        }
    }
}

int main()
{
    for(int j = 0; j < 9; ++j)
        for(int i = 0; i < 9; ++i)
        {
            cin >> board[j][i];
            if(!board[j][i]) blank.push_back({j, i});
        }

    DFS(0);

    cout << endl;
    for(int j = 0; j < 9; ++j)
    {
        for(int i = 0; i < 9; ++i)
            cout << board[j][i] << " ";
        cout << "\n";
    }

    return 0;
}