#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Map(9, vector<int>(9));

vector<vector<bool>> Row(9, vector<bool>(10, false));
vector<vector<bool>> Col(9, vector<bool>(10, false));
vector<vector<bool>> Rec(9, vector<bool>(10, false));

int rec_idx(int y, int x) { return (y/3 * 3) + x/3; }

bool Flag = false;
void dfs(int y, int x)
{
    if(Flag) return;
    if(y == 9 || x == 9) 
    {
        Flag = true;
        return;
    }
    int ny = y + (x == 8);
    int nx = (x + 1) % 9;
    
    if(Map[y][x]) dfs(ny, nx);
    else
    {
        for(int n = 1; n <= 9; ++n)
        {
            if(Flag) return;
            if(!Row[y][n] && !Col[x][n] && !Rec[rec_idx(y, x)][n])
            {
                Map[y][x] = n;

                Row[y][n] = true;
                Col[x][n] = true;
                Rec[rec_idx(y, x)][n] = true;

                dfs(ny, nx);
                if(Flag) return;

                Map[y][x] = 0;
                Row[y][n] = false;
                Col[x][n] = false;
                Rec[rec_idx(y, x)][n] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    for(int i = 0; i < 9; ++i)
    {
        string s;
        cin >> s;
        
        for(int j = 0; j < 9; ++j)
        {
            int val = s[j] - '0';
            Map[i][j] = val;
            Row[i][val] = true;
            Col[j][val] = true;
            Rec[rec_idx(i,j)][val] = true;
        }
    }

    dfs(0, 0);
        
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            cout << Map[i][j];
        }
        cout << '\n';
    }


    return 0;
}
