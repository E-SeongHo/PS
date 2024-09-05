#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> Childs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    Childs.resize(N+1);
    for(int i = 1; i < N+1; ++i)
        cin >> Childs[i];

    vector<int> v(N+1);
    int len = 0;
    for(int i = 1; i < N+1; ++i)
    {
        v[Childs[i]] = v[Childs[i]-1] + 1;
        len = max(len, v[Childs[i]]);
    }

    cout << N - len;

    return 0;
}