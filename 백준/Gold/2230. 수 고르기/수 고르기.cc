#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> V;

int binary()
{
    int ret = 2147483647;
    for(int i = 0; i < V.size(); ++i)
    {
        auto it = lower_bound(V.begin(), V.end(), V[i]+M);

        if(it != V.end()) ret = min(ret, *it - V[i]);
    }

    return ret;
}

int two_pointers()
{
    int ret = 2147483647;
    
    int l = 0;
    int r = 0;

    while(l < N && r < N)
    {
        if(V[r] - V[l] >= M) 
        {
            ret = min(ret, V[r] - V[l]);
            l++;
            continue;
        }
        else r++;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    V.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    cout << two_pointers();

    return 0;
}
