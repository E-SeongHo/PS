#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> Trees;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    Trees.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> Trees[i];

    int begin = 0;
    int end = 1000000001;

    while(begin + 1 < end)
    {
        int mid = (begin + end) / 2;

        long long sum = 0;
        for(auto height : Trees)
        {
            if(mid < height) sum += height - mid;
        }
        
        if(sum >= M) begin = mid;
        else end = mid;
    }
    
    cout << begin;
    return 0;
}