#include <iostream>
#include <vector>

using namespace std;

vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};

void search(vector<vector<int>>& map, vector<vector<bool>>& check, int yBound, int xBound, int y, int x)
{
    check[y][x] = true;
    for(int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < yBound && nx >= 0 && nx < xBound)
        {
            if(!check[ny][nx] && map[ny][nx] == 1) search(map, check, yBound, xBound, ny, nx);
        }
    }
}

int main()
{
    int T, M, N, K;
    cin >> T;

    vector<int> ans(T);
    for(int i = 0; i < T; ++i)
    {
        cin >> M >> N >> K;
        vector<vector<int>> map(N, vector<int>(M));
        vector<vector<bool>> visited(N, vector<bool>(M));

        for(int j = 0; j < K; ++j)
        {   
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        int cnt = 0;
        for(int y = 0; y < N; ++y)
        {
            for(int x = 0; x < M; ++x)
            {
                if(!visited[y][x] && map[y][x] == 1)
                {
                    search(map, visited, N, M, y, x);
                    cnt++;
                }
            }
        }
        ans[i] = cnt;
    }

    for(auto n : ans)
        cout << n << "\n";
    return 0;
}