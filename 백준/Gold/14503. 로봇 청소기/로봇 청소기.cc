#include <iostream>
#include <vector>

using namespace std;

int N, M;
int R, C, D;
vector<vector<int>> Map;

// d = 0, 1, 2, 3
vector<int> dx = {0, +1, 0, -1};
vector<int> dy = {-1, 0, +1, 0};

#define WALL 1
#define CLEAN 2

bool can_clean_nearby()
{
    for(int i = 0; i < 4; ++i)
    {
        int ny = R + dy[i];
        int nx = C + dx[i];

        if(ny >= 0 && ny < N && nx >= 0 && nx < M)
        {
            if(Map[ny][nx] != CLEAN && Map[ny][nx] != WALL) return true;
        }
    }

    return false;
}

bool go_reverse()
{
    int ny = R - dy[D];
    int nx = C - dx[D];

    if(ny >= 0 && ny < N && nx >= 0 && nx < M)
    {
        if(Map[ny][nx] != WALL)
        {
            R = ny;
            C = nx;
            return true;
        }
    }

    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> R >> C >> D;
    Map.resize(N, vector<int>(M));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> Map[i][j];

    int cnt = 0;
    while(true)
    {
        if(Map[R][C] != CLEAN) 
        {
            Map[R][C] = Map[R][C] = CLEAN;
            cnt++;
        }

        if(can_clean_nearby())
        {
            D--;
            if(D < 0) D = 3;

            int ny = R + dy[D];
            int nx = C + dx[D];

            if(ny >= 0 && ny < N && nx >= 0 && nx < M)
            {
                if(Map[ny][nx] != CLEAN && Map[ny][nx] != WALL)
                {
                    R = ny;
                    C = nx;
                }
            }
        }
        else
        {
            if(!go_reverse()) break;
        }
    }

    cout << cnt;
    return 0;
}