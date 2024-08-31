#include <iostream>
#include <vector>
#include <string>

using namespace std;

string encrypted;

int main()
{
    cin >> encrypted;
    vector<int> dp(encrypted.size()+1);

    dp[0] = 1;
    dp[1] = encrypted[0] - '0' != 0;
    for(int i = 2; i < dp.size(); ++i)
    {
        if(encrypted[i-1] - '0' != 0)
        {
            dp[i] = (dp[i] + dp[i-1]) % 1000000;
        }
        if(encrypted[i-2] - '0' != 0 && 1 <= stoi(encrypted.substr(i-2, 2)) && stoi(encrypted.substr(i-2, 2)) <= 26)
        {
            dp[i] = (dp[i] + dp[i-2]) % 1000000;
        } 
    }

    cout << dp.back();

    return 0;
}