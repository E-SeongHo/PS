#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> set;
vector<bool> visited;

void select(int depth)
{
    if(depth == M)
    {
        for(auto s : set)
            cout << s << " ";
        cout << "\n";
        return;
    }

    vector<int> used; 
    for(int i = 0; i < arr.size(); ++i)
    {
        if(!visited[i])
        {
            if( binary_search(used.begin(), used.end(), arr[i]) ) continue;
            set[depth] = arr[i];
            visited[i] = true;
            used.push_back(arr[i]);
            select(depth+1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        arr.push_back(n);
    }    

    visited.resize(N);

    sort(arr.begin(), arr.end());
    set.resize(M);
    select(0);

    return 0;
}