#include <iostream>
#include <set>

using namespace std;

int T, K;

// K <= 1000000
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        multiset<int, less<int>> set;

        cin >> K;
        for(int k = 0; k < K; k++)
        {
            char D; int I;
            cin >> D >> I;

            if(D == 'I')
            {
               set.insert(I);
            }
            else if(D == 'D')
            {
                if(set.empty()) continue;
                if(I == 1)
                {
                    set.erase(--set.end());
                }
                if(I == -1)
                {
                    set.erase(set.begin());
                }
            }
        }
        if(set.empty()) cout << "EMPTY\n";
        else cout << *--set.end() << " " << *set.begin() << "\n";
    }

    return 0;
}