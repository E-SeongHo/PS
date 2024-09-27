#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, X, Y;
vector<vector<int>> V;
int A, B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> A >> B >> M;
    V.resize(N+1);

    for(int i = 0; i < M; ++i)
    {
        cin >> X >> Y;
        V[X].push_back(Y);
        V[Y].push_back(X);
    }

    queue<pair<int, int>> q;
    vector<bool> visited(N+1, false);

    q.push({A, 0});
    visited[A] = true;

    int ans = -1;
    while(!q.empty())
    {
        auto [cur, cost] = q.front(); q.pop();
        if(cur == B)
        {
            ans = cost;
            break;
        }

        for(int next : V[cur])
        {
            if(!visited[next])
            {
                visited[next] = true;
                q.push({next, cost+1});
            }
        }
    }

    cout << ans;

    return 0;
}