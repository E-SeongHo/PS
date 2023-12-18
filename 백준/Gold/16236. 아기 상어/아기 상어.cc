#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pos = pair<int, int>;
const int INF = 1987654321;

int N;
vector<vector<int>> map;
vector<vector<pos>> fishes(7);

pos sharkPos;
int sharkSize = 2;
int cnt = 0;
int time = 0;

vector<int> dx = {0, -1, +1, 0};
vector<int> dy = {-1, 0, 0, +1};

using element = pair<int, pos>;
struct cmp
{
    bool operator()(element& e1, element& e2)
    {
        if(e1.first == e2.first)
        {
            if(e1.second.first == e2.second.first)
                return e1.second.second > e2.second.second;
            else 
                return e1.second.first > e2.second.first;
        }
        else return e1.first > e2.first;
    }
};

bool select()
{
    // cout << sharkPos.first << " " << sharkPos.second << endl;

    vector<vector<int>> visited(N, vector<int>(N));

    priority_queue<element, vector<element>, cmp> pq;
    pq.push({0, sharkPos});
    visited[sharkPos.first][sharkPos.second] = 1;
    map[sharkPos.first][sharkPos.second] = 0;

    while(!pq.empty())
    {
        auto e = pq.top(); pq.pop();
        pos p = e.second;

        int y = p.first;
        int x = p.second;

        if(map[y][x] != 0 && map[y][x] < sharkSize) // can eat
        {
            map[y][x] = 0;
            time += visited[y][x] - 1;
            sharkPos = {y, x};
            cnt++;
            if(cnt == sharkSize) 
            {
                sharkSize = min(sharkSize+1, 7);
                cnt = 0;
            }
            return true;
        }
        for(int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 0 && ny < N && nx >= 0 && nx < N)  // can move
            {
                if(!visited[ny][nx] && map[ny][nx] <= sharkSize) // can pass
                {
                    visited[ny][nx] = visited[y][x] + 1;
                    pq.push({visited[ny][nx] - 1, {ny, nx}});
                }
            }
        }
    }
    return false;
}
int main()
{
    cin >> N;
    map.resize(N, vector<int>(N));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            int state;
            cin >> state;
            map[i][j] = state;
            if(state == 9) sharkPos = {i, j};
            else fishes[state].push_back({i, j});
        }

    while(select())
    {

    }

    cout << time << endl;

    return 0;
}