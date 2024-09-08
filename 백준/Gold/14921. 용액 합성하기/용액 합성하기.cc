#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> Liquids;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    Liquids.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> Liquids[i];


    int ans = 200000001;
    for(int i = 0; i < N; ++i)
    {
        int begin = i+1;
        int end = N-1;

        while(begin <= end)
        {
            int mid = begin + (end - begin) / 2;
            int sum = Liquids[mid] + Liquids[i];
            if(abs(sum) < abs(ans)) ans = sum;

            if(sum >= 0) end = mid-1;
            else begin = mid+1;
        }
    }  

    cout << ans;

    return 0;
}
