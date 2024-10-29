#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int answer;

vector<vector<int>> team;
vector<int> _sales;
vector<bool> selected_member;
unordered_map<int, int> u_m;

void dfs(int size, int depth, int cost)
{
    if(depth == size)
    {
        //cout << "cost : " << cost << '\n';
        answer = min(answer, cost);
        return;
    }
    
    for(int i = 0; i < team[depth].size(); i++)
    {
        int member = team[depth][i];
        
        if(u_m[member] == 2)
        {   
            if(selected_member[member])
            {
                //cout << "alredy insert : " << member << '\n';
                dfs(size, depth+1, cost);
                return;
            }
            else
            {
                //cout << "insert : " << member << ", " << "current cost : " << cost << '\n';
                
                cost += _sales[member - 1];
                selected_member[member] = true;
                dfs(size, depth+1, cost);
                selected_member[member] = false;
                cost -= _sales[member - 1];
            }
        }
        else
        {            
            cost += _sales[member - 1];
            selected_member[member] = true;
            //cout << "insert : " << member << ", " << "current cost : " << cost << '\n';
            dfs(size, depth+1, cost);
            selected_member[member] = false;
            cost -= _sales[member - 1];
        }
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    answer = 999999;
    
    vector<vector<int>> graph(sales.size() + 1);
    _sales = sales;
    
    for(auto x : links)
    {
        graph[x[0]].push_back(x[1]);
    }
    
    for(int i = 1; i <= sales.size(); i++)
    {
        if(graph[i].size() > 0)
        {
            vector<int> temp;
            
            temp.push_back(i);
            
            u_m[i]++;
            
            for(auto x : graph[i])
            {
                u_m[x]++;
                temp.push_back(x);
            }
            
            team.push_back(temp);
        }
    }
    
    /*for(int i = 0; i < team.size(); i++)
    {
        cout << "member : ";
        
        for(auto x : team[i])
        {
            cout << x << ", ";
        }
        cout << '\n';
    }
    cout << '\n';
    
    for(auto x : u_m)
    {
        cout << x.first << ", " << x.second << '\n';
    }
    */
    
    int team_size = team.size();
    
    selected_member.resize(sales.size() + 1, false);
    
    dfs(team_size, 0, 0);
    
    return answer;
    
    
}