#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N;
vector<int> V;
set<int> S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    V.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            S.insert(V[i]+V[j]);
        }
    }

    for(int i = N-1; i >= 0; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(S.find(V[i]-V[j]) != S.end())
            {
                cout << V[i] << endl;
                return 0;
            }
        }
    }

    return 0;
}