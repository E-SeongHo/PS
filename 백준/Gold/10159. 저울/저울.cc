#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<vector<int>> Smaller, Bigger;

void visit_smaller(int cur, vector<bool>& visited)
{
    visited[cur] = true;

    for(int n : Smaller[cur])
    {
        if(!visited[n]) visit_smaller(n, visited);
    }
}

void visit_bigger(int cur, vector<bool>& visited)
{
    visited[cur] = true;

    for(int n : Bigger[cur])
    {
        if(!visited[n]) visit_bigger(n, visited);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    Smaller.resize(N+1); Bigger.resize(N+1);

    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        Smaller[b].push_back(a);
        Bigger[a].push_back(b);
    }

    for(int i = 1; i < N+1; ++i)
    {
        vector<bool> v(N+1, false);
        visit_smaller(i, v);
        
        int smaller = 0;
        for(int i = 1; i < N+1; ++i)
        {
            if(v[i]) smaller++;
        }

        fill(v.begin(), v.end(), false);
        visit_bigger(i, v);

        int bigger = 0;
        for(int i = 1; i < N+1; ++i)
        {
            if(v[i]) bigger++;
        }

        cout << N-1 - (smaller + bigger - 2) << '\n';
    }


    return 0;
}