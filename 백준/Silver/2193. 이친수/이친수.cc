#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<long long>> Table;

int main()
{
    cin >> N;
    Table.resize(N+1, vector<long long>(2));

    Table[1][0] = 0;
    Table[1][1] = 1;

    for(int i = 2; i < N+1; ++i)
    {
        Table[i][0] = Table[i-1][0] + Table[i-1][1];
        Table[i][1] = Table[i-1][0];
    }

    cout << Table[N][0] + Table[N][1];
    
    return 0;
}