#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <limits>

using namespace std;

string solution(string s) {
    
    stringstream sstream(s);
    string buffer;
    
    int max = numeric_limits<int>::min();
    int min = numeric_limits<int>::max();
    
    while(getline(sstream, buffer, ' '))
    {
        int n = stoi(buffer);
        max = std::max(max, n);
        min = std::min(min, n);
    }
    
    string answer = "";
    answer = answer + to_string(min);
    answer = answer + " ";
    answer = answer + to_string(max);
    
    return answer;
}