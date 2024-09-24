#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> V;

void dfs(int start, vector<char>& v)
{
    if(v.size() == L)
    {
        int cnt = 0;
        for(char c : v)
        {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                cnt++;
        }

        if(cnt && L-cnt >= 2)
        {
            for(char c : v) cout << c;
            cout << '\n';
        }
    }

    for(int i = start; i < C; ++i)
    {
        v.push_back(V[i]);
        dfs(i+1, v);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> L >> C;
    V.resize(C);

    for(int i = 0; i < C; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    vector<char> v;
    dfs(0, v);
    
    return 0;
}