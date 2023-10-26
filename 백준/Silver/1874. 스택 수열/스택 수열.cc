#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int N;
    cin >> N;
    v.reserve(N);

    for(int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }

    vector<char> record;
    vector<int> stack;
    int p = 1;    

    for(int i = 0; i < N; ++i)
    {
        int goal = v[i];
        if(p > N+1)
        {
            cout << "NO";
            return 0;
        }
        if(p < goal)
        {
            while(p <= goal)
            {               
                stack.push_back(p++);
                record.push_back('+');           
            }
            stack.pop_back();
            record.push_back('-');
        }
        else if(p > goal)
        {
            if(stack.back() != goal)
            {
                cout << "NO";
                return 0;
            }
            stack.pop_back();
            record.push_back('-');
        }
        else // p == goal
        {
            stack.push_back(p++);
            record.push_back('+');
            stack.pop_back();
            record.push_back('-');
        }
    }


    for(auto r : record)
        cout << r << "\n";
    
    return 0;
}