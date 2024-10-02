#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <limits.h>

using namespace std;

int X, N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(cin >> X >> N)
    {
        X = X * 10000000;
        vector<int> v(N);
        for(int i = 0; i < N; ++i)
            cin >> v[i];

        sort(v.begin(), v.end());

        bool flag = false;
        int l1, l2;
        for(int i = 0; i < N; ++i)
        {
            if(binary_search(v.begin()+i+1, v.end(), X-v[i]))
            {
                flag = true;
                l1 = v[i]; l2 = X-v[i];
                break;
            }
        }

        if(flag)
        {
            cout << "yes " << l1 << " " << l2 << '\n';
        }
        else
        {
            cout << "danger" << '\n';
        }
    }
    return 0;
}