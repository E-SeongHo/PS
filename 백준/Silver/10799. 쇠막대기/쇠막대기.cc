#include <iostream>
#include <vector>
#include <string>

using namespace std;

string S;

int main()
{
    cin >> S;

    int open = 0;
    int cnt = 0;

    for(int i = 0; i < S.length(); ++i)
    {
        if(S[i] == '(') open++;
        if(S[i] == ')') 
        {
            open--;
            if(S[i-1] == '(') cnt += open;
            else cnt += 1;
        }
    }

    cout << cnt;

    return 0;
}