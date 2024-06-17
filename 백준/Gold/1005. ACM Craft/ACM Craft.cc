#include <iostream>
#include <vector>

using namespace std;

int T, N, K, X, Y, W;
vector<int> BuildTimes;
vector<vector<int>> Edges;
vector<vector<int>> ReverseEdges;
vector<bool> Visited;
vector<int> Order;

void dfs(int current)
{
    Visited[current] = true;
    
    if(current != W)
    {
        for(auto vertex : Edges[current])
        {
            if(!Visited[vertex]) dfs(vertex);
        }
    }

    Order.push_back(current);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int tc = 0; tc < T; tc++)
    {
        cin >> N >> K;

        vector<int> buildTimes(N+1);
        vector<vector<int>> edges(N+1);
        vector<vector<int>> reverseEdges(N+1);
        vector<bool> visited(N+1);
        vector<int> order;

        for(int i = 1; i < N+1; i++)
        {
            cin >> buildTimes[i];
        }

        for(int i = 0; i < K; i++)
        {
            cin >> X >> Y;
            edges[X].push_back(Y);
            reverseEdges[Y].push_back(X);
        }

        cin >> W;

        BuildTimes = buildTimes;
        Edges = edges;
        ReverseEdges = reverseEdges;
        Visited = visited;
        Order = order;

        for(int i = 1; i < N+1; i++)
        {
            if(!Visited[i]) dfs(i);
        }

        vector<int> dp(N+1, 0);
        
        for(auto it = Order.rbegin(); it != Order.rend(); ++it)
        {
            int prev = 0;
            for(auto vertex : ReverseEdges[*it])
            {
                prev = max(prev, dp[vertex]);
            }
            
            dp[*it] = prev + BuildTimes[*it];
        }

        cout << dp[W] << '\n';
    }

    return 0;
}