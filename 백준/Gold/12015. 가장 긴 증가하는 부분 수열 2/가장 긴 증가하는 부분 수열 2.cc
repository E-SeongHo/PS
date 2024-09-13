#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N+1);

    for(int i = 1; i < N+1; ++i)
        cin >> A[i];
    
    vector<int> lis;
    lis.push_back(A[1]);

    int ans = 0;
    for(int i = 2; i < N+1; ++i)
    {
        int idx = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
        
        if(idx == lis.size()) lis.push_back(A[i]);
        else lis[idx] = A[i];
    }

    cout << lis.size();

    return 0;
}