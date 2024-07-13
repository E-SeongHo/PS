#include <string>
#include <vector>
#include <iostream>

using namespace std;
enum direction
{
    Up, Down, Left, Right,
};

vector<int> solution(int n) {
    
    vector<vector<int>> snail;
    
    for(int i = 0; i < n; i++)
    {
        vector<int> v(i+1, -1);
        snail.push_back(v);
    }
    
    int y = 0;
    int x = 0;
    int i = 1;
    int limit = ((1 + n) * n) / 2;
    snail[y][x] = i++;
    int dir = Down;
        
    while(i <= limit)
    {
        if(dir == Up)
        {
            if(snail[y-1][x-1] != -1)
            {
                dir = Left;
            }
            else
            {
                y = y-1;
                x = x-1;
                snail[y][x] = i++;
            }
        }
        else if(dir == Down)
        {
            if(y == n-1 || snail[y+1][x] != -1)
            {
                dir = Right;
            }
            else
            {
                y = y+1;
                snail[y][x] = i++;
            }
        }
        else if(dir == Left)
        {
            if(snail[y][x-1] != -1)
            {
                dir = Down;
            }
            else
            {
                x = x-1;
                snail[y][x] = i++;
            }
        }
        else if(dir == Right)
        {
            if((y == n-1 && x == n-1) || snail[y][x+1] != -1)
            {
                dir = Up;
            }
            else
            {
                x = x+1;
                snail[y][x] = i++;
            }
        }
    }
    
    vector<int> answer;
    answer.reserve(limit);
    for(int i = 0; i < snail.size(); i++)
    {
        for(int j = 0; j < snail[i].size(); j++)
        {
            answer.push_back(snail[i][j]);
        }
    }
    
    return answer;
}