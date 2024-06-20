#include <iostream>
#include <vector>

#define SENTINAL 9999999

using namespace std;

int N, S;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> S;
    V.resize(N);

    for(int i = 0; i < N; i++)
    {
        cin >> V[i];
    }

    int ptr = 0;
    int qtr = -1;
    int sum = 0;
    int len = SENTINAL;

    while(qtr < N)
    {
        if(sum < S)
        {
            // sum += V[++qtr] // array index 
            if(++qtr >= N) break;

            sum += V[qtr];
        }
        else
        {
            len = min(len, qtr - ptr + 1);
            sum -= V[ptr++];
        }
    }

    len == SENTINAL ? cout << 0 : cout << len;

    return 0;
}