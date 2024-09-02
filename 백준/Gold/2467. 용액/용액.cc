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

    int ans = 2000000000;
    int l1 = Liquids[0];
    int l2 = Liquids[N-1];

    for(int i = 0; i < N; ++i)
    {
        int begin = i+1;
        int end = N-1;

        while(begin <= end)
        {
            int mid = begin + (end - begin) / 2;
        
            int combine = Liquids[i] + Liquids[mid];
            if(combine >= 0) end = mid-1;
            else begin = mid+1;

            if(abs(combine) < ans)
            {
                ans = abs(combine);
                l1 = Liquids[i];
                l2 = Liquids[mid];
            }
        }
    }    

    cout << l1 << " " << l2;

    return 0;
}