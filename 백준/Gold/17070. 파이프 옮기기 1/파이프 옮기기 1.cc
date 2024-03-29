#include <iostream>
#include <vector>

using namespace std;

enum class PipeState
{
    Horizontal,
    Vertical,
    Diagonal
};

int N;
vector<vector<int>> house;

using pipe = pair<pair<int, int>, PipeState>;

int cnt = 0;

void dfs(pipe current)
{
    PipeState state = current.second;
    auto pos = current.first;
    int y = pos.first;
    int x = pos.second;

    bool flag = false;
    switch(state)
    {
    case PipeState::Horizontal:
        if(y == N-1 && x == N-2) flag = true;
        break;
    case PipeState::Vertical:
        if(y == N-2 && x == N-1) flag = true;
        break;
    case PipeState::Diagonal:
        if(y == N-2 && x == N-2) flag = true;
        break;
    }
    if(flag) 
    {
        cnt++;
        return;
    }

    switch(state)
    {
    case PipeState::Horizontal:
        if(x+2 < N && !house[y][x+2])
            dfs(pipe({{y, x+1}, PipeState::Horizontal}));
        if(x+2 < N && y+1 < N)
        {
            if(!house[y][x+2] && !house[y+1][x+2] && !house[y+1][x+1])
                dfs(pipe({{y, x+1}, PipeState::Diagonal}));
        }
        break;
    case PipeState::Vertical:
        if(y+2 < N && !house[y+2][x])
            dfs(pipe({{y+1}, x}, PipeState::Vertical));
        if(y+2 < N && x+1 << N)
        {
            if(!house[y+2][x] && !house[y+2][x+1] && !house[y+1][x+1])
                dfs(pipe({{y+1, x}, PipeState::Diagonal}));
        }
        break;
    case PipeState::Diagonal:
        if(x+2 < N && !house[y+1][x+2])
            dfs(pipe({{y+1, x+1}, PipeState::Horizontal}));
        if(y+2 < N && !house[y+2][x+1])
            dfs(pipe({{y+1, x+1}, PipeState::Vertical}));
        if(y+2 < N && x+2 < N)
        {
            if(!house[y+2][x+1] && !house[y+2][x+2] && !house[y+1][x+2])
                dfs(pipe({{y+1, x+1}, PipeState::Diagonal}));
        }
        break;
    }

}

int main()
{
    cin >> N;
    house.resize(N, vector<int>(N));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> house[i][j];

    dfs(pipe({{0, 0}, PipeState::Horizontal}));

    cout << cnt;
    return 0;
}