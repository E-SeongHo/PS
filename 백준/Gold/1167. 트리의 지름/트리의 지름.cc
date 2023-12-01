#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
using edge = pair<int, int>;

int V;
vector<vector<edge>> vertices;

void find_longest(vector<bool>& visited, int current, int cost, pair<int, int>& dest)
{
    visited[current] = true;
    bool flag = false;
    for(auto e : vertices[current])
    {
        if(!visited[e.first]) 
        {
            flag = true;
            find_longest(visited, e.first, cost + e.second, dest);
        }
    }
    if(!flag)
    {
        if(cost > dest.second)
        {
            dest.first = current;
            dest.second = cost;
        }
    }
}
int main()
{
    cin >> V;
    vertices.resize(V+1);
    cin.get();

    for(int i = 1; i < V+1; ++i)
    {
        string input;
        getline(cin, input);
        istringstream stream(input);
        vector<string> nums;

        while(getline(stream, input, ' '))
            nums.push_back(input);

        int vertex = stoi(nums[0]);
        for(int j = 1; j < nums.size()-2; j+=2)
        {
            int node, weight;
            node = stoi(nums[j]);
            weight = stoi(nums[j+1]);
            vertices[vertex].push_back({node, weight});
            vertices[node].push_back({vertex, weight});
        }
    }
    
    vector<bool> visited(V+1);
    pair<int, int> node;

    find_longest(visited, 1, 0, node);
    fill(visited.begin(), visited.end(), false);

    pair<int, int> ans;
    find_longest(visited, node.first, 0, ans); 

    cout << ans.second;

    return 0;
}