#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<vector<int>> mDist;
int ans = 2e9;

int ChickenDist(vector<int>& stores)
{
    int dists = 0;
    for(int i = 0; i < houses.size(); ++i)
    {
        int dist = 2e9;
        for(auto idx : stores)
        {
            dist = min(mDist[i][idx], dist);
        }
        dists += dist;
    }
    return dists;
}

void Select(vector<int>& stores, int ptr)
{
    if(stores.size() == M)
    {   
        int dist = ChickenDist(stores);
        ans = min(ans, dist);
        return;
    }   
    for(int i = ptr; i < chickens.size(); ++i)
    {   
        stores.push_back(i);
        Select(stores, i+1);
        stores.pop_back();
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
    
    // pre calc
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
    Select(stores, 0);
    
    cout << ans;
    return 0;
}