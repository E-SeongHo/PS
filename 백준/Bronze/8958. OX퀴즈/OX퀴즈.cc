#include <iostream>
#include <string>

using namespace std;

int T;
string result;

int main()
{
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cin >> result;
        int cnt = 0;
        int score = 0;
        
        for(int i = 0; i < result.size(); i++)
        {
            if(result[i] == 'O') cnt++;
            else cnt = 0;

            score += cnt;
        }

        cout << score << "\n";
    }

    return 0;
}