#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

using pp = pair<pair<int, int>, pair<int, int>>;
vector<pp> V;

void print(pp& p)
{
    cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    V.resize(N);
    for(int i = 0; i < N; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        V[i] = {{a, b}, {c, d}};
    }

    sort(V.begin(), V.end());

    pair<int, int> from = {3, 1};
    pair<int, int> to = {11, 30};    
    int ptr = -1;

    int cnt = 0;
    while(true)
    {
        int qtr = -1;
        pair<int, int> cover = {0, 0};

        for(int i = ptr+1; i < V.size(); ++i)
        {
            auto [f, t] = V[i];

            if(f > from) break;

            if(t > cover)
            {
                qtr = i;
                cover = t;
            }            
        }

        if(qtr == -1) 
        {
            cout << 0;
            break;
        }
        cnt++;

        if(cover > to)
        {
            cout << cnt;
            break;
        }

        ptr = qtr;
        from = V[qtr].second;
    }

    return 0;
}