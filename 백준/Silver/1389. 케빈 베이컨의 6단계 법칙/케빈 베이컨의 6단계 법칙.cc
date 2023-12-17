#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;
int N, M;
vector<vector<int>> friends;
const int INF = 1987654321;

int get_kevin(int n)
{
    vector<int> visited(N+1);
    queue<int> q;
    visited[n] = 0;
    q.push(n);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        for(auto f : friends[current])
        {
            if(!visited[f])
            {
                visited[f] = visited[current] + 1;
                q.push(f);
            }
        }
    }

    int kevin = accumulate(visited.begin()+1, visited.end(), 0) - visited[n];

    return kevin;
}

int main()
{
    cin >> N >> M;
    friends.resize(N+1);

    for(int i = 0; i < M; ++i)
    {
        int f1, f2;
        cin >> f1 >> f2;
        friends[f1].push_back(f2);
        friends[f2].push_back(f1);
    }

    int min_kevin = INF;
    int kevin_bacon = 1;

    // O(N * N)
    for(int i = 1; i < N+1; ++i)
    {
        int kevin = get_kevin(i);
        if(min_kevin > kevin)
        {
            min_kevin = kevin;
            kevin_bacon = i;
        }            
    }

    cout << kevin_bacon;

    return 0;
}