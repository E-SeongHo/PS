#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> Coords;

int count_availables(int gap)
{
    int cnt = 1;
    int prev = 0;
    for(int i = 1; i < N; ++i)
    {
        if(Coords[i] - Coords[prev] >= gap)
        {
            prev = i;
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C;
    Coords.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> Coords[i];

    sort(Coords.begin(), Coords.end());

    int begin = 1;
    int end = 1000000001;

    while(begin + 1 < end)
    {
        int mid = (begin + end) / 2;
        int cnt = count_availables(mid);

        if(cnt >= C) begin = mid;
        else end = mid;
    }

    cout << begin;

    return 0;
}