#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> N;
        vector<int> v(N);
        for(int n = 0; n < N; ++n)
            cin >> v[n];

        vector<int> maxfutures(N);
        int maxtill = 0;        
        for(int i = N-1; i >= 0; --i)
        {
            maxtill = max(maxtill, v[i]);
            maxfutures[i] = maxtill;
        }

        long long outcome = 0;
        int current = 0;
        long long income = 0;

        for(int i = 0; i < N; ++i)
        {
            int maxfuture = maxfutures[i];
            
            if(maxfuture > v[i]) 
            {
                current++;
                income += v[i];
            }
            else 
            {
                outcome += current * v[i];
                current = 0;
            }
        }

        cout << outcome - income << '\n';
    }
    return 0;
}