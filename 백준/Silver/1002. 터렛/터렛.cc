#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

int distance(int x1, int x2, int y1, int y2)
{
    return ((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
}

int main()
{
    int x1, x2, y1, y2;
    int r1, r2;
    int T;

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if(x1 == x2 && y1 == y2) 
        {
            if(r1 == r2) cout << -1 << '\n';
            else cout << 0 << '\n';
        }
        else
        {
            int squaredDist = distance(x1, x2, y1, y2);
            if((r1 + r2) * (r1 + r2) == squaredDist) cout << 1 << '\n';
            else if((r1 + r2) * (r1 + r2) < squaredDist) cout << 0 << '\n';
            else
            {
                if((r2 - r1) * (r2 - r1) < squaredDist) cout << 2 << '\n';
                else if((r2 - r1) * (r2 - r1) == squaredDist) cout << 1 << '\n';
                else cout << 0 << '\n';
            }
        }
    }

    return 0;
}