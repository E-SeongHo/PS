#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, S;
vector<int> V;
map<int, int> M;

int main()
{
    cin >> N >> S;

    V.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];

    for(int i = 0; i < N; ++i)
    {
        map<int, int> copy(M);
        for(auto& n : copy)
        {
            M[n.first + V[i]] += n.second;
        }

        M[V[i]]++;
    }

    cout << M[S];

    return 0;
}