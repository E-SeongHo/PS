#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string S, P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> S >> P;
    
    strstr(S.c_str(), P.c_str()) ? cout << 1 : cout << 0;

    return 0;
}
