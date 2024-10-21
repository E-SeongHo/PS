#include <iostream>
#include <vector>

using namespace std;
int N;
vector<vector<int>> Map; 

vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};

void move(vector<vector<int>>& map, int dir)
{
    vector<vector<bool>> combined(N, vector<bool>(N, false));

    int line, dl;
    if(dir % 2 == 0) 
    {
        line = 0; dl = +1;
    }
    else 
    {
        line = N-1; dl = -1;
    }

    while(line >= 0 && line <= N-1)
    {
        for(int j = 0; j < N; ++j)
        {
            if(dx[dir] == 0) // j = x
            {
                int cur = line;
                int next = line - dl;

                if(!map[cur][j]) continue;

                while(next >= 0 && next <= N-1)
                {
                    if(!map[next][j])
                    {
                        map[next][j] = map[cur][j];
                        map[cur][j] = 0;
                        cur = cur - dl;
                        next = next - dl;
                    }
                    else
                    {
                        if(map[next][j] == map[cur][j] && !combined[next][j])
                        {
                            map[next][j] += map[cur][j];
                            map[cur][j] = 0;
                            combined[next][j] = true;
                        }
                        break;
                    }
                }
            }
            else
            {
                int cur = line;
                int next = line - dl;

                if(!map[j][cur]) continue;

                while(next >= 0 && next <= N-1)
                {
                    if(!map[j][next])
                    {
                        map[j][next] = map[j][cur];
                        map[j][cur] = 0;
                        cur = cur - dl;
                        next = next - dl;
                    }
                    else
                    {
                        if(map[j][next] == map[j][cur] && !combined[j][next])
                        {
                            map[j][next] += map[j][cur];
                            map[j][cur] = 0;
                            combined[j][next] = true;
                        }
                        break;
                    }
                }
            }
        }

        line = line + dl;
    }
}

int Ans = 0;

void dfs(vector<vector<int>>& map, int dep)
{
    if(dep == 5)
    {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                Ans = max(Ans, map[i][j]);

        return;
    }

    for(int i = 0; i < 4; ++i)
    {
        vector<vector<int>> moved_map = map;
        move(moved_map, i);
        dfs(moved_map, dep+1);
    }
}

int main()
{
    cin >> N;
    Map.resize(N, vector<int>(N));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> Map[i][j];

    dfs(Map, 0);

    cout << Ans;

    return 0;
}