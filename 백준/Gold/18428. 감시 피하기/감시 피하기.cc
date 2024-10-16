#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> Map;

vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};
bool check()
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(Map[i][j] == 'T')
            {
                for(int k = 0; k < 4; ++k)
                {   
                    int y = i + dy[k]; int x = j + dx[k];
                    bool flag = false;

                    while(y >= 0 && y < N && x >= 0 && x < N)
                    {
                        if(Map[y][x] == 'S')
                        {
                            flag = true;
                            break;
                        }
                        if(Map[y][x] == 'O')
                        {
                            break;
                        }

                        y += dy[k]; 
                        x += dx[k];
                    }
                    if(flag) return false;
                }
            }
        }
    }

    return true;
}

bool Flag = false;

void dfs(int cur, int dep)
{
    if(Flag) return;
    if(dep == 3)
    {   
        Flag = check();
        return;
    }

    for(int i = cur; i < N*N; ++i)
    {
        if(Map[i/N][i%N] == 'X')
        {
            Map[i/N][i%N] = 'O';
            dfs(i+1, dep+1);
            Map[i/N][i%N] = 'X';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    Map.resize(N, vector<char>(N));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> Map[i][j];

    dfs(0, 0);

    Flag ? cout << "YES" : cout << "NO";

    return 0;
}
