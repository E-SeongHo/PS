#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Requests;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    Requests.resize(N);
    
    for(int i = 0; i < N; ++i)
        cin >> Requests[i];

    cin >> M;

    int begin = 1;
    int end = *max_element(Requests.begin(), Requests.end()) + 1;
    while(begin + 1 < end)
    {
        int mid = (begin + end) / 2;

        int total = 0;
        for(int request : Requests)
        {
            if(mid > request) total += request;
            else total += mid;
        }

        if(total > M) end = mid;
        else begin = mid;
    }

    cout << begin;

    return 0;
}