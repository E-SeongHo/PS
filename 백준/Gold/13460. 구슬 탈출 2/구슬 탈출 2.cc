#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

constexpr char BLANK = '.';
constexpr char WALL = '#';
constexpr char HALL = 'O';
constexpr char RED = 'R';
constexpr char BLUE = 'B';

int N, M;
vector<vector<char>> Board;

vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};

void lean(int dir, int& red_y, int& red_x, int& blue_y, int& blue_x)
{
    bool redpass = false;
    bool bluepass = false;

    bool redfirst;
    switch(dir)
    {
    case 0:
        redfirst = (red_y < blue_y);
        break;
    case 1:
        redfirst = (red_y > blue_y);
        break;
    case 2:
        redfirst = (red_x < blue_x);
        break;
    case 3:
        redfirst = (red_x > blue_x);
        break;
    }

    if(redfirst)
    {
        while(!redpass)
        {
            int ry = red_y + dy[dir];
            int rx = red_x + dx[dir];

            if(Board[ry][rx] == WALL || Board[ry][rx] == HALL) 
            {
                redpass = true;
                if(Board[ry][rx] == HALL)
                {
                    red_y = -99; red_x = -99;
                }
            }
            else
            {
                red_y = ry; red_x = rx;
            }
        }

        while(!bluepass)
        {
            int by = blue_y + dy[dir];
            int bx = blue_x + dx[dir];

            if(Board[by][bx] == WALL || Board[by][bx] == HALL || (by == red_y && bx == red_x)) 
            {
                bluepass = true;
                if(Board[by][bx] == HALL)
                {
                    blue_y = -99; blue_x = -99;
                }
            }
            else
            {
                blue_y = by; blue_x = bx;
            }
        }
    }
    else
    {
        while(!bluepass)
        {
            int by = blue_y + dy[dir];
            int bx = blue_x + dx[dir];

            if(Board[by][bx] == WALL || Board[by][bx] == HALL) 
            {
                bluepass = true;
                if(Board[by][bx] == HALL)
                {
                    blue_y = -99; blue_x = -99;
                }
            }
            else
            {
                blue_y = by; blue_x = bx;
            }
        }

        while(!redpass)
        {
            int ry = red_y + dy[dir];
            int rx = red_x + dx[dir];

            if(Board[ry][rx] == WALL || Board[ry][rx] == HALL || (ry == blue_y && rx == blue_x)) 
            {
                redpass = true;
                if(Board[ry][rx] == HALL)
                {
                    red_y = -99; red_x = -99;
                }
            }
            else
            {
                red_y = ry; red_x = rx;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    Board.resize(N, vector<char>(M));

    int ry, rx, by, bx;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> Board[i][j];
            if(Board[i][j] == RED)
            {
                ry = i; rx = j;
            }
            if(Board[i][j] == BLUE)
            {
                by = i; bx = j;
            }
        }
    }
    
    // vector<int> ansv = {3, 2, 1};
    // for(int v : ansv)
    // {
    //     lean(v, ry, rx, by, bx);
    //     for(int i = 0; i < N; ++i)
    //     {
    //         for(int j = 0; j < M; ++j)
    //         {
    //             if(i == ry && j == rx) cout << "R";
    //             else if(i == by && j == bx) cout << "B";
    //             else if(Board[i][j] == HALL) cout << "O";
    //             else if(Board[i][j] == WALL) cout << "#";
    //             else cout << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    // return 0;

    using tup = tuple<int, int, int, int, int>;
    queue<tup> q;
    q.push({ry, rx, by, bx, 0});

    int ans = -1;
    while(!q.empty())
    {
        auto [red_y, red_x, blue_y, blue_x, dep] = q.front(); q.pop();

        if(dep == 11) break;
        bool redpass = red_y == -99 && red_x == -99;
        bool bluepass = blue_y == -99 && blue_x == -99;
        if(redpass || bluepass)
        {   
            if(redpass && !bluepass)
            {
                ans = dep; 
                // for(int i = 0; i < v.size(); ++i) cout << v[i] << " ";
                // cout << endl;
                break;
            }
            else continue;
        }

        for(int i = 0; i < 4; ++i)
        {
            int nry = red_y; 
            int nrx = red_x;
            int nby = blue_y;
            int nbx = blue_x;
            lean(i, nry, nrx, nby, nbx);
            // vector<int> vv = v;
            // vv.push_back(i);
            q.push({nry, nrx, nby, nbx, dep+1});
        }
    }

    cout << ans;

    return 0;
}