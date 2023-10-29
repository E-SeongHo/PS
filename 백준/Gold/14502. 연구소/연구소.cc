#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<pair<int, int>> blanks;
vector<pair<int, int>> virus;

vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};

void DFS(int y, int x, vector<vector<int>>& lab)
{
    //cout << y << " " << x << endl;
    for(int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N) continue;
        if(nx < 0 || nx >= M) continue;

        if(lab[ny][nx] == 0)
        {
            lab[ny][nx] = 2;
            DFS(ny, nx, lab);
        }
    }
}
int main()
{
    cin >> N >> M;
    map.resize(N, vector<int>(M));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
            if(map[i][j] == 2)  virus.push_back({i, j});
            if(map[i][j] == 0)  blanks.push_back({i, j});
        }

    int ret = 0;
    for(int i = 0; i < blanks.size()-2; ++i)
    {
        for(int j = i+1; j < blanks.size()-1; ++j)
        {
            for(int k = j+1; k < blanks.size(); ++k)
            {
                vector<vector<int>> lab(map);
                lab[blanks[i].first][blanks[i].second] = 1;
                lab[blanks[j].first][blanks[j].second] = 1;
                lab[blanks[k].first][blanks[k].second] = 1;

                for(auto p : virus)
                {
                    DFS(p.first, p.second, lab);
                }
                
                int area = 0;
                for(int i = 0; i < N; ++i)
                    for(int j = 0; j < M; ++j)
                        if(lab[i][j] == 0)  area++;
                ret = max(ret, area);
            }
        }
    }
    cout << ret;
    
    return 0;
}