#include <iostream>
#include <string>
#include <list>

using namespace std;

string S;
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> S >> N;

    list<char> l;
    for(char c : S)
        l.push_back(c);
    auto cursor = l.end();

    for(int i = 0; i < N; ++i)
    {
        char op, c;
        cin >> op;

        switch(op)
        {
        case 'L': 
            if(cursor != l.begin()) --cursor;
            break;
        case 'D':
            if(cursor != l.end()) ++cursor;
            break;
        case 'B':
            if(cursor != l.begin()) cursor = l.erase(--cursor);
            break;
        case 'P':
            cin >> c;
            l.insert(cursor, c);
            break;
        }
    }

    for(char c : l)
        cout << c;

    return 0;
}