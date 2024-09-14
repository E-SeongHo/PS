#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L;
vector<int> Stops;

bool check(int gap)
{
    int cnt = 0;
    int start = 0;
    int end = L;

    for(int i = 1; i < N+2; ++i)
    {   
        int room = Stops[i] - Stops[i-1];
        
        if(room > gap)
        {
            cnt += room / gap;
            if(room % gap == 0) cnt--;
        }
    }

    return cnt <= M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> L;
    Stops.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> Stops[i];

    Stops.push_back(0);
    Stops.push_back(L);

    sort(Stops.begin(), Stops.end());

    int begin = 0;
    int end = L;

    while(begin + 1 < end)
    {
        int mid = (begin + end) / 2;

        if(!check(mid)) begin = mid;
        else end = mid;
    }

    cout << end;
}