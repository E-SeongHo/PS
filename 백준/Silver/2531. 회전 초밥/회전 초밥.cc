#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

int N, D, K, C;
vector<int> V;
vector<int> Has;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> D >> K >> C;
    V.resize(N+1);
    Has.resize(D+1, 0);

    for(int i = 1; i < N+1; i++)
    {
        cin >> V[i];
    }

    int cnt = 0;
    for(int i = 1; i < K+1; i++)
    {
        if(!Has[V[i]]++) cnt++;
    }
    if(!Has[C]++) cnt++;
    
    int ret = cnt;
    int ptr = K % N;
    if(!ptr) ptr = N;
    
    for(int i = 1; i < N+1; i++)
    {
        assert(Has[V[i]]);

        if(!--Has[V[i]]) cnt--;

        ptr = (ptr + 1) % N;
        if(!ptr) ptr = N;

        if(!Has[V[ptr]]++) cnt++;

        ret = max(ret, cnt);
    }

    cout << ret;

    return 0;
}