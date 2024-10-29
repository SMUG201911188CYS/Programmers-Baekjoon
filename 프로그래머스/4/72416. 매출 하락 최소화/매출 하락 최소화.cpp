#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int answer;

unordered_map<int, vector<int>> team;
map<int, pair<int, int>> dp;

vector<int> _sales;

void dfs(int member)
{
    if(team[member].size() == 0)
        return;
    
    int minimum_cost = 1e9;
    bool flag = false;
    
    for(int i = 0; i < team[member].size(); i++)
    {
        dfs(team[member][i]);
        
        int child = team[member][i];
        
        int min_cost = min(dp[child].first, dp[child].second);
        
        dp[member].first += min_cost;
        dp[member].second += min_cost;
        
        minimum_cost = min(minimum_cost, dp[child].second - dp[child].first);
        
        if(dp[child].first >= dp[child].second)
        {
            flag = true;
        }
    }
    
    if(!flag)
    {
        dp[member].first += minimum_cost;
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    _sales = sales;
    
    for(int i = 1; i <= _sales.size(); i++)
    {
        dp[i] = make_pair(0, _sales[i - 1]);
    }
    for(auto x : links)
    {
        team[x[0]].push_back(x[1]);
    }
    
    
    /*for(auto x : team)
    {
        for(auto y : x.second)
        {
            cout << y << ", ";
        }
        cout << '\n';    
    }
    
    for(auto x : dp)
    {
        cout << x.first << " : ";
        cout << x.second.first << ", " << x.second.second << '\n';
    }
    cout << '\n';
    
    */
    dfs(1);
    
    /*for(auto x : dp)
    {
        cout << x.first << " : ";
        cout << x.second.first << ", " << x.second.second << '\n';
    }
    */
    
    return min(dp[1].first, dp[1].second);
    
    
}