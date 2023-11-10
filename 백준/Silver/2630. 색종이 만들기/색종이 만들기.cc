#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> paper;
int blue = 0;
int white = 0;

void CheckSquare(int y, int x, int n)
{
    int color = paper[y][x];
    bool flag = true;

    for(int i = y; i < y+n; ++i)
    {    
        for(int j = x; j < x+n; ++j)
        {    
            if(paper[i][j] != color)
            {
                flag = false;
                break;    
            }
        } 
    }

    if(flag)
    {
        if(color == 1) blue++;
        else if(color == 0) white++;
        return;
    }

    else
    {
        int offset = n/2;
        CheckSquare(y, x, offset);
        CheckSquare(y+offset, x, offset);
        CheckSquare(y, x+offset, offset);
        CheckSquare(y+offset, x+offset, offset);
    }
    
}

int main()
{
    int N;
    cin >> N;

    paper.resize(N, vector<int>(N));
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> paper[i][j];

    CheckSquare(0, 0, N);
    cout << white << "\n" << blue;
    
    return 0;
}