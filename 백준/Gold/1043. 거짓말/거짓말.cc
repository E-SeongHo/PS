#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<int> Set;
vector<int> Know;
vector<vector<int>> Parties;

int Find(int n)
{
    if(Set[n] == n) return n;
    else return Find(Set[n]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    a < b ? Set[b] = a : Set[a] = b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    Set.resize(N+1, false);
    Parties.resize(M);

    for(int i = 0; i < N+1; i++)
    {
        Set[i] = i;
    }

    int p;
    cin >> p;

    for(int i = 0; i < p; i++)
    {
        int n;
        cin >> n;
        Know.push_back(n);
        Union(Know[i], Know[0]);
    }

    for(int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        Parties[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> Parties[i][j];
            Union(Parties[i][0], Parties[i][j]);
        }
    }

    if(p == 0) 
    {
        cout << M;
        return 0;
    }

    int ret = 0;
    for(int i = 0; i < M; i++)
    {
        if(Find(Set[Parties[i][0]]) != Find(Set[Know[0]])) ret++;
    }

    cout << ret;
    return 0;
}