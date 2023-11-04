#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> P(N);

    for(int i = 0; i < N; ++i)
        cin >> P[i];

    sort(P.begin(), P.end());
    int sum = P[0];

    for(int i = 1; i < N; ++i)
    {
        P[i] += P[i-1];
        sum += P[i];
    }

    cout << sum;

    return 0;
}