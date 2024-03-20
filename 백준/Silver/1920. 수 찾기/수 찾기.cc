#include <iostream>
#include <set>

using namespace std;

int main()
{
    // O(NlogN + MlogN), O(N) : 100000 * 4 = 400000byte = 400kb = 0.4mb
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, M;
    set<int> s;
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        s.insert(n);
    }
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        if(s.find(n) != s.end()) cout << 1 << "\n";
        else cout << 0 << "\n";
    }


    return 0;
}