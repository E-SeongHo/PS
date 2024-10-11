#include <iostream>
#include <vector>
#include <string>

using namespace std;

string S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> S;

    vector<string> maxMK;
    vector<string> minMK;

    maxMK.push_back(string(1, S[0]));
    minMK.push_back(string(1, S[0]));

    for(int i = 1; i < S.length(); ++i)
    {
        if(S[i] == 'M')
        {
            if(S[i-1] == 'M')
            {
                maxMK.push_back("M");
                minMK[minMK.size()-1] = minMK.back() + "M";
            }
            else
            {
                maxMK.push_back("M");
                minMK.push_back("M");
            }
        }
        else
        {
            if(S[i-1] == 'M')
            {
                int cnt = 0;
                while(!maxMK.empty() && maxMK.back() == "M")
                {
                    cnt++;
                    maxMK.pop_back();
                }
                maxMK.push_back(string(cnt, 'M') + "K");
                minMK.push_back("K");
            }
            else
            {
                maxMK.push_back("K");
                minMK.push_back("K");
            }
        }
    }

    string maxParsed;
    for(string s : maxMK) 
    {
        if(s.back() == 'K')
        {
            maxParsed = maxParsed + "5" + string(s.length()-1, '0');
        }
        else
        {
            maxParsed = maxParsed + "1" + string(s.length()-1, '0');
        }
    }
    cout << maxParsed << '\n';

    string minParsed;
    for(string s : minMK) 
    {
       if(s.back() == 'K')
        {
            minParsed = minParsed + "5" + string(s.length()-1, '0');
        }
        else
        {
            minParsed = minParsed + "1" + string(s.length()-1, '0');
        }
    }
    cout << minParsed << '\n';

    return 0;
}
