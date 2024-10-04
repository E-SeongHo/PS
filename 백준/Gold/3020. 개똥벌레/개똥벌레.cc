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
    Traps1.resize(W/2); Traps2.resize(W/2);

    for(int i = 0; i < W; ++i)
    {
        int height;
        cin >> height;

        i % 2 == 0 ? Traps1[i/2] = height : Traps2[i/2] = height;
    }

    sort(Traps1.begin(), Traps1.end());
    sort(Traps2.begin(), Traps2.end());

    map<int, int> m;
    for(int i = 1; i < H+1; ++i)
    {
        int cnt1 = (int)Traps1.size() - (lower_bound(Traps1.begin(), Traps1.end(), i) - Traps1.begin());
        int cnt2 = (int)Traps2.size() - (lower_bound(Traps2.begin(), Traps2.end(), (H+1 - i)) - Traps2.begin());
        m[cnt1+cnt2]++;
    }

    auto it = m.begin();
    cout << it->first << " " << it->second;

    return 0;
}