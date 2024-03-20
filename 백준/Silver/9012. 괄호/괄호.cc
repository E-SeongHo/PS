#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool IsVPS(string& s)
{
    stack<char> st;
    int count = 0;
    char c;
    for(int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    while(!st.empty())
    {
        c = st.top();
        if(c == '(') count--;
        else if(c == ')') count++;
        if(count < 0) 
        {
            return false;
        }
        st.pop();
    }
    if(count == 0) return true;
    else return false;
}

int main()
{
    int N;
    cin >> N;
    vector<bool> v(N,false);    

    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        if(IsVPS(temp)) v[i] = true;
    }
    for(int i = 0; i < N; i++)
    {
        if(v[i]) cout << "YES";
        else cout << "NO";
        cout << endl;
    }   

    return 0;
}