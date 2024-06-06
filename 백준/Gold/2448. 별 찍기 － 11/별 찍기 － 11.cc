#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int Width, Height;

vector<vector<char>> stars;

void print_star(int n, int y, int x, int depth)
{
    if(n == 3)
    {
        stars[y][x] = '*';
        
        stars[y+1][x-1] = '*';
        stars[y+1][x+1] = '*';
        
        for(int i = 0 ; i < 5; i++)
        {
            stars[y+2][x-2+i] = '*';
        }

        return;
    }

    int dy = Height / std::pow(2,depth+1);
    int dx = Width / std::pow(2, depth+2) + 1;

    print_star(n/2, y, x, depth+1);
    print_star(n/2, y + dy, x - dx, depth+1);
    print_star(n/2, y + dy, x + dx, depth+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    Width = 2*N - 1;
    Height = N;

    stars.resize(Height, vector<char>(Width, ' '));
    
    print_star(N, 0, Width/2, 0);

    for(int i = 0; i < stars.size(); i++)
    {
        for(int j = 0; j < stars[0].size(); j++)
        {
            cout << stars[i][j];
        }
        cout << '\n';
    }

    return 0;
}