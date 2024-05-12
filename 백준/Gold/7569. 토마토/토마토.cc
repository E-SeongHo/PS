#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int M, N, H;
vector<vector<vector<int>>> boxes;
using coords = tuple<int, int, int>;
queue<coords> riped;

vector<int> dx = {-1, +1, 0, 0, 0, 0};
vector<int> dy = {0, 0, -1, +1, 0, 0};
vector<int> dz = {0, 0, 0, 0, -1, +1};

void bfs()
{
    while(!riped.empty())
    {
        auto [h, n, m] = riped.front(); riped.pop();
        int days = boxes[h][n][m];

        for(int i = 0; i < 6; i++)
        {
            coords coord = {h + dx[i], n + dy[i], m + dz[i]};
            auto [x, y, z] = coord;

            if(x >= 0 && x < H && y >= 0 && y < N && z >= 0 && z < M)
            {
                if(boxes[x][y][z] == -1) continue;
                if(boxes[x][y][z] >= 1 && boxes[x][y][z] <= days + 1) continue;
                
                boxes[x][y][z] = days + 1;
                riped.push({x, y, z});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> M >> N >> H;
    boxes.resize(H, vector<vector<int>>(N, vector<int>(M)));

    for(int h = 0; h < H; h++)
    {
        for(int n = 0; n < N; n++)
        {
            for(int m = 0; m < M; m++)
            {
                cin >> boxes[h][n][m];
                if(boxes[h][n][m] == 1) riped.push({h, n, m});
            }
        }
    }

    bfs();

    int ret = 0;

    for(int h = 0; h < H; h++)
    {
        for(int n = 0; n < N; n++)
        {
            for(int m = 0; m < M; m++)
            {
                if(boxes[h][n][m] == -1) continue;
                if(boxes[h][n][m] == 0) 
                {
                    cout << -1;
                    return 0;
                }
                ret = max(ret, boxes[h][n][m]);
            }
        }
    }

    cout << ret - 1;

    return 0;
}