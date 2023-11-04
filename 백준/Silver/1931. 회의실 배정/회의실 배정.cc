#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    if(lhs.first == rhs.first) return lhs.second < rhs.second;
    else return lhs.first < rhs.first;
}

vector<pair<int, int>> tasks;
int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int start, end;
        cin >> start >> end;
        tasks.push_back({start, end});
    }

    sort(tasks.begin(), tasks.end(), cmp);
    vector<pair<int, int>> ans;
    int last = 0;

    auto it = tasks.begin();
    ans.push_back({it->first, it->second});
    it++;

    for(; it != tasks.end(); ++it)
    {
        if(ans.back().second <= it->first)
        {
            last = ans.back().second;
            ans.push_back({it->first, it->second});
        }
        else
        {
            int evalPrev = ans.back().first - last + ans.back().second - ans.back().first;
            int evalCurrent = it->first - last + it->second - it->first;

            if(evalCurrent < evalPrev)
            {
                ans.pop_back();
                ans.push_back({it->first, it->second});
            }
            else if(evalCurrent == evalPrev)
            {
                if(it->second < ans.back().second)
                {
                    ans.pop_back();
                    ans.push_back({it->first, it->second});
                }
            }
        }
    }
    
    cout << ans.size();

    return 0;
}