#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    
    multiset<int> bt;
    
    for(auto& str : operations)
    {
        if(str[0] == 'I')
        {
            int n = stoi(str.substr(2));
            bt.insert(n);
        }
        else
        {
            if(!bt.size()) continue;
            int op = stoi(str.substr(2));
            {
                if(op == 1) bt.erase(--bt.end());
                else bt.erase(bt.begin());
            }
        }
    }
    
    if(bt.size()) return {*bt.rbegin(), *bt.begin()};
    else return {0, 0};
}