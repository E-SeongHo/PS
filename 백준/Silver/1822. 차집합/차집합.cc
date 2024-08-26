#include <iostream>
#include <set>

using namespace std;

int NA, NB;
set<int> A, B;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> NA >> NB;
    for(int i = 0; i < NA; ++i)
    {
        int n;
        cin >> n;
        A.insert(n);
    }

    for(int i = 0; i < NB; ++i)
    {
        int n;
        cin >> n;
        B.insert(n);
    }

    for(auto n : B)
        A.erase(n);

    cout << A.size() << "\n";
    for(auto n : A)
        cout << n << " ";

    return 0;
}