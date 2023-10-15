#include <iostream>
#include <vector>
#include <string>

using namespace std;

int M, N;
vector<string> given;

int MakeChessBoard8x8(int row, int column)
{
    int cnt = 0;
    char c = given[row][column];

    for(int i = row; i < row + 8; ++i)
    {
        for(int j = column; j < column + 8; ++j)
        {
            if(((row + column) - (i + j)) % 2 == 0)
            {
                if(given[i][j] != c) cnt++;
            }
            else
            {
                if(given[i][j] == c) cnt++;
            }
        }
    }
    return min(64 - cnt, cnt);
}

int main()
{
    cin >> M >> N;
    for(int j = 0; j < M; ++j)
    {
        string s;
        cin >> s;
        given.push_back(s);
    }

    int min = 64;
    for(int i = 0; i < M-7; ++i)
    {
        for(int j = 0; j < N-7; ++j)
        {
            int cnt = MakeChessBoard8x8(i, j);
            if(cnt < min) min = cnt;
        }
    }

    cout << min << endl;
    return 0;
}