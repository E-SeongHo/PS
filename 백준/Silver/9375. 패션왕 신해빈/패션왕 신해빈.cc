#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(vector<int>& v, vector<bool>& check, int current, int& sum)
{
    if(current == v.size()) 
    {
        vector<int> valid;
        for(int i = 0; i < v.size(); i++)
        {
            if(check[i]) valid.push_back(v[i]);
        }

        if(valid.size())
        {
            int calc = 1;
            for(auto n : valid) calc *= n;
            
            sum += calc;
        }
        return;
    }

    check[current] = true;
    dfs(v, check, current+1, sum);
    check[current] = false;
    dfs(v, check, current+1, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++)
    {
        int N;
        cin >> N;

        map<string, int> map;

        for(int i = 0; i < N; i++)
        {
            string name, category;
            cin >> name >> category;
            
            map[category]++;
        }

        // vector<int> parsed;
        // for(auto c : map)
        // {
        //     parsed.push_back(c.second);
        // }
        
        // int sum = 0;
        // vector<bool> check(parsed.size(), false);
        // dfs(parsed, check, 0, sum);

        int sum = 1;
        for(auto c : map)
        {
            sum *= c.second+1;
        }
        sum = sum-1;

        cout << sum << "\n";
    }

    return 0;
}