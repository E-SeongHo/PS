#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
int N, M;
vector<string> v;
unordered_map<string, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    v.reserve(N);

    for(int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        v.push_back(str);
        m.insert({str, i});
    }

    for(int i = 0; i < M; ++i)
    {
        string str;
        cin >> str;

        if(isalpha(str[0]))
        {
            cout << m[str] + 1 << "\n";
        }
        else
        {
            int idx = stoi(str);
            cout << v[idx-1] << "\n";
        }
    }
}
