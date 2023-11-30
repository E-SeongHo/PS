#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<vector<int>> paper;

int get_blue(int y, int x)
{
    int sum = 0;
    if(x + 3 < M)
    {
        int horizontal = paper[y][x] + paper[y][x+1] + paper[y][x+2] + paper[y][x+3];
        sum = max(sum, horizontal);
    }
    if(x - 3 >= 0)
    {
        int horizontal = paper[y][x] + paper[y][x-1] + paper[y][x-2] + paper[y][x-3];
        sum = max(sum, horizontal);
    }
    if(y + 3 < N)
    {
        int vertical = paper[y][x] + paper[y+1][x] + paper[y+2][x] + paper[y+3][x];
        sum = max(sum, vertical);
    }
    if(y - 3 >= 0)
    {
        int vertical = paper[y][x] + paper[y-1][x] + paper[y-2][x] + paper[y-3][x];
        sum = max(sum, vertical);
    }

    return sum;
}

int get_yellow(int y, int x)
{
    int sum = 0;
    if(x+1 < M && y+1 < N)
    {
        int down_right = paper[y][x] + paper[y+1][x] + paper[y+1][x+1] + paper[y][x+1];
        sum = max(sum, down_right);
    }
    if(x+1 < M && y-1 >= 0)
    {
        int up_right = paper[y][x] + paper[y-1][x] + paper[y-1][x+1] + paper[y][x+1];
        sum = max(sum, up_right);
    }
    if(x-1 >= 0 && y+1 < N)
    {
        int down_left = paper[y][x] + paper[y+1][x] + paper[y+1][x-1] + paper[y][x-1];
        sum = max(sum, down_left);
    }
    if(x-1 >= 0 && y-1 >= 0)
    {
        int up_left = paper[y][x] + paper[y-1][x] + paper[y-1][x-1] + paper[y][x-1];
        sum = max(sum, up_left);
    }
    return sum;
}

