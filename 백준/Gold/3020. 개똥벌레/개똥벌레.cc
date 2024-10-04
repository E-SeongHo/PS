#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int W, H;
vector<int> Traps;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> W >> H;
    Traps.resize(H+2);

    // Binary Search : O(NlogN + HlogN)
    // PrefixSum : O(H + H)
    // IMOS : O(H + H)

    // marking
    for(int i = 0; i < W; i+=2)
    {
        int height1, height2;
        cin >> height1 >> height2;

        Traps[1]++;
        Traps[height1+1]--;

        Traps[H - height2+1]++;
        Traps[H+1]--;
    }

    // sweep
    for(int i = 1; i < H+1; ++i)
    {
        Traps[i] += Traps[i-1];
    }

    map<int, int> m;
    for(int i = 1; i < H+1; ++i)
    {
        m[Traps[i]]++;
    }

    cout << m.begin()->first << " " << m.begin()->second;
}