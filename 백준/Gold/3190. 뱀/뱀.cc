#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int N, K, L;
vector<vector<int>> Map;
queue<pair<int, char>> Directions;

// CCW(positive)
vector<int> dy = {0, -1, 0, +1};
vector<int> dx = {+1, 0, -1, 0};

#define SNAKE 2
#define APPLE 1
#define EMPTY 0

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    Map.resize(N, vector<int>(N, 0));

    for(int i = 0; i < K; ++i)
    {
        int y, x;
        cin >> y >> x;
        Map[y-1][x-1] = APPLE;
    }

    cin >> L;
    for(int i = 0; i < L; ++i)
    {
        int time; 
        char direction;
        cin >> time >> direction;
        Directions.push({time, direction});
    }

    Map[0][0] = SNAKE;
    int time = 0;
    int direction = 0;
    
    deque<pair<int, int>> snake;
    snake.push_back({0, 0});

    while(true)
    {
        time++;
        int head_y = snake.back().first + dy[direction];
        int head_x = snake.back().second + dx[direction];

        if(head_y < 0 || head_y >= N || head_x < 0 || head_x >= N || Map[head_y][head_x] == SNAKE)
            break;

        if(Map[head_y][head_x] == EMPTY)
        {
            int tail_y = snake.front().first;
            int tail_x = snake.front().second;

            Map[tail_y][tail_x] = EMPTY;
            snake.pop_front();
        }
        Map[head_y][head_x] = SNAKE;
        snake.push_back({head_y, head_x});

        if(Directions.front().first == time)
        {
            if(Directions.front().second == 'L')
            {
                direction++;
                direction = direction % 4;
            }
            else
            {
                direction--;
                if(direction < 0) direction = 3;
            }
            Directions.pop();
        }
    }

    cout << time;

    return 0;
}