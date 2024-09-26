#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S;
int M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> S >> M;
    vector<char> left;
    vector<char> right;

    left.reserve(S.length());
    right.reserve(S.length());

    for(char c : S) left.push_back(c);

    for(int i = 0; i < M; ++i)
    {
        char op, c;
        cin >> op;

        switch(op)
        {
        case 'L': 
            if(!left.empty())
            {
                right.push_back(left.back());
                left.pop_back();
            }
            break;
        case 'D':
            if(!right.empty())
            {
                left.push_back(right.back());
                right.pop_back();
            }
            break;
        case 'B':
            if(!left.empty())
            {
                left.pop_back();
            }
            break;
        case 'P':
            cin >> c;
            left.push_back(c);
            break;
        }
    }

    for(char c : left) cout << c;
    for(auto it = right.rbegin(); it != right.rend(); ++it) cout << *it;

    return 0;
}