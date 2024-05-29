#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
string S;

/// 1 <= N <= 1000000, 2N+1 <= M <= 1000000
/// 1s

int main()
{
    cin >> N >> M >> S;

    string sub(2*N+1, 'I');
    for(int i = 1; i < sub.size(); i+=2)
    {
        sub[i] = 'O';
    }

    int cnt = 0;
    for(int i = 0; i < M-sub.size()+1; i++)
    {
        if(S.substr(i, sub.size()) == sub)
        {
            cnt++;
        }
    }  

    cout << cnt;

    return 0;
}