#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
int N, M;

set<string> neverHeard;
set<string> neverSeen;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        neverHeard.insert(s);
    }

    for(int i = 0; i < M; ++i)
    {
        string s;
        cin >> s;
        neverSeen.insert(s);
    }

    auto itH = neverHeard.begin();
    auto itS = neverSeen.begin();

    vector<string> never;
    while(itH != neverHeard.end() && itS != neverSeen.end())
    {
        if(*itH == *itS)
        {
            never.push_back(*itH);
            itH++; 
            itS++;
            continue;
        }

        if(*itH > *itS)
        {
            itS++;
            continue;
        }

        if(*itH < *itS)
        {
            itH++;
            continue;
        }
    }
    
    cout << never.size() << "\n";
    for(auto s : never)
        cout << s << "\n";

    return 0;
}

