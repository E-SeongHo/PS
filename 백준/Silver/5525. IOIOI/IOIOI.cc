#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
string S;

/// 1 <= N <= 1000000, 2N+1 <= M <= 1000000
/// 1s

int calc(int n)
{
    int cnt = 0;
    while(n >= 2*N+1)
    {
        cnt++;
        n = n-2;
    }

    return cnt;
}

int main()
{
    cin >> N >> M >> S;

    string sub(2*N+1, 'I');

    int ret = 0;    
    vector<int> table(M+1);
    table[0] = 0;
    char prev = 'O';

    for(int i = 1; i < table.size(); i++)
    {
        if(S[i-1] != prev)
        {
            table[i] = table[i-1] + 1;
        }
        else
        {
            if(S[i-1] == 'I') table[i] = 1;
            else if(S[i-1] == 'O') table[i] = 0;

            ret += calc(table[i-1]);
        }
        prev = S[i-1];
    }

    ret += calc(table.back());
    
    cout << ret;

    return 0;
}