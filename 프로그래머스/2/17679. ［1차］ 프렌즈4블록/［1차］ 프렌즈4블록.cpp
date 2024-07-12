#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
    
    int cnt = 0;
    while(true)
    {
        set<pair<int, int>> s;
        for(int i = 0; i < m-1; i++)
        {
            for(int j = 0; j < n-1; j++)
            {
                char c = board[i][j];
                if(c == 'X') continue;
                
                if(board[i][j] == c && board[i+1][j] == c && board[i][j+1] == c && board[i+1][j+1] == c)
                {
                    s.insert({i, j});
                    s.insert({i+1, j});
                    s.insert({i, j+1});
                    s.insert({i+1, j+1});
                }
            }
        }    
        
        if(!s.size()) break;
        cnt += s.size();
                
        for(auto p : s)
        {
            board[p.first][p.second] = 'X';
        }
        
        for(int j = 0; j < n; j++)
        {
            int x = 0;
            for(int i = m-1; i >= 0; i--)
            {
                if(board[i][j] == 'X') x++;
                else 
                {
                    if(x) 
                    {
                        board[i+x][j] = board[i][j];
                        board[i][j] = 'X';
                    }
                }
            }
        }
        
    }
    
    
    return cnt;
}