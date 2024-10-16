#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M;
vector<long long> Time;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    Time.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> Time[i];

    long long l = 0;
    long long r = (*max_element(Time.begin(), Time.end()) * M);
    
    while(l + 1 < r)
    {
        long long mid = (l+r) / 2;

        long long cnt = 0;
        for(int i = 0; i < N; ++i)
        {
            cnt += (mid / Time[i]);
            if(cnt >= M) break;
        }

        if(cnt >= M) r = mid;
        else l = mid;
    }

    cout << r;
    return 0;
}
