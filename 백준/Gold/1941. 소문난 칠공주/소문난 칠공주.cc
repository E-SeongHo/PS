#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> V(5, vector<char>(5));
int Cnt = 0;

vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};

bool can_visit_all(vector<int>& v)
{
    vector<bool> visited(7, false);
    queue<int> q;

    visited[0] = true;
    q.push(v[0]);

    while(!q.empty())
    {
        int n = q.front(); q.pop();
        int y = n/5;
        int x = n%5;

        //cout << n << " " << y << " " << x << ": " << endl;
        for(int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 0 && ny < 5 && nx >= 0 && nx < 5)
            {
                for(int j = 0; j < 7; ++j)
                {   
                    int jy = v[j]/5;
                    int jx = v[j]%5;
                    if(!visited[j] && jy == ny && jx == nx)
                    {
                        visited[j] = true;
                        q.push(v[j]);
                        break;
                        //cout << j << " " << jy << " " << jx << endl;
                    }
                }
            }
        }
    }

    for(int i = 0; i < 7; ++i)
    {
        //cout << visited[i] << " ";
        if(!visited[i]) return false;
    }

    return true;
}

void dfs(int start, vector<int>& v)
{
    if(v.size() == 7)
    {
        int S = 0;
        for(int n : v)
        {
            if(V[n/5][n%5] == 'S') S++;
        }

        if(S >= 4)
        {
            if(can_visit_all(v)) 
            {
                // for(int n : v) cout << n << " ";
                // cout << endl;
                Cnt++;
            }
        }
        
        return;
    }

    for(int i = start; i < 25; ++i)
    {
        v.push_back(i);
        dfs(i+1, v);
        v.pop_back();
    }
}
int main()
{
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            cin >> V[i][j];

    // vector<int> v = {2, 5, 6, 7, 8, 9, 12};
    // cout << can_visit_all(v);
    
    vector<int> v;
    dfs(0, v);

    cout << Cnt;

    return 0;
}