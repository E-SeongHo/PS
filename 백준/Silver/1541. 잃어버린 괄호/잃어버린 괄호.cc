#include <iostream>
#include <string>

using namespace std;
int main()
{
    string expr;
    cin >> expr;

    int sum = 0;
    char prev = '+';
    string number;
    
    int i = 0;
    while( i < expr.length() )
    {
        if(isdigit(expr[i]))
        {
            number.push_back(expr[i]);
        }
        else
        {
            int num = stoi(number);
            number.clear();
            
            if(prev == '+') sum += num;
            else sum -= num;

            if(expr[i] == '-')  prev = '-';
        }
        i++;
    }

    int num = stoi(number);
    if(prev == '+') sum += num;
    else sum -= num;
        
    cout << sum;

    return 0;
}