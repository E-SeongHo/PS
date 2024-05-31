#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T, N;
vector<string> v;
int dist;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cin >> N;
        v.resize(N);
        for(int n = 0; n < N; n++)
        {
            cin >> v[n];
        }
        dist = 9999999;

        if(N <= 32)
        {
            for(int i = 0; i < N; i++)
            {
                for(int j = i+1; j < N; j++)
                {
                    for(int k = j+1; k < N; k++)
                    {
                        int cnt = 0;
                        for(int l = 0; l < 4; l++)
                        {
                            if(v[i][l] != v[j][l]) cnt++;
                            if(v[i][l] != v[k][l]) cnt++;
                            if(v[j][l] != v[k][l]) cnt++;
                        }
                        dist = min(dist, cnt);
                    }
                }
            }
        }
        else dist = 0;

        cout << dist << "\n";
    }
    return 0;   
}