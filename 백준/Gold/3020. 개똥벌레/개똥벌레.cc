#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int W, H;
vector<int> Traps1, Traps2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> W >> H;
    Traps1.resize(H+1); Traps2.resize(H+1);

    // Binary Search : O(NlogN + HlogN)
    // PrefixSum : O(H + N)
    for(int i = 0; i < W; i+=2)
    {
        int height1, height2;
        cin >> height1 >> height2;

        ++Traps1[height1];
        ++Traps2[height2];
    }

    for(int i = 1; i < H+1; ++i)
    {
        Traps1[i] += Traps1[i-1];
        Traps2[i] += Traps2[i-1];
    }

    map<int, int> m;
    for(int i = 1; i < H+1; ++i)
    {
        int cnt1 = Traps1[H] - Traps1[i-1];
        int cnt2 = Traps2[H] - Traps2[H+1-i-1];

        m[cnt1+cnt2]++;
    }

    cout << m.begin()->first << " " << m.begin()->second;
}