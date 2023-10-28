#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int N, M;
vector<int> buttons; // 0 ~ 9
int ret;
vector<int> digits;

int FindLeastBigger(int n)
{
    int most = buttons[0] != 0 ? buttons[0] : buttons[1];
    int others = buttons[0];

    int ret = 0;
    ret += most * pow(10, digits.size());
    for(int i = 0; i < digits.size(); ++i)
    {   
        ret += others * pow(10, digits.size()-1-i);
    }

    return ret;
}

int FindMostLesser(int n)
{
    int most = buttons[buttons.size()-1];

    int ret = 0;
    for(int i = 0; i < digits.size()-1; ++i)
    {
        ret += most * pow(10, digits.size()-2-i);
    }
    return ret;
}

void DFS(vector<int>& moved, int depth)
{
    if(depth == moved.size())
    {
        int sum = 0;
        for(int i = 0; i < depth; ++i)
        {
            sum += moved[i] * pow(10, depth-i-1);
        }
        
        //cout << sum << " " << abs(N-sum) + depth << endl;
        if(abs(N-sum) + depth < ret) ret = abs(N-sum) + depth;

        return;
    }

    for(int i = 0; i < buttons.size(); ++i)
    {
        moved[depth] = buttons[i];
        DFS(moved, depth+1);
    }
}


int main()
{
    cin >> N >> M;

    vector<bool> v(10, true);
    for(int i = 0; i < M; ++i)
    {
        int chanel;
        cin >> chanel;
        v[chanel] = false;
    }

    for(int i = 0; i < 10; ++i)
    {
        if(v[i]) buttons.push_back(i);
    }

    ret = abs(100-N);
    string s = to_string(N);
    for(int i = 0; i < s.length(); ++i)
    {
        digits.push_back(s[i]-'0');
    }

    if(buttons.size() == 0)
    {
        ret = abs(100-N);
    }
    else if(buttons.size() == 1 && buttons[0] == 0)
    {
        ret = min(ret, abs(N-0) + 1);
    }
    else
    {
        vector<int> moved(digits.size());
        DFS(moved, 0);

        int n = abs(FindLeastBigger(N)-N) + digits.size()+1;
        ret = min(ret, n);
        if(digits.size() > 1)
        {
            n = abs(FindMostLesser(N)-N) + digits.size()-1;
            ret = min(ret, n);
        }
    }

    cout << ret;
    return 0;
}