#include <iostream>
#include <vector>

using namespace std;

int N;

bool Check(int x, int y, vector<pair<int, int>>& exist)
{
    for(auto e : exist)
    {
        if (e.first == x) return false;
        if ((e.first - e.second) == (x-y)) return false;
        if ((e.first + e.second) == (x+y)) return false;
    }
    return true;
}

void DFS(int depth, vector<pair<int, int>>& exist, int& cnt)
{
    for(int i = 0; i < N; ++i)
    {
        if(Check(i, depth, exist))
        {
            if(depth == N-1)
            {
                cnt++;
                return;
            }
            exist.push_back({i, depth});
            DFS(depth+1, exist, cnt);
            exist.pop_back();
        }
    }
}
int NQueen()
{
    int cnt = 0;
    for(int i = 0; i < N; ++i)
    {
        vector<pair<int, int>> exist;
        exist.push_back({i, 0});
        DFS(1, exist, cnt);
    }
    return cnt;
}
int main()
{
    cin >> N;

    if(N == 1) cout << 1;
    else cout << NQueen();

    return 0;
}