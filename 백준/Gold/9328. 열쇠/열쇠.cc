#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, H, W;
vector<vector<char>> Map;
vector<vector<bool>> Visited;

int Docs;
vector<int> HasKey(26, 0);
vector<vector<pair<int, int>>> WaitingKeys(26);

vector<int> dy = {-1, +1, 0, 0};
vector<int> dx = {0, 0, -1, +1};

bool is_key(char elem) { return ('a' <= elem && elem <= 'z'); }
bool is_door(char elem) { return ('A' <= elem && elem <= 'Z'); }
void get_key(char key) { HasKey[key - 'a']++; }
bool has_key(char door) { return HasKey[door-'A']; }

void search(queue<pair<int, int>>& q)
{
    while(!q.empty())
    {
        auto [cy, cx] = q.front(); q.pop();
        if(is_key(Map[cy][cx])) get_key(Map[cy][cx]);
        if(Map[cy][cx] == '$') { Docs++; }

        for(int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < H && nx >= 0 && nx < W && !Visited[ny][nx] && Map[ny][nx] != '*')
            {
                if(is_door(Map[ny][nx]) && !has_key(Map[ny][nx]))
                {
                    WaitingKeys[Map[ny][nx]-'A'].push_back({ny, nx});
                    continue;
                }

                Visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

int can_open_any()
{
    for(char door = 'A'; door <= 'Z'; door++)
    {
        if(!WaitingKeys[door-'A'].empty() && HasKey[door-'A']) return door-'A';
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cin >> H >> W;
        Map.resize(0); Map.resize(H, vector<char>(W));
        Visited.resize(0); Visited.resize(H, vector<bool>(W, false));
        WaitingKeys.resize(0); WaitingKeys.resize(26);
        fill(HasKey.begin(), HasKey.end(), 0);
        Docs = 0;

        vector<pair<int, int>> entrances;
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                cin >> Map[i][j];
                if(i == 0 || i == H-1 || j == 0 || j == W-1)
                {
                    if(Map[i][j] != '*') entrances.push_back({i, j});
                } 
            }
        }
        
        string keys;
        cin >> keys;
        if(keys != "0")
        {
            for(char key : keys) HasKey[key - 'a']++;
        }

        queue<pair<int, int>> q;
        for(auto [y, x] : entrances)
        {
            if(is_door(Map[y][x]) && !has_key(Map[y][x]))
            {
                WaitingKeys[Map[y][x]-'A'].push_back({y, x});
                continue;
            }
            Visited[y][x] = true;
            q.push({y, x});            
        }

        // marks the door requiring key (WaitingKeys[door])
        search(q);
        
        // go back to the door if have found the matching key
        while(true)
        {
            int can_open = can_open_any();
            if(can_open == -1) break;

            auto [jump_y, jump_x] = WaitingKeys[can_open].back();
            WaitingKeys[can_open].pop_back();

            Visited[jump_y][jump_x] = true;
            q.push({jump_y, jump_x});

            search(q);
        }

        cout << Docs << '\n';
    }
    return 0;
}
