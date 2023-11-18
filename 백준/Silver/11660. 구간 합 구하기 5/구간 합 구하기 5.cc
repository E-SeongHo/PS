#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> table;

int GetPrefixSum(int y1, int x1, int y2, int x2)
{
    int sum = 0;
    for(int i = y1; i <= y2; ++i)
        sum += table[i][x2] - table[i][x1-1]; 

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    table.resize(N+1, vector<int>(N+1));

    int sum = 0;
    for(int i = 1; i < N+1; ++i)
    {
        for(int j = 0; j < N+1; ++j)
        {
            if(j == 0) table[i][j] = table[i-1][N];
            else
            {
                int n;
                cin >> n;
                sum += n;
                table[i][j] = sum;
            } 
        }
    }

    for(int i = 0; i < M; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ret = GetPrefixSum(x1, y1, x2, y2);
        cout << ret << "\n";
    }
    return 0;
}