#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string buffer;
    while(getline(cin, buffer))
    {
        if(buffer == ".") break;

        vector<char> stack;
        string result = "yes";

        for(auto ch : buffer)
        {
            if(result == "no") break;

            if(ch == '(' || ch == '[') stack.push_back(ch);
            else if(ch == ')')
            {
                if(stack.size() && stack.back() == '(') stack.pop_back();
                else result = "no";
            }       
            else if(ch == ']')
            {
                if(stack.size() && stack.back() == '[') stack.pop_back();
                else result = "no";
            }     
        }

        if(stack.size()) result = "no";

        cout << result << "\n";
    }

    return 0;
}