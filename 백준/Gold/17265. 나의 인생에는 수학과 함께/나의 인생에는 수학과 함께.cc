#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> V;
vector<vector<bool>> Visited;

int Max = -99999999;
int Min = 99999999;

void dfs(int y, int x, int dep, int sum, char op)
{
    Visited[y][x] = true;
    if(dep % 2 == 0)
    {
        int cur = (V[y][x] - '0');
        if(op == '+') sum += cur;
        else if(op == '-') sum -= cur;
        else sum *= cur;
    }

    if(y == N-1 && x == N-1)
    {
        Max = max(Max, sum);
        Min = min(Min, sum);

        return;
    }

    char operation = dep % 2 == 1 ? V[y][x] : ' ';
    
    if(y+1 < N && x < N && !Visited[y+1][x])
    {
        dfs(y+1, x, dep+1, sum, operation);
        Visited[y+1][x] = false;
    }
    if(y < N && x+1 < N && !Visited[y][x+1])
    {
        dfs(y, x+1, dep+1, sum, operation);
        Visited[y][x+1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    V.resize(N, vector<char>(N));
    Visited.resize(N, vector<bool>(N, false));
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> V[i][j];

    dfs(0, 0, 0, 0, '+');

    cout << Max << " " << Min;

    return 0;
}
