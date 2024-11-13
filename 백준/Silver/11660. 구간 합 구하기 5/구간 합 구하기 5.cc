#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> Sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    Sum.resize(N+1, vector<int>(N+1, 0));

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int n;
            cin >> n;
            Sum[i][j] = Sum[i-1][j] + Sum[i][j-1] - Sum[i-1][j-1] + n;
        }
    }

    for(int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << Sum[x2][y2] - Sum[x2][y1-1] - Sum[x1-1][y2] + Sum[x1-1][y1-1] << '\n';
    }

    return 0;
}
