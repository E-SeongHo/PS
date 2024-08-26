#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int N, M;
vector<long long> Cards;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    Cards.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> Cards[i];

    // O(M * NlogN)
    for(int i = 0; i < M; ++i)
    {
        sort(Cards.begin(), Cards.end());

        long long sum = Cards[0] + Cards[1];
        Cards[0] = sum;
        Cards[1] = sum;
    }
    
    cout << accumulate(Cards.begin(), Cards.end(), 0ll);

    return 0;
}