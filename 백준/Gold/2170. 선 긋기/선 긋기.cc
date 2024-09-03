#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X1, X2;
vector<pair<int, int>> Locations;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    Locations.resize(N);

    for(int i = 0; i < N; ++i)
    {
        cin >> X1 >> X2;
        Locations[i] = {X1, X2};
    }

    sort(Locations.begin(), Locations.end());

    int len = 0;
    int begin = Locations.front().first;
    int end = Locations.front().second;

    for(auto& [x1, x2] : Locations)
    {
        if(x1 > end)
        {
            len += end - begin;
            begin = x1;
            end = x2;
        }
        else
        {
            end = max(end, x2);
        }
    }    

    len += end - begin;

    cout << len;

    return 0;
}