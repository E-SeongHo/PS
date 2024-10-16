#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> Time;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    Time.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> Time[i];

    long long l = 0;
    long long r = 1000000000000ll;

    while(l + 1 < r)
    {
        long long mid = (l+r) / 2;

        long long cnt = 0;
        for(int time : Time)
        {
            cnt += (mid / time);
            if(cnt >= M) break;
        }

        if(cnt >= M) r = mid;
        else l = mid;
    }

    cout << r;

    return 0;
}
