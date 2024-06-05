#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<vector<char>> stars;

void store_star(int n, int y, int x)
{
    if(n == 1) 
    {
        stars[y][x] = '*';
        return;
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == 1 && j == 1) continue;
            store_star(n/3, y + n/3 * i, x + n/3 * j);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    stars.resize(N, vector<char>(N, ' '));
    store_star(N, 0, 0);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << stars[i][j];
        }
        cout << '\n';
    }

    return 0;
}
