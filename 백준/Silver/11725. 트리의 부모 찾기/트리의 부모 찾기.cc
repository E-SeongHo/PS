#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> adjList;
vector<int> parent;

void DFS(int node)
{
    for(auto n : adjList[node])
    {
        if(!parent[n]) 
        {   
            parent[n] = node;
            DFS(n);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    adjList.resize(N+1);
    parent.resize(N+1);

    for(int i = 0; i < N-1; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adjList[n1].push_back(n2);
        adjList[n2].push_back(n1);
    }

    DFS(1);

    for(int i = 2; i < parent.size(); ++i)
        cout << parent[i] << "\n";

    return 0;
}