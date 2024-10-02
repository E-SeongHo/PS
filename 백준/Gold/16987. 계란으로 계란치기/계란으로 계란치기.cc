#include <iostream>
#include <vector>

using namespace std;

int N, S, W;
vector<pair<int, int>> Eggs;

int MaxCnt = 0;
void dfs(int cur)
{
    if(cur == N) 
    {
        int cnt = 0;
        for(int i = 0; i < N; ++i) 
        {
            if(Eggs[i].first <= 0) cnt++;
        }

        MaxCnt = max(MaxCnt, cnt);
        return;
    }

    if(Eggs[cur].first <= 0) 
    {
        dfs(cur+1);
        return;
    }

    bool flag = false;
    for(int i = 0; i < N; ++i)
    {
        if(i == cur) continue;

        if(Eggs[i].first > 0)
        {
            flag = true;
            Eggs[i].first -= Eggs[cur].second;
            Eggs[cur].first -= Eggs[i].second;

            dfs(cur+1);

            Eggs[i].first += Eggs[cur].second;
            Eggs[cur].first += Eggs[i].second;
        }
    }

    if(!flag) dfs(cur+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    Eggs.resize(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> S >> W;
        Eggs[i] = {S, W};
    }

    dfs(0);
    cout << MaxCnt;

    return 0;
}