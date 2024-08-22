#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> Pos;
vector<int> Neg;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    Pos.reserve(N);
    Neg.reserve(N);

    int ans = 0;
    bool has_zero = false;
    for(int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        if(n > 0) 
        {
            if(n == 1) ans += n;
            else Pos.push_back(n);
        }
        else if(n < 0) Neg.push_back(n);
        else has_zero = true;
    }

    sort(Pos.begin(), Pos.end());
    sort(Neg.begin(), Neg.end(), greater<int>());

    int i = Pos.size() % 2 == 0 ? 0 : 1;
    for(i; i < (int)Pos.size()-1; i+=2)
    {
        ans += Pos[i]*Pos[i+1];
    }
    if(Pos.size() % 2 == 1) ans += Pos.front();

    i = Neg.size() % 2 == 0 ? 0 : 1;
    for(i; i < (int)Neg.size()-1; i+=2)
    {
        ans += Neg[i]*Neg[i+1];
    }
    if(Neg.size() % 2 == 1 && !has_zero) 
    {
        ans += Neg.front();
    }

    cout << ans;

    return 0;
}