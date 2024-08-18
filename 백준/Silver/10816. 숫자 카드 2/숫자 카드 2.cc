#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int N, M;
vector<int> Cards;

int upperBound(int begin, int end, int key)
{
    if(begin > end) return begin;

    int mid = (begin + end) / 2;
    
    if(Cards[mid] > key) return upperBound(begin, mid-1, key);
    if(Cards[mid] <= key) return upperBound(mid+1, end, key);
}

int lowerBound(int begin, int end, int key)
{
    if(end < begin) return end+1;

    int mid = (begin + end) / 2;

    if(Cards[mid] >= key) return lowerBound(begin, mid-1, key);
    if(Cards[mid] < key) return lowerBound(mid+1, end, key);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    Cards.resize(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> Cards[i];
    }

    sort(Cards.begin(), Cards.end());

    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        int n;
        cin >> n;

        auto upper = upper_bound(Cards.begin(), Cards.end(), n);
        auto upper2 = upperBound(0, N-1, n);

        auto lower = lower_bound(Cards.begin(), Cards.end(), n);
        auto lower2 = lowerBound(0, N-1, n);

        assert(distance(lower, upper) == (upper2 - lower2));
        cout << distance(lower, upper) << " ";
    }

    return 0;
}