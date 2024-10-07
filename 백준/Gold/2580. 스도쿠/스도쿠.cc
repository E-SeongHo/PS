#include <iostream>
#include <vector>

using namespace std;

const int N = 9;
vector<vector<int>> Board(N, vector<int>(N, 0));
vector<pair<int, int>> Empty;

bool flag = false;
void dfs(int dep)
{
    if(dep == (int)Empty.size()) 
    {
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                cout << Board[i][j] << " ";
            }
            cout << '\n';
        }
        flag = true;
        return;
    }

    auto [y, x] = Empty[dep];
    int vertical = 0;
    for(int i = 0; i < N; ++i)
    {
        if(Board[y][i]) 
        {
            vertical |= (1 << (Board[y][i]));
        }
    }

    int horizontal = 0;
    for(int i = 0; i < N; ++i)
    {
        if(Board[i][x]) 
        {
            horizontal |= (1 << (Board[i][x]));
        }
    }

    int start_y = 3 * (y / 3);
    int start_x = 3 * (x / 3);
    int quad = 0;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(Board[start_y + i][start_x + j]) 
            {
                quad |= (1 << (Board[start_y+i][start_x+j]));
            }
        }
    }

    vector<int> candidates;
    for(int i = 1; i <= N; ++i)
    {
        int mask = 1 << i;

        if(!(vertical & mask) && !(quad & mask) && !(horizontal & mask))
        {
            candidates.push_back(i);
        }
    }    

    for(int n : candidates)
    {
        Board[y][x] = n;
        dfs(dep+1);
        if(flag) return;
        Board[y][x] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> Board[i][j];
            if(!Board[i][j]) Empty.push_back({i, j});
        }
    }    
    dfs(0);

    return 0;
}

