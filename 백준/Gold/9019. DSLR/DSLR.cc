#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int d(int n)
{
    return (n*2) % 10000;
}
int s(int n)
{
    if(n == 0) return 9999;
    else return n-1;
}
int l(int n)
{
    return (n % 1000) * 10 + (n / 1000);
}

int r(int n)
{
    return n / 10 + (n % 10) * 1000;
}

string dslr(int current, int goal)
{
    queue<pair<int, string>> q;

    q.push({current, ""});
    vector<bool> visited(10000);
    visited[current] = true;

    while(!q.empty())
    {
        auto p = q.front(); q.pop();
        int n = p.first;

        if(n == goal) return p.second;
    
        int next;  
        next = d(n);
        if(!visited[next])
        {
            q.push({next, p.second + "D"});
            visited[next] = true;
        }
        next = s(n);
        if(!visited[next])
        {
            q.push({next, p.second + "S"});
            visited[next] = true;
        }
        next = l(n);
        if(!visited[next])
        {
            q.push({next, p.second + "L"});
            visited[next] = true;
        }
        next = r(n);
        if(!visited[next])
        {
            q.push({next, p.second + "R"});
            visited[next] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int r1, r2;
        cin >> r1 >> r2;
        cout << dslr(r1, r2) << "\n";        
    }

    return 0;
}