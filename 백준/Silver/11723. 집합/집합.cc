#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> active(21);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M;
    cin >> M;

    for(int i = 0; i < M; ++i)
    {
        string command;
        int n;
        cin >> command;

        if(command == "add")
        {
            cin >> n;
            active[n] = true;
        }        
        else if(command == "remove")
        {
            cin >> n;
            active[n] = false;
        }
        else if(command == "check")
        {
            cin >> n;
            cout << active[n] << "\n";
        }
        else if(command == "toggle")
        {
            cin >> n;
            active[n] = !active[n];
        }
        else if(command == "all")
        {
            fill(active.begin(), active.end(), true);
        }
        else if(command == "empty")
        {
            fill(active.begin(), active.end(), false);
        }

    }
    return 0;
}