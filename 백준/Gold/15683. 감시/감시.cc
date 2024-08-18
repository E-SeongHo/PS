#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

#define WALL 6
#define SIGHT 10

using tup = tuple<int, int, int>;

vector<tup> CC;
vector<vector<int>> Lab;
int N, M;

void mark(vector<vector<int>>& CurLab, int y, int x, bool right, bool left, bool up, bool down)
{
    CurLab[y][x] = CurLab[y][x] >= SIGHT ? CurLab[y][x] + 1 : SIGHT;

    if(right)
    {
        int cx = x+1;
        while(cx < M && CurLab[y][cx] != WALL)
        {
            CurLab[y][cx] = CurLab[y][cx] >= SIGHT ? CurLab[y][cx] + 1 : SIGHT;
            cx++;
        }
    }

    if(left)
    {
        int cx = x-1;
        while(cx >= 0 && CurLab[y][cx] != WALL)
        {
            CurLab[y][cx] = CurLab[y][cx] >= SIGHT ? CurLab[y][cx] + 1 : SIGHT;
            cx--;
        }
    }

    if(up)
    {
        int cy = y+1;
        while(cy < N && CurLab[cy][x] != WALL)
        {
            CurLab[cy][x] = CurLab[cy][x] >= SIGHT ? CurLab[cy][x] + 1 : SIGHT;
            cy++;
        }
    }

    if(down)
    {
        int cy = y-1;
        while(cy >= 0 && CurLab[cy][x] != WALL)
        {
            CurLab[cy][x] = CurLab[cy][x] >= SIGHT ? CurLab[cy][x] + 1 : SIGHT;
            cy--;
        }
    }
}

void erase(vector<vector<int>>& CurLab, int y, int x, bool right, bool left, bool up, bool down)
{
    CurLab[y][x] = CurLab[y][x] == SIGHT ? 0 : CurLab[y][x] - 1;

    if(right)
    {
        int cx = x+1;
        while(cx < M && CurLab[y][cx] != WALL)
        {
            CurLab[y][cx] = CurLab[y][cx] == SIGHT ? 0 : CurLab[y][cx] - 1;
            cx++;
        }
    }

    if(left)
    {
        int cx = x-1;
        while(cx >= 0 && CurLab[y][cx] != WALL)
        {
            CurLab[y][cx] = CurLab[y][cx] == SIGHT ? 0 : CurLab[y][cx] - 1;
            cx--;
        }
    }

    if(up)
    {
        int cy = y+1;
        while(cy < N && CurLab[cy][x] != WALL)
        {
            CurLab[cy][x] = CurLab[cy][x] == SIGHT ? 0 : CurLab[cy][x] - 1;
            cy++;
        }
    }

    if(down)
    {
        int cy = y-1;
        while(cy >= 0 && CurLab[cy][x] != WALL)
        {
            CurLab[cy][x] = CurLab[cy][x] == SIGHT ? 0 : CurLab[cy][x] - 1;
            cy--;
        }
    }
}

int MinBlinds = 99999999;
int Walls = 0;


void dfs(int depth, vector<vector<int>>& CurLab)
{
    if(depth == CC.size())
    {
        int cnt = 0;
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                if(CurLab[i][j]) cnt++;
            }
        }
        MinBlinds = min(MinBlinds, N*M - cnt);
        return;
    }

    auto [num, y, x] = CC[depth];

    switch(num)
    {
    case 1:
        mark(CurLab, y, x, true, false, false, false);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, true, false, false, false);

        mark(CurLab, y, x, false, true, false, false);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, false, true, false, false);

        mark(CurLab, y, x, false, false, true, false);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, false, false, true, false);

        mark(CurLab, y, x, false, false, false, true);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, false, false, false, true);
        break;
    case 2:
        mark(CurLab, y, x, true, true, false, false);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, true, true, false, false);

        mark(CurLab, y, x, false, false, true, true);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, false, false, true, true);
        break;
    case 3:
        mark(CurLab, y, x, true, false, true, false);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, true, false, true, false);

        mark(CurLab, y, x, false, true, true, false);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, false, true, true, false);

        mark(CurLab, y, x, false, true, false, true);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, false, true, false, true);

        mark(CurLab, y, x, true, false, false, true);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, true, false, false, true);
        break;
    case 4:
        mark(CurLab, y, x, true, true, true, false);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, true, true, true, false);

        mark(CurLab, y, x, false, true, true, true);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, false, true, true, true);

        mark(CurLab, y, x, true, true, false, true);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, true, true, false, true);

        mark(CurLab, y, x, true, false, true, true);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, true, false, true, true);
        break;
    case 5:
        mark(CurLab, y, x, true, true, true, true);
        dfs(depth+1, CurLab);
        erase(CurLab, y, x, true, true, true, true);
        break;
    default:
        cout << "error" << endl;
    }
}

int main()
{
    cin >> N >> M;
    Lab.resize(N, vector<int>(M));

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> Lab[i][j];
            if(Lab[i][j] && Lab[i][j] != WALL)
            {
                CC.push_back({Lab[i][j], i, j});
            }
            if(Lab[i][j] == WALL)
            {
                Walls++;
            }
        }
    }

    dfs(0, Lab);

    cout << MinBlinds;

    return 0;
}