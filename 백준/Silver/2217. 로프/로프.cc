#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> Ropes;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    Ropes.resize(N);

    int weight = 0;
    for(int i = 0; i < N; ++i)
    {
        cin >> Ropes[i];
        weight += Ropes[i];
    }

    sort(Ropes.begin(), Ropes.end());

    int max_weight = 0;

    for(int i = 0; i < N; ++i)
    {
        max_weight = max(max_weight, Ropes[i] * (N-i));
    }

    cout << max_weight;
    
    return 0;
}