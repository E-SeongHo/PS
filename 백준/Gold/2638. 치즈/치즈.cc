#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> V;

vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    V.resize(N, vector<int>(M, 0));

    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> V[i][j];
            if(V[i][j]) cnt++;
        }
    }

    int time = 0;
    while(cnt)
    {
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while(!q.empty())
        {
            auto [y, x] = q.front(); q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny >= 0 && ny < N && nx >= 0 && nx < M)
                {
                    if(!visited[ny][nx] && !V[ny][nx])
                    {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                }
            }
        }

        vector<vector<int>> Copy(V);

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(Copy[i][j])
                {
                    int contact = 0;
                    for(int k = 0; k < 4; k++)
                    {
                        int y = i + dy[k];
                        int x = j + dx[k];

                        if(y >= 0 && y < N && x >= 0 && x < M)
                        {
                            if(!Copy[y][x] && visited[y][x]) contact++;
                            if(contact >= 2) 
                            {
                                V[i][j] = 0;
                                cnt--;
                                break;
                            }
                        }
                    }
                }
            }
        }

        time++;
        if(!cnt) break;
    }

    cout << time;

    return 0;
}