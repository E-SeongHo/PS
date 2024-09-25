#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int W, H;
vector<vector<bool>> Map;

vector<int> dx = {-1, +1, 0, 0, -1, +1, -1, +1};
vector<int> dy = {0, 0, -1, +1, -1, +1, +1, -1};

int count_land()
{
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int cnt = 0;
    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            if(Map[i][j] && !visited[i][j])
            {
                queue<pair<int, int>> q;
                visited[i][j] = true;
                q.push({i, j});

                while(!q.empty())
                {
                    auto [y, x] = q.front(); q.pop();

                    for(int i = 0; i < 8; ++i)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        if(ny >= 0 && ny < H && nx >= 0 && nx < W)
                        {
                            if(!visited[ny][nx] && Map[ny][nx])
                            {
                                visited[ny][nx] = true;
                                q.push({ny, nx});
                            }
                        }
                    }
                }

                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(true)
    {
        cin >> W >> H;
        if(!W && !H) break;

        Map.resize(H, vector<bool>(W, false));

        for(int i = 0; i < H; ++i)
        {
            for(int j = 0; j < W; ++j)
            {
                int a;
                cin >> a;
                Map[i][j] = a;
            }
        }

        cout << count_land() << '\n';
    }  
    return 0;
}