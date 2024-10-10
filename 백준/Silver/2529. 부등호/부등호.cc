#include <iostream>
#include <vector>

using namespace std;

int K;
vector<char> V;

long long Max = 0;
long long Min = 9999999999;

string SMax;
string SMin;

void dfs(string& s, vector<bool>& issued)
{
    int dep = s.length();

    if(dep == K+1)
    {
        long long val = stoll(s);
        if(val >= Max)
        {
            Max = val;
            SMax = s;
        }
        if(val <= Min)
        {
            Min = val;
            SMin = s;
        }
        return;
    }

    if(dep == 0)
    {
        for(int i = 0; i <= 9; ++i)
        {
            s.push_back(i+'0');
            issued[i] = true;
            dfs(s, issued);
            s.pop_back();
            issued[i] = false;
        }
    }
    else
    {
        int border = s.back() - '0';
        if(V[dep-1] == '<')
        {
            for(int i = border+1; i <= 9; ++i)
            {
                if(issued[i]) continue;

                issued[i] = true;
                s.push_back(i+'0');
                dfs(s, issued);
                s.pop_back();
                issued[i] = false;
            }
        }
        else
        {
            for(int i = border-1; i >= 0; --i)
            {
                if(issued[i]) continue;

                issued[i] = true;
                s.push_back(i+'0');
                dfs(s, issued);
                s.pop_back();
                issued[i] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> K;
    V.resize(K);
    for(int i = 0; i < K; ++i)
        cin >> V[i];

    string s;
    vector<bool> issued(10, false);
    dfs(s, issued);

    cout << SMax << '\n';
    cout << SMin << '\n';

    return 0;
}
