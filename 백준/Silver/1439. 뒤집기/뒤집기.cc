#include <iostream>
#include <vector>
#include <string>

using namespace std;

string S;

int main()
{
    cin >> S;

    int cnt_zeros = 0;
    int cnt_ones = 0;

    char prev = S[0];
    for(int i = 1; i < S.size(); ++i)
    {
        if(S[i] != prev)
        {
            prev == '0' ? cnt_zeros++ : cnt_ones++;
        }

        prev = S[i];
    }
    prev == '0' ? cnt_zeros++ : cnt_ones++;

    cout << min(cnt_zeros, cnt_ones);

    return 0;
}