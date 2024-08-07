#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> Connections;
vector<int> Sales;
vector<long long> SelectedSum;
vector<long long> UnSelectedSum;

void dfs(int cur)
{
    if(Connections[cur].size() == 0)
    {
        SelectedSum[cur] = Sales[cur];
        UnSelectedSum[cur] = 0;
        return;
    }
    
    for(int node : Connections[cur])
    {
        dfs(node);
        SelectedSum[cur] += min(SelectedSum[node], UnSelectedSum[node]);
    }
    
    int minSum = 2147483647;
    for(int selected : Connections[cur])
    {
        int sum = SelectedSum[selected];
        for(int other : Connections[cur])
        {
            if(selected == other) continue;
            sum += min(SelectedSum[other], UnSelectedSum[other]);
        }
        
        minSum = min(minSum, sum);
    }
    
    SelectedSum[cur] = SelectedSum[cur] + Sales[cur];
    UnSelectedSum[cur] = minSum;
    //cout << cur << " " << SelectedSum[cur] << " " << UnSelectedSum[cur] << endl;
}

int solution(vector<int> sales, vector<vector<int>> links) 
{    
    Sales.resize(sales.size()+1);
    Connections.resize(sales.size()+1);
    SelectedSum.resize(sales.size()+1);
    UnSelectedSum.resize(sales.size()+1);
        
    for(int i = 0; i < sales.size(); i++)
        Sales[i+1] = sales[i];
    
    for(auto link : links)
        Connections[link[0]].push_back(link[1]);
    
    dfs(1);
    
    return min(SelectedSum[1], UnSelectedSum[1]);
}
