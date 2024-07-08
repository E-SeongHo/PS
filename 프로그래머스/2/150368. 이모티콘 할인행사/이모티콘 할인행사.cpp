#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<float> Discounts = {0.1f, 0.2f, 0.3f, 0.4f};
vector<int> Emoticons;
vector<vector<int>> Users;

int Subscriber = 0;
int Sales = 0;

void dfs(vector<float>& discount_info, int depth)
{
    if(depth == Emoticons.size())
    {
        int subscriber = 0;
        int sales = 0;
        
        for(auto user : Users)
        {
            int rate = user[0];
            int limit = user[1];
            
            int cost = 0;
            for(int i = 0; i < discount_info.size(); i++)
            {
                if(discount_info[i] >= rate * 0.01f) cost += Emoticons[i] * (1.0f - discount_info[i]);
            }
            
            if(cost >= limit) subscriber++;
            else sales += cost;
        }
        
        if(subscriber > Subscriber)
        {
            Subscriber = subscriber;
            Sales = sales;
        }
        else if(subscriber == Subscriber)
        {
            if(sales > Sales)
            {
                Subscriber = subscriber;
                Sales = sales;
            }
        }
        
        return;
    }
    
    for(float discount : Discounts)
    {
        discount_info[depth] = discount;
        dfs(discount_info, depth+1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    
    Users = users;
    Emoticons = emoticons;
    
    vector<float> v(emoticons.size());
    dfs(v, 0);
    
    vector<int> ret = {Subscriber, Sales};
    
    return ret;
}