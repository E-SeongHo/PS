#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string lcs(string s1, string s2)
{
    // 첫 두 문자열에서 가능한 LCS가 여러개 있을 경우 어떤 걸 선택할지 결정할 수 없음
    if(s2.size() > s1.size()) swap(s1, s2);

    vector<vector<int>> dp(s2.size()+1, vector<int>(s1.size()+1));
    for(int i = 0; i < s2.size(); ++i)
    {
        for(int j = 0; j < s1.size(); ++j)
        {
            if(s2[i] == s1[j])
            {
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else
            {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    string lcs = "";
    int cur_y = s2.size();
    int cur_x = s1.size();
    while(dp[cur_y][cur_x])
    {
        if(dp[cur_y][cur_x] == dp[cur_y][cur_x-1])
        {
            --cur_x;
        }
        else if(dp[cur_y][cur_x] == dp[cur_y-1][cur_x])
        {
            --cur_y;
        }
        else 
        {
            lcs.push_back(s2[cur_y-1]);
            --cur_x; --cur_y;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    vector<vector<vector<int>>> dp(a.length()+1, vector<vector<int>>(b.length()+1, vector<int>(c.length()+1)));

    for(int i = 0; i < a.length(); ++i)
    {
        for(int j = 0; j < b.length(); ++j)
        {
            for(int k = 0; k < c.length(); ++k)
            {
                if(a[i] == b[j] && b[j] == c[k])
                {
                    dp[i+1][j+1][k+1] = dp[i][j][k] + 1;
                }
                else
                {
                    dp[i+1][j+1][k+1] = max({dp[i][j+1][k+1], dp[i+1][j][k+1], dp[i+1][j+1][k]});
                }
            }
        }
    }
    
    cout << dp[a.length()][b.length()][c.length()];

    return 0;
}