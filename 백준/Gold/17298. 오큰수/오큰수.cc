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
    
    vector<int> right;
    vector<int> ans(N);
    for(int i = N-1; i >= 0; --i)
    {
        while(!right.empty() && right.back() <= V[i])
        {
            right.pop_back();
        }

        if(right.empty()) ans[i] = -1;
        else ans[i] = right.back();
        
        right.push_back(V[i]);
    }
    
    for(int i = 0; i < N; ++i) 
        cout << ans[i] << " ";

    return 0;
}

