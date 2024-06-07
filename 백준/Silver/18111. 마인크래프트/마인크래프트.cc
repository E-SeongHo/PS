#include <iostream>
#include <vector>

using namespace std;

int N, M, B, H;
vector<vector<int>> SandBox;


int make_sandbox(int target_height)
{
    int blocks = B;

    int time = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int diff = SandBox[i][j] - target_height;
        
            if(diff > 0)
            {
                time += 2 * abs(diff);
                blocks += abs(diff);
            }
            else if(diff < 0)
            {
                time += abs(diff);
                blocks -= abs(diff);
            }
            else continue;
        }
    }

    if(blocks < 0) return 999999999;
    return time;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> B;
    SandBox.resize(N, vector<int>(M));

    H = -1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> SandBox[i][j];
            H = max(H, SandBox[i][j]);
        }
    }

    int ret_time = 999999999;
    int ret_height = -1;
    for(int h = 0; h <= H; h++)
    {
        int time = make_sandbox(h);
        if(time <= ret_time)
        {
            ret_time = time;
            ret_height = h;
        }
    }

    cout << ret_time << " " << ret_height;
    return 0;
}