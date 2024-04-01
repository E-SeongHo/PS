#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums;

void dfs(vector<int>& ans, int current)
{
    if(ans.size() == M)
    {
        for(auto n : ans)
            cout << n << " ";
        cout << "\n";        
        return;
    }

    for(int i = current; i < N; i++)
    {
        if(i > 0 && nums[i] <= nums[i-1]) continue;
        
        ans.push_back(nums[i]);
        dfs(ans, i);
        ans.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    nums.resize(N);

    for(int i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    vector<int> ans;
    dfs(ans, 0);

    return 0;
}