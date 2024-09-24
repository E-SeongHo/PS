#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> S;

void dfs(int start, vector<int>& v)
{
    if(v.size() == 6)
    {
        for(int n : v) cout << n << " ";
        cout << '\n';

        return;
    }

    for(int i = start; i < K; ++i)
    {
        v.push_back(S[i]);
        dfs(i+1, v);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(true)
    {
        cin >> K;
        if(!K) break;

        S.resize(K);
        for(int i = 0; i < K; ++i)
            cin >> S[i];

        vector<int> s;
        dfs(0, s);
        cout << '\n';
    }

    return 0;
}