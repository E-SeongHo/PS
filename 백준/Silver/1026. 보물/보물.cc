#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A, B;

int main()
{
    cin >> N;
    A.resize(N);
    B.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> A[i];
    for(int i = 0; i < N; ++i)
        cin >> B[i];


    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int S = 0;

    for(int i = 0; i < N; ++i)
        S += A[i] * B[N-i-1];

    cout << S;
    return 0;
}