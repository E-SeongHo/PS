#include <iostream>
#include <vector>

using namespace std;

enum Surface
{
    Etop, 
    Ebottom,
    Eright,
    Eleft,
    Efront,
    Erear
};

vector<int> Dice = {0, 0, 0, 0, 0, 0};

int N, M, K;
int Y, X;
vector<vector<int>> Map;

vector<int> dy = {0, 0, -1, +1};
vector<int> dx = {+1, -1, 0, 0};

void roll_dice(int direction)
{
    int temp = Dice[Etop];

    switch(direction)
    {
    case 1: // right
        Dice[Etop] = Dice[Eleft];
        Dice[Eleft] = Dice[Ebottom];
        Dice[Ebottom] = Dice[Eright];
        Dice[Eright] = temp;
        break;
    case 2: // left
        Dice[Etop] = Dice[Eright];
        Dice[Eright] = Dice[Ebottom];
        Dice[Ebottom] = Dice[Eleft];
        Dice[Eleft] = temp;
        break;
    case 3: // upward
        Dice[Etop] = Dice[Efront];
        Dice[Efront] = Dice[Ebottom];
        Dice[Ebottom] = Dice[Erear];
        Dice[Erear] = temp;
        break;
    case 4 : // downward
        Dice[Etop] = Dice[Erear];
        Dice[Erear] = Dice[Ebottom];
        Dice[Ebottom] = Dice[Efront];
        Dice[Efront] = temp;
        break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> Y >> X >> K;
    Map.resize(N, vector<int>(M));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> Map[i][j];

    for(int k = 0; k < K; ++k)
    {
        int dir;
        cin >> dir;

        int ny = Y + dy[dir-1];
        int nx = X + dx[dir-1];
        if(ny >= 0 && ny < N && nx >= 0 && nx < M)
        {
            roll_dice(dir);
            Y = ny;
            X = nx;

            if(Map[Y][X]) 
            {
                Dice[Ebottom] = Map[Y][X];
                Map[Y][X] = 0;
            }
            else
            {
                Map[Y][X] = Dice[Ebottom];
            }

            cout << Dice[Etop] << '\n';
        }
    }
    
    return 0;
}