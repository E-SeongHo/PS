#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums;

void dfs(vector<int>& arr, int current)
{
    if(arr.size() == M) 
    {
        for(auto n : arr) cout << n << " ";
        cout << "\n";
        return;
    }

    for(int i = current; i < N; i++)
    {
        arr.push_back(nums[i]);
        dfs(arr, i);
        arr.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end());
    vector<int> arr;
    dfs(arr, 0);

    return 0;
}