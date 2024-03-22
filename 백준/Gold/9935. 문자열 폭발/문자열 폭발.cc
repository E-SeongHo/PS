#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str, bomb;

int main()
{
    cin >> str >> bomb;

    string stack;

    for(int i = 0; i < str.size(); i++)
    {
        stack.push_back(str[i]);

        if(stack.back() == bomb.back() && stack.size() >= bomb.size())
        {
            if(stack.substr(stack.size()-bomb.size(), bomb.size()) == bomb)
            {
                for(int i = 0; i < bomb.size(); i++) stack.pop_back();
            }
        }
    }

    if(stack.empty()) cout << "FRULA";
    else cout << stack;

    return 0;
}