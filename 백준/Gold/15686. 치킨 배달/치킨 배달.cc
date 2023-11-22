#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<vector<int>> mDist;
int ans = 987654321;

void Func(vector<int>& stores, vector<bool>& visited)
{
    if(stores.size() == M)
    {   
        int dists = 0;
        for(int i = 0; i < houses.size(); ++i)
        {
            int dist = 987654321;
            for(auto idx : stores)
            {
                dist = min(mDist[i][idx], dist);
            }
            dists += dist;
        }
        ans = min(ans, dists);
        return;
    }   

    for(int i = 0; i < chickens.size(); ++i)
    {   
        if(!stores.empty() && stores.back() > i) continue;
        if(!visited[i]) 
        {
            stores.push_back(i);
            visited[i] = true;
            Func(stores, visited);
            stores.pop_back();
            visited[i] = false;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            int n;
            cin >> n;
            if(n == 1) houses.push_back({i, j});
            if(n == 2) chickens.push_back({i, j});
        }
    }
    
    mDist.resize(houses.size(), vector<int>(chickens.size()));
    for(int i = 0; i < houses.size(); ++i)
    {
        auto h = houses[i];
        for(int j = 0; j < chickens.size(); ++j)
        {
            auto c = chickens[j];
            int d = abs(h.first - c.first) + abs(h.second - c.second);
            mDist[i][j] = d;
        }
    }


    vector<int> stores;
    vector<bool> visited(chickens.size());
    Func(stores, visited);
    
    cout << ans;
    return 0;
}