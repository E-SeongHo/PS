#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int V, E;
vector<tuple<int, int, int>> Edges;
vector<int> DisjointSet;


int find(int e)
{
    if(DisjointSet[e] == e) return e;

    return DisjointSet[e] = find(DisjointSet[e]);
}

void union_set(int s1, int s2)
{
    int a = find(s1);
    int b = find(s2);

    a < b ? DisjointSet[b] = a : DisjointSet[a] = b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E;
    DisjointSet.resize(V+1);
    for(int i = 1; i < V+1; i++)
    {
        DisjointSet[i] = i;
    }

    Edges.reserve(E);

    for(int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edges.push_back({c, a, b});
    }

    sort(Edges.begin(), Edges.end());

    int mst_cost = 0;
    int cnt = 0;
    for(auto [weight, a, b] : Edges)
    {
        if(find(a) != find(b))
        {
            mst_cost += weight;
            union_set(a, b);
            cnt++;

            if(cnt == V-1) break;
        }
    }

    cout << mst_cost;

    return 0;
}