#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    //if(s2.length() > s1.length()) swap(s1, s2);
    vector<vector<int>> dp(s2.size()+1, vector<int>(s1.size()+1));

    for(int i = 1; i < s2.size()+1; ++i)
    {
        char ci = s2[i-1];
        for(int j = 1; j < s1.size()+1; ++j)
        {
            char cj = s1[j-1];
            if(ci == cj) dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j-1]);
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            dp[i][j] = min(dp[i][j], i+1);
        }
    }

    cout << dp[s2.size()][s1.size()];
    return 0;
}