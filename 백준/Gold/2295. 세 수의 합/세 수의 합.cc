#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    V.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];    

    sort(V.begin(), V.end());

    // O(N^2)
    vector<int> ts;
    ts.reserve(N*N);
    for(int i = 0; i < N; ++i)
        for(int j = i; j < N; ++j)
            ts.push_back(V[i]+V[j]);

    sort(ts.begin(), ts.end());
    
    for(int i = N-1; i >= 0; --i)
    {
        for(int j = i; j >= 0; --j)
        {
            int key = V[i] - V[j];
            if(binary_search(ts.begin(), ts.end(), key))
            {
                cout << V[i];
                return 0;
            }
        }
    }

    return 0;
}
