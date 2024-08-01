#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

using tup = tuple<int, int, int>;
vector<vector<tup>> v;
vector<pair<int, int>> tree;

bool cmp(tuple<int, int, int>& t1, tuple<int, int, int>& t2)
{
    auto [y1, x1, i1] = t1;
    auto [y2, x2, i2] = t2;
    
    if(y1 == y2) return x1 <= x2; 
    else return y1 > y2; 
}

int find_node(vector<tup>& v, int min_x, int max_x)
{
    for(int i = 0; i < v.size(); i++)
    {
        auto [y, x, index] = v[i];
        if(x > min_x && x < max_x) return i;
    }

    return -1;
}

void preorder(vector<int>& order, int current)
{
    order.push_back(current);
    
    if(tree[current].first)
    {
        preorder(order, tree[current].first);
    }
    
    if(tree[current].second)
    {
        preorder(order, tree[current].second);
    }
}

void postorder(vector<int>& order, int current)
{
    if(tree[current].first)
    {
        postorder(order, tree[current].first);
    }
    
    if(tree[current].second)
    {
        postorder(order, tree[current].second);
    }
    
    order.push_back(current);
}

void find_childs(tup& current, int min_x, int max_x)
{
    auto [y, x, index] = current;
    
    while(y && v[--y].empty()) {}
    if(y == 0 && v[0].empty()) return;
    
    vector<tup>& nextlevels = v[y];

    int left = find_node(nextlevels, min_x, x);
    if(left != -1)
    {
        tree[index].first = get<2>(nextlevels[left]);
        find_childs(nextlevels[left], min_x, x);
    }
    
    int right = find_node(nextlevels, x, max_x);
    if(right != -1)
    {
        tree[index].second = get<2>(nextlevels[right]);
        find_childs(nextlevels[right], x, max_x);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    // 2:00
    
    vector<tup> tmp(nodeinfo.size());
    int max_x = -1;
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int index = i+1;
        max_x = max(max_x, x);
        
        tmp[i] = {y, x, index};
    }
    sort(tmp.begin(), tmp.end(), cmp);
        
    v.resize(get<0>(tmp.front())+1);
    for(int i = 0; i < tmp.size(); i++)
    {
        v[get<0>(tmp[i])].push_back(tmp[i]);
    }
    
    int root = get<2>(tmp[0]);
    tree.resize(nodeinfo.size()+1);
    
    find_childs(tmp[0], -1, max_x+1);
    
    vector<vector<int>> answer(2);
    preorder(answer[0], root);
    postorder(answer[1], root);
    
    // 2:55
    return answer;
}