#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> K;
    V.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> V[i];

    int l = 0;
    int r = 0;
    vector<int> cnts(100001, 0);
    cnts[V[r]]++;
    int ret = 0;
    while(l <= r && r < N)
    {
        if(cnts[V[r]] > K)
        {
            l++;
            cnts[V[l-1]]--;
        }
        else
        {
            ret = max(ret, r-l+1);
            r++;    
            cnts[V[r]]++;
        }
    }

    cout << ret;

    return 0;
}
