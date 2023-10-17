#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int>> v;
    string s;
    cin >> s;

    v.resize(26, vector<int>(s.size()+1));
    
    for(int i = 0; i < s.size(); ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            v[j][i+1] = v[j][i];
        }
        v[s[i]-'a'][i+1]++;
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; ++i)
    {
        char c; 
        int start, end;
        cin >> c >> start >> end;

        cout << v[c-'a'][end+1] - v[c-'a'][start] << "\n";
    }

    return 0;
}