#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pr = pair<int, int>;
const int INF = 987654321;

int N, M, X;
vector<vector<pr>> map;
vector<vector<pr>> rmap;

vector<int> to;
vector<int> from;

void Dij(vector<int>& table, vector<vector<pr>>& board, int start)
{
    vector<int> visited(N+1);

    fill(table.begin(), table.end(), INF);
    table[start] = 0;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({table[start], start});
    
    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        int node = p.second;
        int cost = p.first;
        visited[node] = true;

        for(auto edge : board[node])
        {
            int dest = edge.first;
            int weight = edge.second;

            if(visited[dest]) continue;
            if(cost + weight < table[dest])
            {
                table[dest] = cost + weight;
                pq.push({table[dest], dest});
            }
        }
    }
}

int main()
{
    cin >> N >> M >> X;
    map.resize(N+1);
    rmap.resize(N+1);

    to.resize(N+1);
    from.resize(N+1);

    for(int i = 0; i < M; ++i)
    {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        map[n1].push_back({n2, w});
        rmap[n2].push_back({n1, w});
    }

    Dij(to, rmap, X);
    Dij(from, map, X);

    int ret = 0;
    for(int i = 1; i < N+1; ++i)
    {
        int sum = to[i] + from[i];
        ret = max(ret, sum);
    }

    cout << ret;

    return 0;
}