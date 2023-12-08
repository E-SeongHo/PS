#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// 1. list : STL list reverse : O(N) 이라서 time exceed

void print(vector<int>& v, int front, int rear, bool reversed)
{
    cout << "[";
    if(reversed && rear > 0)
    {
        for(int i = rear; i >= front; --i)
        {
            cout << v[i];
            if(i != front) cout << ",";
        }    
            
    }
    else
    {
        for(int i = front; i <= rear; ++i)
        {
            cout << v[i];
            if(i != rear) cout << ",";
        }    
    }
    cout << "]\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        string commands, input;
        int N;
        cin >> commands >> N >> input;
        
        string arr = input.substr(1, input.length()-2);
        vector<int> v;
        v.reserve(N);

        istringstream iss(arr);
        string temp;
        while(getline(iss, temp, ','))
            v.push_back(stoi(temp));

        int front = 0;
        int rear = N-1;
        bool reversed = false;

        bool errorFlag = false;
        for(int i = 0; i < commands.size(); ++i)
        {
            if(commands[i] == 'R') reversed = !reversed;
            else 
            {
                if(reversed) rear--;
                else front++;

                if(front > rear+1)
                {
                    errorFlag = true;
                    break;
                }
            }
        }
        if(errorFlag) cout << "error\n";
        else print(v, front, rear, reversed);            
    }

    return 0;
}