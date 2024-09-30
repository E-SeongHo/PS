#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T, N;
vector<string> V;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> N;
        V.resize(0); V.resize(N);
        for(int i = 0; i < N; ++i)
            cin >> V[i];

        sort(V.begin(), V.end());

        bool flag = false;
        for(int i = 0; i < N-1; ++i)
        {
            if(V[i+1].substr(0, V[i].length()) == V[i])
            {
                flag = true;
                break;
            }
        }
        if(flag) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }

    return 0;
}