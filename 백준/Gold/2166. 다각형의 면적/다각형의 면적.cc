#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<pair<long long, long long>> Pos;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    Pos.resize(N);

    for(int i = 0; i < N; ++i)
    {
        long long x, y;
        cin >> x >> y;
        Pos[i] = {x, y};
    }    

    auto [ref_x, ref_y] = Pos[0];

    double S = 0;
    for(int i = 1; i < N-1; ++i)
    {
        auto [x1, y1] = Pos[i];
        auto [x2, y2] = Pos[i+1];

        double s = (ref_x*y1 + x1*y2 + x2*ref_y) - (x1*ref_y + x2*y1 + ref_x*y2);
        S += s;
    }

    cout << fixed;
    cout.precision(1);

    cout << abs(S) / 2.0;
    return 0;
}
