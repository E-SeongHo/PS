#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
vector<int> Lans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> N;
    Lans.resize(K);

    for(int i = 0; i < K; ++i) cin >> Lans[i];

    long long begin = 1;
    long long end = 2147483647;

    while(begin <= end)
    {   
        long long mid = begin + (end - begin) / 2;
        int num = 0;
        for(int i = 0; i < K; ++i)
        {
            num += Lans[i] / mid;
        }

        if(num >= N) begin = mid+1;
        else end = mid-1;
    }

    cout << end;

    return 0;
}