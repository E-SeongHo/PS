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

    int gap = Coords[N-1] - Coords[0];
    while(count_availables(gap) < C)
    {
        gap = gap/2;
    }
    
    while(count_availables(gap) >= C)
    {
        gap++;
    }

    cout << gap-1;

    return 0;
}