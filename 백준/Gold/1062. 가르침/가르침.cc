#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
vector<string> Words;
int MaxWords = 0;

string Alphabets = "bdefghjklmopqrsuvwxyz";
vector<bool> Has(26, false);

void dfs(int cur, int dep)
{   
    if(dep == K-5)
    {
        int cnt = 0;
        for(string& word : Words)
        {
            bool flag = false;
            for(char c : word)
            {
                if(!Has[c-'a'])
                {
                    flag = true;
                    break;
                }
            }

            if(!flag) cnt++;
        }

        MaxWords = max(MaxWords, cnt);
        return;
    }

    for(int i = cur; i < 21; ++i)
    {
        Has[Alphabets[i] - 'a'] = true;
        dfs(i+1, dep+1);
        Has[Alphabets[i] - 'a'] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    Words.resize(N);

    for(int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;
        Words[i] = temp.substr(4, temp.length()-8);
    }

    if(K >= 5)
    {
        Has['a'-'a'] = Has['n'-'a'] = Has['t'-'a'] = Has['i'-'a'] = Has['c'-'a'] = true;
        dfs(0, 0);
    }

    cout << MaxWords;
    return 0;
}