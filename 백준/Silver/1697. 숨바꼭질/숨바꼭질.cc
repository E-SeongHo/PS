#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<bool> visited;
vector<int> weight;

int N, K;

void BFS(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;
    weight[n] = 0;

    while(q.front() != K)
    {
        int node = q.front();
        q.pop();
        if(node-1 >= 0 && !visited[node-1]) 
        {
            q.push(node-1);
            visited[node-1] = true;
            weight[node-1] = weight[node] + 1;
        }    
        if(node+1 <= visited.size()-1 && !visited[node+1])
        {
            q.push(node+1);
            visited[node+1] = true;
            weight[node+1] = weight[node] + 1;
        }
        if(2*node <= visited.size()-1 && !visited[2*node])
        {
            q.push(2*node);
            visited[2*node] = true;
            weight[2*node] = weight[node] + 1;
        }
    }
}

int main()
{
    cin >> N >> K;

    int size = max(N, K) + 1;
    size*= 2;
    visited.resize(size);
    weight.resize(size);

    BFS(N);

    cout << weight[K];
    
    return 0;
}