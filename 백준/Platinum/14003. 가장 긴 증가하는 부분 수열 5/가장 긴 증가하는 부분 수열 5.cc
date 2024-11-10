#include <iostream>
#include <vector>

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

    vector<int> length;
    vector<int> index(N, -1);
    
    length.push_back(V[0]);
    index[0] = 0;

    for(int i = 1; i < N; ++i)
    {
        auto it = lower_bound(length.begin(), length.end(), V[i]);
        if(it == length.end()) 
        {
            length.push_back(V[i]);
            index[i] = length.size()-1;
        }
        else 
        {
            *it = V[i];
            index[i] = it - length.begin();
        }
    }

    vector<int> lis;
    for(int i = N-1; i >= 0; --i)
    {
        if(index[i] == (length.size() - lis.size() - 1))
        {
            lis.push_back(V[i]);
        }
    }

    cout << lis.size() << '\n';
    for(auto it = lis.rbegin(); it != lis.rend(); ++it)
        cout << *it << " ";

    return 0;
}
