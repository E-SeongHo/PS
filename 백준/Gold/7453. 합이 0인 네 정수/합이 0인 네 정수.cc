#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> A, B, C, D;

int main()    
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    A.resize(N); B.resize(N); C.resize(N); D.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    
    vector<long long> AB(N*N);
    vector<long long> CD(N*N);

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            AB[i*N+j] = A[i] + B[j];
            CD[i*N+j] = C[i] + D[j];
        }
    }
    
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long cnt = 0;
    for(int i = 0; i < AB.size(); ++i)
    {
        cnt += upper_bound(CD.begin(), CD.end(), -AB[i]) - lower_bound(CD.begin(), CD.end(), -AB[i]);
    }


    cout << cnt;
    return 0;
}