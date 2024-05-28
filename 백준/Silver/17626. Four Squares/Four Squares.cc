#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

int N; // 1 <= N <= 50,000
vector<int> SquareTable;

bool lagrangju(vector<int>& v, int current, int limit)
{
    if(v.size() == limit)
    {
        if(accumulate(v.begin(), v.end(), 0) == N) return true;
        else return false;
    }
    
    for(int i = current; i < SquareTable.size(); i++)
    {
        v.push_back(SquareTable[i]);
        if(lagrangju(v, i, limit)) return true;
        v.pop_back();
    }

    return false;
}

int main()
{
    cin >> N;
    SquareTable.resize(sqrt(N) + 1);

    for(int i = 1; i < SquareTable.size(); i++)
    {
        SquareTable[i] = i * i;
    }

    for(int i = 1; i <= 4; i++)
    {
        vector<int> v;
        v.reserve(i);
        if(lagrangju(v, 1, i)) 
        {
            cout << i;
            break;
        }
    }

    return 0;
}