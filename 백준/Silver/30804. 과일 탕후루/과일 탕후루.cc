#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N;
vector<int> V;
vector<int> Cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    V.resize(N); Cnt.resize(10, 0);
    for(int i = 0; i < N; ++i)
        cin >> V[i];

    int l = 0;
    int r = 0;
    Cnt[V[r]]++;
    int ret = 0;
    
    while(r < N && l <= r)
    {
        int cnt = 0;
        for(int n : Cnt) if(n) cnt++;

        if(cnt > 2)
        {
            l++;
            Cnt[V[l-1]]--;
        }
        else
        {
            ret = max(ret, r-l+1);
            r++;
            Cnt[V[r]]++;
        }
    }
    
    cout << ret;
    
    return 0;
}
