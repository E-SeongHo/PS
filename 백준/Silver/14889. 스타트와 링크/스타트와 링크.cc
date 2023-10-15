#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> S;
vector<bool> selected;

int diff = 2147483647;

void CalcScore()
{
    int a = 0;
    int b = 0;
    vector<int> A;
    vector<int> B;
    A.reserve(N/2);
    B.reserve(N/2);

    for(int i = 0; i < N; ++i)
    {
        if(selected[i])
            A.push_back(i);
        else
            B.push_back(i);
    }

    for(int i = 0; i < N/2; ++i)
    {
        for(int j = i+1; j < N/2; ++j)
        {
            a+= S[A[i]][A[j]] + S[A[j]][A[i]];
            b+= S[B[i]][B[j]] + S[B[j]][B[i]];
        }
    }

    diff = min(diff, abs(a-b));
}

void TeamMatch(int depth, int prev)
{
    if(depth == N/2)
    {
        CalcScore();
        return;
    }

    for(int i = prev; i < N; ++i)
    {
        if(!selected[i])
        {
            selected[i] = true;
            TeamMatch(depth + 1, i);
            selected[i] = false;
        }
    }
}

int main()
{
    cin >> N;
    S.resize(N, vector<int>(N));
    selected.resize(N);

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> S[i][j];
        }
    }

    TeamMatch(0, 0);

    cout << diff;

    return 0;
}