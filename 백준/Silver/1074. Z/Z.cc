#include <iostream>
#include <cmath>

using namespace std;


int Quadrant(int y, int x)
{
    if(y == 0 && x == 0) return 0;
    if(y == 0 && x == 1) return 1;
    if(y == 1 && x == 0) return 2;
    if(y == 1 && x == 1) return 3;

    return -1;
}

int main()
{
    int N, r, c;
    cin >> N >> r >> c;

    int depth = N-1;
    int ret = 0;

    while(r > 1 || c > 1)
    {
        int y,x;
        int mod = pow(2, depth);
        y = r/mod; x = c/mod;
        ret += Quadrant(y, x) * pow(4, depth--);
        r %= mod; c %= mod;
    }
    ret += Quadrant(r, c);

    cout << ret;
    return 0;
}