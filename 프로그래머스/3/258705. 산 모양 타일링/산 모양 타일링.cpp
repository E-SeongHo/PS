#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> tops) {
    
    vector<tuple<int, int, int, int>> dp(n);
    
    dp[0] = {1, 1, 1, 1};
    if(!tops[0]) get<2>(dp[0]) = 0;
    
    for(int i = 1; i < n; i++)
    {
        auto [a, b, c, d] = dp[i-1];
        dp[i] = {(a+b+c+d) % 10007, (a+b+c) % 10007, (a+b+c+d) % 10007, (a+b+c+d) % 10007};
        
        if(!tops[i]) get<2>(dp[i]) = 0;
    }
    
    auto [a, b, c, d] = dp[n-1];
    
    return (a + b + c + d) % 10007;
}