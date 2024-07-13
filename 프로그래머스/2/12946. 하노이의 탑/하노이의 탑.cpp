#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Answer;

void hanoi(int n, int from, int temp, int to)
{
    if(n == 1)
    {
        Answer.push_back(vector<int>({from, to}));
        return;
    }
    
    hanoi(n-1, from, to, temp);
    hanoi(1, from, temp, to);
    hanoi(n-1, temp, from, to);
}

vector<vector<int>> solution(int n) {
    
    hanoi(n, 1, 2, 3);
    
    return Answer;
}