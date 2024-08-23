#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int main()
{
    cin >> N;
    vector<int> v(N);

    for(int i = 0; i < N; ++i)
        cin >> v[i];

    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        int min_next = 999999;
        int min_idx = 0;
        for(int j = i+1; j < N; ++j)
        {
            if(v[j] <= v[i] && v[j] <= min_next)
            {
                min_next = v[j];
                min_idx = j;
            }
        }
        if(min_idx == 0) continue;

        int val = v[min_idx];
        int goal = val - (min_idx - i);

        ans += v[i] - goal;
    }

    cout << ans;

    return 0;
}