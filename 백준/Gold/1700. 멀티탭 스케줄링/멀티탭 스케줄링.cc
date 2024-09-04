#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, K;
vector<int> Orders;

int find_closest(int begin, int key)
{
    int appear = 99999;
    for(int i = begin; i < K; ++i)
    {
        if(Orders[i] == key)
        {
            appear = i;
            break;
        }
    }    
    return appear;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    Orders.resize(K);

    for(int i = 0; i < K; ++i)
        cin >> Orders[i];

    set<int> s;
    int cnt = 0;
    for(int i = 0; i < K; ++i)
    {
        if(s.size() < N)
        {
            s.insert(Orders[i]);
        }
        else
        {
            if(s.find(Orders[i]) == s.end())
            {
                int idx = -1;
                int key = -1;
                for(auto n : s) 
                {
                    int appear = find_closest(i+1, n);
                    if(appear > idx)
                    {
                        key = n;
                        idx = appear;
                    }
                }

                cnt++;
                s.erase(key);
                s.insert(Orders[i]);
            }
        }
    }
    
    cout << cnt;

    return 0;
}