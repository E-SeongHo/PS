#include <iostream>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

int N, M;
vector<unsigned int> Trains;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    Trains.resize(N+1, 0);

    for(int i = 0; i < M; ++i)
    {
        int op, train, seat;
        cin >> op >> train;

        switch(op)
        {
        case 1:
            cin >> seat;
            Trains[train] |= 1 << (seat-1);
            break;
        case 2:
            cin >> seat;
            Trains[train] &= ~(1 << (seat-1));
            break;
        case 3:
            Trains[train] = Trains[train] << 1;
            break;
        case 4:
            Trains[train] = Trains[train] >> 1;
            break;
        }

        Trains[train] = Trains[train] & 0xFFFFF;
    }

    set<unsigned int> s;
    for(int i = 1; i < N+1; ++i)
    {
        s.insert(Trains[i]);
    }

    cout << s.size();

    return 0;
}