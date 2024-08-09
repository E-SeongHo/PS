#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;
int main()
{
    // 3:32
    cin >> n;
    v.resize(n+1);
    for(int i = 1; i < n+1; ++i)
    {
        int t, p;
        cin >> t >> p;
        v[i] = {t, p};
    }
    
    vector<int> selected(n+1);
    vector<int> unselected(n+1);
    for(int i = 1; i < n+1; ++i)
    {
        if(v[i].first + i - 1 <= n)
        {
            selected[i] = v[i].second;
            for(int j = 1; j < i; ++j)
            {
                if(v[j].first + j <= i)
                {
                    selected[i] = max(selected[i], selected[j] + v[i].second);
                }
            }
        }
        unselected[i] = max(selected[i-1], unselected[i-1]);
    }

    cout << max(unselected[n], selected[n]);

    // 4:08
    return 0;
}
