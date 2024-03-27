
#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
vector<vector<int>> room;
pair<int, int> upperAC;
pair<int, int> lowerAC;

vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};

void advection()
{
    vector<vector<int>> roomCopy(room);

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(roomCopy[i][j])
            {
                if(roomCopy[i][j] == -1) continue;
                
                int y = i;
                int x = j;
                int amount = roomCopy[i][j] / 5;
                
                for(int d = 0; d < 4; d++)
                {
                    int ny = y + dy[d];
                    int nx = x + dx[d];

                    if(ny >= 0 && ny < R && nx >= 0 && nx < C && room[ny][nx] != -1)
                    {
                        room[ny][nx] += amount;
                        room[y][x] -= amount;
                    }
                }
            }
        }
    }
}

void ac_task()
{
    // upper
    int y = upperAC.first;

    for(int i = y-1; i > 0; i--)
        room[i][0] = room[i-1][0];
    for(int j = 0; j < C-1; j++)
        room[0][j] = room[0][j+1];
    for(int i = 0; i < y; i++)
        room[i][C-1] = room[i+1][C-1];
    for(int j = C-1; j > 1; j--)
        room[y][j] = room[y][j-1];
    room[y][1] = 0;

    // lower
    y = lowerAC.first;

    for(int i = y+1; i < R-1; i++)
        room[i][0] = room[i+1][0];
    for(int j = 0; j < C-1; j++)
        room[R-1][j] = room[R-1][j+1];
    for(int i = R-1; i > y; i--)
        room[i][C-1] = room[i-1][C-1];
    for(int j = C-1; j > 1; j--)
        room[y][j] = room[y][j-1];
    room[y][1] = 0;
}

int main()
{
    cin >> R >> C >> T;

    room = vector<vector<int>>(R, vector<int>(C));
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
            cin >> room[r][c];
    }

    for(int r = 0; r < R; r++)
    {
        if(room[r][0] == -1) 
        {
            upperAC = {r, 0};
            lowerAC = {r+1, 0};
            break;
        } 
    }

    for(int t = 0; t < T; t++)
    {
        advection();
        ac_task();
    }
    
    int ret = 0;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
            ret+=room[i][j];
    }

    cout << ret+2; 

    return 0;
}