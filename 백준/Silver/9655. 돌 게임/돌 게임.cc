#include <iostream>
#include <vector>

using namespace std;

int N;
int main()
{
    cin >> N;
    N % 2 == 0 ? cout << "CY" : cout << "SK";

    return 0;
}