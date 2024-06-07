#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
vector<int> visited;

int main()
{
    cin >> N >> K;
    visited.resize(200000, 99999999);

    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = 0;

    int time = 999999999;
    int cnt = 0;

    while(!q.empty())
    {
        auto p = q.front(); q.pop();
        int current = p.first;
        int second = p.second;

        if(second > time) break;
        if(current == K) 
        {
            if(second < time) time = second;
            cnt++;
            continue;
        }

        if(current - 1 >= 0 && second+1 <= visited[current-1])
        {
            q.push({current-1, second+1});
            visited[current-1] = second+1;
        }
        if(current + 1 < 200000 && second+1 <= visited[current+1])
        {
            q.push({current+1, second+1});
            visited[current+1] = second+1;
        }
        if(current * 2 < 200000 && second+1 <= visited[current*2])
        {
            q.push({current*2, second+1});
            visited[current*2] = second+1;
        }
    }

    cout << time << '\n' << cnt;

    return 0;
}