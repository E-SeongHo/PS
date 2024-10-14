#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Text;
string Pattern;
vector<int> LSP;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    getline(cin, Text);
    getline(cin, Pattern);

    LSP.resize(Pattern.length());
    int k = 0;
    for(int i = 1; i < LSP.size(); ++i)
    {
        while(k && Pattern[i] != Pattern[k])
        {
            k = LSP[k-1];
        }

        if(Pattern[i] == Pattern[k])
        {
            k++;
        }

        LSP[i] = k;
    }

    vector<int> ans;
    k = 0;
    for(int i = 0; i < Text.size(); ++i)
    {
        while(k && Pattern[k] != Text[i])
        {
            k = LSP[k-1];
        }

        if(Pattern[k] == Text[i])
        {
            k++;
        }

        if(k == Pattern.length())
        {
            ans.push_back(i-k+2);
            k = LSP[k-1];
        }
    }

    cout << ans.size() << '\n';
    for(int n : ans) cout << n << " ";

    return 0;
}
