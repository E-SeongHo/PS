#include <iostream>
#include <vector>

using namespace std;

int T, X, Y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> X >> Y;
        Y = Y-X; X = 0;

        int left = 0;
        int right = Y;

        int jump = 1;
        int cnt = 0;
        while(left < right)
        {
            left += jump;
            right -= jump;

            jump = jump+1;
            cnt++;
        }


        left -= (jump-1);
        right += (jump-1);

        if(right - left <= jump-1) cout << cnt*2 - 1;
        else cout << cnt*2;

        cout << '\n';
    }
    return 0;
}