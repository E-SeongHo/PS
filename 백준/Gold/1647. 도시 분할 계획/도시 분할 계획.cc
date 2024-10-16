#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N, M, A, B, C;
vector<int> DisjointSet;
int Groups;

using tup = tuple<int, int, int>;
vector<tup> Edges;

int xfind(int a)
{
    if(DisjointSet[a] == a) return a;

    DisjointSet[a] = xfind(DisjointSet[a]);
    return DisjointSet[a];
}

void xunion(int a, int b)
{
    a = xfind(a);
    b = xfind(b);
    if(a > b) swap(a, b);

    DisjointSet[b] = a;
    Groups--;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    DisjointSet.resize(N+1);
    Groups = N;
    for(int i = 1; i < N+1; ++i) 
        DisjointSet[i] = i;

    Edges.resize(M);

    for(int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C;
        Edges[i] = {C, A, B};    
    }

    sort(Edges.begin(), Edges.end());

    int ans = 0;
    for(auto [cost, a, b] : Edges)
    {
        if(xfind(a) == xfind(b)) continue;

        xunion(a, b);
        ans += cost;
        if(Groups == 1)
        {
            ans -= cost;
            break;
        }
    }

    cout << ans;

    return 0;
}
