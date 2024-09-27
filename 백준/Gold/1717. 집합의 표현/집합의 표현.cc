#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M, A, B;
vector<int> DisjointSet;


int Find(int A)
{
    if(DisjointSet[A] == A) return A;

    DisjointSet[A] = Find(DisjointSet[A]);
    return DisjointSet[A];
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);

    if(A > B) swap(A, B);
    DisjointSet[B] = A;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    DisjointSet.resize(N+1);
    for(int i = 0; i < N+1; ++i)
        DisjointSet[i] = i;

    for(int i = 0; i < M; ++i)
    {
        int op;
        cin >> op >> A >> B;

        if(op == 0)
        {
            Union(A, B);
        }
        else
        {
            if(Find(A) != Find(B)) cout << "NO";
            else cout << "YES";
            cout << '\n';
        }
    }

    return 0;
}