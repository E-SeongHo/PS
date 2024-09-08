#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> Liquids;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    Liquids.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> Liquids[i];

    sort(Liquids.begin(), Liquids.end());

    int l1, l2, l3;
    long long ans = 3000000001;

    for(int i = 0; i < N; ++i)
    {
        for(int j = i+1; j < N; ++j)
        {
            int begin = j+1;
            int end = N-1;

            while(begin <= end)
            {
                int mid = begin + (end - begin) / 2;
                long long sum = Liquids[i] + Liquids[j] + Liquids[mid];

                if(abs(sum) < abs(ans))
                {
                    l1 = Liquids[i];
                    l2 = Liquids[j];
                    l3 = Liquids[mid];
                    ans = sum;
                }

                if(sum >= 0) end = mid-1;
                else begin = mid+1;
            }
        }
    }

    cout << l1 << " " << l2 << " " << l3;

    return 0;
}