int get_orange(int y, int x)
{
    int sum = 0;
    if(x+1 < M && y+2 < N)
    {
        int verticaldown_right = paper[y][x] + paper[y+1][x] + paper[y+2][x] + paper[y+2][x+1];
        sum = max(sum, verticaldown_right);
    }
    if(x-1 >= 0 && y+2 < N)
    {
        int verticaldown_left =  paper[y][x] + paper[y+1][x] + paper[y+2][x] + paper[y+2][x-1];
        sum = max(sum, verticaldown_left);
    }
    if(x+1 < M && y-2 >= 0)
    {
        int verticalup_right = paper[y][x] + paper[y-1][x] + paper[y-2][x] + paper[y-2][x+1];
        sum = max(sum, verticalup_right);
    }
    if(x-1 >= 0 && y-2 >= 0)
    {
        int verticalup_left = paper[y][x] + paper[y-1][x] + paper[y-2][x] + paper[y-2][x-1];
        sum = max(sum, verticalup_left);
    }
    if(x+2 < M && y-1 >= 0)
    {
        int horizontalright_up = paper[y][x] + paper[y][x+1] + paper[y][x+2] + paper[y-1][x+2];
        sum = max(sum, horizontalright_up);
    }
    if(x+2 < M && y+1 < N)
    {
        int horizontalright_down = paper[y][x] + paper[y][x+1] + paper[y][x+2] + paper[y+1][x+2];
        sum = max(sum, horizontalright_down);
    }
    if(x-2 >= 0 && y-1 >= 0)
    {
        int horizontalleft_up = paper[y][x] + paper[y][x-1] + paper[y][x-2] + paper[y-1][x-2];
        sum = max(sum, horizontalleft_up);
    }
    if(x-2 >= 0 && y+1 < N)
    {
        int horizontalleft_down = paper[y][x] + paper[y][x-1] + paper[y][x-2] + paper[y+1][x-2];
        sum = max(sum, horizontalleft_down);
    }
    return sum;
}
int get_green(int y, int x)
{
    int sum = 0;
    if(x+1 < M && y+2 < N)
    {
        int down_right = paper[y][x] + paper[y+1][x] + paper[y+1][x+1] + paper[y+2][x+1];
        sum = max(sum, down_right);
    }
    if(x-1 >= 0 && y+2 < N)
    {
        int down_left = paper[y][x] + paper[y+1][x] + paper[y+1][x-1] + paper[y+2][x-1];
        sum = max(sum, down_left);
    }
    if(x+1 < M && y-2 >= 0)
    {
        int up_right = paper[y][x] + paper[y-1][x] + paper[y-1][x+1] + paper[y-2][x+1];
        sum = max(sum, up_right);
    }
    if(x-1 >= 0 && y-2 >= 0)
    {
        int up_left = paper[y][x] + paper[y-1][x] + paper[y-1][x-1] + paper[y-2][x-1];
        sum = max(sum, up_left);
    }
    if(x+2 < M && y-1 >= 0)
    {
        int right_up = paper[y][x] + paper[y][x+1] + paper[y-1][x+1] + paper[y-1][x+2];
        sum = max(sum, right_up);
    }
    if(x+2 < M && y+1 < N)
    {
        int right_down = paper[y][x] + paper[y][x+1] + paper[y+1][x+1] + paper[y+1][x+2];
        sum = max(sum, right_down);
    }
    if(x-2 >= 0 && y-1 >= 0)
    {
        int left_up = paper[y][x] + paper[y][x-1] + paper[y-1][x-1] + paper[y-1][x-2];
        sum = max(sum, left_up);
    }
    if(x-2 >= 0 && y+1 < N)
    {
        int left_down = paper[y][x] + paper[y][x-1] + paper[y+1][x-1] + paper[y+1][x-2];
        sum = max(sum, left_down);
    }
    return sum;
}
int get_pink(int y, int x)
{
    int sum = 0;
    if(x+2 < M && y+1 < N)
    {
        int right_down = paper[y][x] + paper[y][x+1] + paper[y][x+2] + paper[y+1][x+1];
        sum = max(sum, right_down);
    }
    if(x+2 < M && y-1 >= N)
    {
        int right_up = paper[y][x] + paper[y][x+1] + paper[y][x+2] + paper[y-1][x+1];
        sum = max(sum, right_up);
    }
    if(x-2 >= 0 && y+1 < N)
    {
        int left_down = paper[y][x] + paper[y][x-1] + paper[y][x-2] + paper[y+1][x-1];
        sum = max(sum, left_down);
    }
    if(x-2 >= 0 && y-1 >= 0)
    {
        int left_up = paper[y][x] + paper[y][x-1] + paper[y][x-2] + paper[y-1][x-1];
        sum = max(sum, left_up);
    }
    if(x+1 < M && y+2 < N)
    {
        int down_right = paper[y][x] + paper[y+1][x] + paper[y+2][x] + paper[y+1][x+1];
        sum = max(sum, down_right);
    }
    if(x-1 >= 0 && y+2 < N)
    {
        int down_left = paper[y][x] + paper[y+1][x] + paper[y+2][x] + paper[y+1][x-1];
        sum = max(sum, down_left);
    }
    if(x+1 < M && y-2 >= 0)
    {
        int up_right = paper[y][x] + paper[y-1][x] + paper[y-2][x] + paper[y-1][x+1];
        sum = max(sum, up_right);
    }
    if(x-1 >= 0 && y-2 >= 0)
    {
        int up_left = paper[y][x] + paper[y-1][x] + paper[y-2][x] + paper[y-1][x-1];
        sum = max(sum, up_left);
    }
    return sum;
}

int main()
{
    cin >> N >> M;
    paper.resize(N, vector<int>(M));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> paper[i][j];

    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            ans = max(ans, get_blue(i, j));
            ans = max(ans, get_yellow(i, j));
            ans = max(ans, get_orange(i, j));
            ans = max(ans, get_green(i, j));
            ans = max(ans, get_pink(i, j));
        }
    }

    cout << ans;

    return 0;
}