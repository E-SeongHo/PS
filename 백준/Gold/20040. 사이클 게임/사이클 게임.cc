#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> DSet;

int xfind(int a)
{
    if(DSet[a] == a) return a;

    DSet[a] = xfind(DSet[a]);
    return DSet[a];
}

void xunion(int a, int b)
{
    a = xfind(a);
    b = xfind(b);

    a < b ? DSet[b] = a : DSet[a] = b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    DSet.resize(N);

    for(int i = 0; i < N; ++i)
        DSet[i] = i;


    int ans = -1;
    bool flag = false;
    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;

        if(flag) continue;
        
        if(xfind(a) == xfind(b)) 
        {
            flag = true;
            ans = i+1;
            continue;
        }

        xunion(a, b);
    }

    flag ? cout << ans : cout << 0;

    return 0;
}
