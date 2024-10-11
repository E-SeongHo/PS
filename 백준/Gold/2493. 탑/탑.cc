#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    V.reserve(N);
    vector<int> ans(N);

    for(int i = 0; i < N; ++i)
    {
        int height;
        cin >> height;

        int receiver = 0;
        while(!V.empty())
        {
            if(V.back().second >= height)
            {
                receiver = V.back().first;
                break;
            }
            else V.pop_back();
        }
        
        ans[i] = receiver;
        V.push_back({i+1, height});
    }

    for(int receiver : ans)
        cout << receiver << " ";
    
    return 0;
}
