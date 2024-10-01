#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int N, P, L, M;
set<pair<int, int>, greater<pair<int, int>>> S;
unordered_map<int, int> Levels;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> P >> L;
        S.insert({L, P});
        Levels[P] = L;
    }

    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        string op;
        cin >> op;

        if(op == "recommend")
        {
            int n;
            cin >> n;

            auto it = n == 1 ? S.begin() : --S.end();
            cout << it->second << '\n';
        }
        else if(op == "add")
        {
            cin >> P >> L;
            S.insert({L, P});
            Levels[P] = L;
        }
        else if(op == "solved")
        {
            cin >> P;
            S.erase({Levels[P], P});
        }
    }

    return 0;
}