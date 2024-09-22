#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> V;
int cnt = 0;

void dfs(int depth, int total)
{
    if(depth == N)
    {
        if(total == S) cnt++;
        return;
    }

    dfs(depth+1, total);
    dfs(depth+1, total + V[depth]);
}

int main()
{
    cin >> N >> S;
    V.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> V[i];

    // O(2^N)
    dfs(0, 0);
    if(S == 0) cnt--;

    cout << cnt;

    return 0;
}