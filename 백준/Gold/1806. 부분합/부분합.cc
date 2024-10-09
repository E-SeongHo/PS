#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> S;
    V.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];

    int l = 0;
    int r = 0;
    int sum = V[0];
    int ret = 99999999;
    while(r < N && l <= r)
    {
        if(sum < S) 
        {
            if(r == N-1) break;
            r++;
            sum += V[r];
        }
        else 
        {
            ret = min(ret, r-l+1);
            l++;
            sum -= V[l-1];
        }
    }

    ret == 99999999 ? cout << 0 : cout << ret;
    return 0;
}
