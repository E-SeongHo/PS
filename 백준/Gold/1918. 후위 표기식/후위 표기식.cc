#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsAlphabet(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool OpCompare(char op1, char op2)
{   // pop op1 if true
    if(op1 == '+' || op1 == '-')
    {
        if(op2 == '*' || op2 == '/') return false;
        else return true;
    }
    else if(op1 == '*' || op1 == '/')
    {
        return true;
    }

    cout << "debug flag" << endl;
    return false;
}

int main()
{
    string exp;
    cin >> exp;
    vector<char> stack;

    string post;
    
    for(int i = 0; i < exp.length(); ++i)
    {
        char c = exp[i];

        if(IsAlphabet(c))
        {
            post.push_back(c);
            continue;
        }

        if(c == '(')
        {
            stack.push_back(c);
            continue;
        }

        if(c == ')')
        {
            while (stack.back() != '(')
            {
                post.push_back(stack.back());
                stack.pop_back();
            }
            stack.pop_back(); // '('
            continue;
        }

        // operators
        while(!stack.empty() && stack.back() != '(')
        {
            if(OpCompare(stack.back(), c))
            {
                post.push_back(stack.back());
                stack.pop_back();
            }
            else break;
        }
        stack.push_back(c);
    }

    while(!stack.empty())
    {
        post.push_back(stack.back());
        stack.pop_back();
    }

    cout << post;

    return 0;
}
