#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, T;
vector<int> A, B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    
    cin >> M;
    B.resize(M);
    for(int i = 0 ; i < M; ++i)
        cin >> B[i];

    vector<long long> prefixA(N+1);
    vector<long long> prefixB(M+1);

    for(int i = 1; i < N+1; ++i)
        prefixA[i] = A[i-1] + prefixA[i-1];

    for(int i = 1; i < M+1; ++i)
        prefixB[i] = B[i-1] + prefixB[i-1];

    vector<long long> sA, sB;
    for(int i = 1; i < N+1; ++i)
        for(int j = i; j < N+1; ++j)
            sA.push_back(prefixA[j] - prefixA[i-1]);

    for(int i = 1; i < M+1; ++i)
        for(int j = i; j < M+1; ++j)
            sB.push_back(prefixB[j] - prefixB[i-1]);

    long long ans = 0;
    sort(sB.begin(), sB.end());
    for(int i = 0; i < sA.size(); ++i)
    {
        long long key = T - sA[i];
        long long cnt = upper_bound(sB.begin(), sB.end(), key) - lower_bound(sB.begin(), sB.end(), key);

        ans += cnt;
    }

    cout << ans;

    return 0;
}