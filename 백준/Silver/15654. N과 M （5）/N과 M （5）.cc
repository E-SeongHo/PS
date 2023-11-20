#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
vector<bool> visited;

int N, M;

void DFS(vector<bool>& visited, vector<int>& v, int depth)
{
    if(depth == M)
    {
        for(auto n : v)
            cout << n << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; ++i)
    {
        if(!visited[i])
        {
            visited[i] = true;
            v.push_back(arr[i]);
            DFS(visited, v, depth+1);
            v.pop_back();
            visited[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    arr.resize(N);
    visited.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < N; ++i)
    {
        vector<int> route;
        route.push_back(arr[i]);
        visited[i] = true;
        DFS(visited, route, 1);
        visited[i] = false;
        route.pop_back();
    }
    return 0;
}