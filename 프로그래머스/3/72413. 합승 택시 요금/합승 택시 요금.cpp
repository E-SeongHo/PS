#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // 11:08
    
    vector<vector<int>> map(n+1, vector<int>(n+1, 99999999));
    for(int i = 0; i < fares.size(); i++)
    {
        int a = fares[i][0]; int b = fares[i][1]; 
        int weight = fares[i][2];
        
        map[a][b] = weight;
        map[b][a] = weight;
    }
    for(int i = 1; i < n+1; i++)
    {
        map[i][i] = 0;
    }
    
    for(int k = 1; k < n+1; k++)
    {
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    
    int answer = map[s][a] + map[s][b];
    
    for(int i = 1; i < n+1; i++)
    {
        answer = min(answer, map[s][i] + map[i][a] + map[i][b]);
    }
    
    // 11:30
    return answer;
}