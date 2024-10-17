#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int N;
vector<vector<int>> W, DP;
vector<vector<int>> Path;
constexpr int Start = 0;
constexpr int INF = 1000000000;

int pop_count(int bitmask)
{
    int cnt = 0;
    while(bitmask)
    {
        if(bitmask & 1) cnt++;
        bitmask = bitmask >> 1;
    }

    return cnt;
}

void path(vector<int>& v, int left)
{
    if(left == 0) 
    {
        v.push_back(Start);
        return;
    }

    v.push_back(Path[v.back()][left]);
    left = left & ~(1 << v.back());

    path(v, left);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;

    W.resize(N, vector<int>(N));
    DP.resize(N, vector<int>(1 << N));
    Path.resize(N, vector<int>(1 << N, -1));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> W[i][j];
            if(i != j && !W[i][j]) W[i][j] = INF;
        }
    }

    for(int i = 0; i < N; i++)
        DP[i][0] = W[i][Start];

    for(int k = 1; k <= N-2; k++)
    {
        // All subsets A(V - {Start}) containing k vertices
        for(int bitmask = 0; bitmask < (1 << N); bitmask++)
        {
            if((bitmask & (1 << Start)) == (1 << Start)) continue;
            if(pop_count(bitmask) != k) continue;

            for(int i = 0; i < N; ++i)
            {
                if(i == Start) continue; // important
                if((bitmask & (1 << i)) == (1 << i)) continue;

                DP[i][bitmask] = INF;
                Path[i][bitmask] = -1; // means from i ~ bitmask ~ i == i ~ j ~ bitmask - {j} ~ i
                for(int j = 0; j < N; ++j)
                {
                    // all j in bitmask
                    if((bitmask & (1 << j)) == (1 << j))
                    {
                        int prev = bitmask & ~(1 << j); // bitmask - {j}
                        if(W[i][j] + DP[j][prev] < DP[i][bitmask])
                        {
                            DP[i][bitmask] = W[i][j] + DP[j][prev];
                            Path[i][bitmask] = j;
                        }
                    }
                }
            }
        }
    }

    // A = V - {Start}
    int A = ((1<<N) - 1) & ~(1 << Start);
    
    DP[Start][A] = 0x7fffffff;
    for(int i = 0; i < N; i++)
    {
        if(i == Start) continue;
        int B = A & ~(1 << i);

        if(W[Start][i] + DP[i][B] < DP[Start][A])
        {
           DP[Start][A] = W[Start][i] + DP[i][B];
           Path[Start][A] = i;
        }
    }

    cout << DP[Start][A];

    // vector<int> v = {Start};
    // path(v, A);

    // for(int n : v) cout << n << " ";
}
