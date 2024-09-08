#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    V.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        int left = 0;
        int right = N-1;

        while(left < right)
        {
            if(left == i) 
            {
                left++;
                continue;
            }
            if(right == i)
            {
                right--;
                continue;
            }   

            int sum = V[left] + V[right];
            if(sum == V[i])
            {
                ans++;
                break;
            }

            if(sum > V[i]) right--;
            else left++;
        }
    }    
    cout << ans;
    return 0;
}