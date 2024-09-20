#include <iostream>
#include <queue>

using namespace std;

int n;
int main()
{
    cin >> n;

    queue<int> q;    
    for(int i = 1; i < n+1; ++i)
    {
        q.push(i);
    }

    int turn = 0;
    while(q.size() != 1)
    {
        if(turn % 2 == 0)
        {
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }        
        ++turn;
    }

    cout << q.front();
    return 0;
}