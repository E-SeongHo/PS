#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, K;

int Func()
{
    if(N >= K) return N-K;

    vector<int> visited(K*2);
    fill(visited.begin(), visited.end(), 987654321);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, N});
    visited[N] = 0;

    while(1)
    {
        auto p = pq.top();
        pq.pop();
        
        int pos = p.second;
        int time = p.first;
        if(pos == K) return time;
        if(visited[pos] < time) continue;

        visited[pos] = time;

        if(pos-1 >= 0) pq.push({time+1, pos-1});
        if(pos && pos*2 <= K*2) pq.push({time, pos*2});
        if(pos+1 <= K) pq.push({time+1, pos+1});
    }

}

int main()
{
    cin >> N >> K;
    cout << Func();
}

