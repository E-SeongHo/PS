#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> dy = {0, 0, +1, +1};
vector<int> dx = {0, +1, 0, +1};

int Zeros = 0;
int Ones = 0;

void search(vector<vector<int>>& arr, int depth, int y, int x)
{
    int quad_size = arr.size() / pow(2, depth);
    
    for(int k = 0; k < 4; k++)
    {
        int start_y = y + dy[k] * quad_size/2;
        int start_x = x + dx[k] * quad_size/2;
        
        if(quad_size / 2 == 1)
        {
            arr[start_y][start_x] == 0 ? Zeros++ : Ones++;
            continue;
        }
        
        bool flag = false;
        int val = arr[start_y][start_x];
        
        for(int i = 0; i < quad_size/2; i++)
        {
            for(int j = 0; j < quad_size/2; j++)
            {
                if(arr[start_y + i][start_x + j] != val)
                {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) 
        {
            val == 0 ? Zeros++ : Ones++;
        }
        else
        {
            search(arr, depth+1, start_y, start_x);
        }
    }

}
vector<int> solution(vector<vector<int>> arr) {
    
    int val = arr[0][0];
    bool flag = false;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            if(arr[i][j] != val) 
            {
                flag = true;
                break; 
            }
        }
        if(flag) break;
    }
    
    if(!flag)
    {
        val == 0 ? Zeros++ : Ones++;
    }
    else
    {
        search(arr, 0, 0, 0);
    }

    vector<int> answer{Zeros, Ones};
    return answer;
}