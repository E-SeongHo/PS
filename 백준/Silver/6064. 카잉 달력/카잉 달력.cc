#include <iostream>
#include <vector>

using namespace std;

int lcm(int x, int y)
{
    int mult = x * y;
    int mod = x % y;
    while(mod != 0)
    {
        x = y;
        y = mod;
        mod = x % y;
    }

    return mult / y;
}

int func(int M, int N, int x, int y)
{
    if(x > M || y > N) return -1;
    
    int limit = lcm(N, M);
    int year = x;
    int yy = x;
    while(yy != y)
    {
        //cout << yy << " " << y << endl;
        year += M;
        yy = year % N;
        if(yy == 0) yy = N;
        if(year > limit) return -1;
    }

    return year;
}


int main()
{
    int T;
    cin >> T;

    for(int t = 0; t < T; ++t)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        if(M > N)
        {
            swap(M, N);
            swap(x, y);
        }
        cout << func(M, N, x, y) << "\n";
    }
    return 0;
}