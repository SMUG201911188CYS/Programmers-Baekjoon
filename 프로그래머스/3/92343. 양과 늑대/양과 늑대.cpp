#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int answer;


void dfs(int vertex, const vector<int> info, const vector<vector<int>> graph, int sheep_cnt, int wolf_cnt, set<int> s)
{
    if(info[vertex] == 0)
    {
        sheep_cnt++;
    }
    else
    {
        wolf_cnt++;
        
        if(sheep_cnt == wolf_cnt)
            return;
    }
    
    s.erase(vertex);
    
    if(answer < sheep_cnt)
        answer = sheep_cnt;
    
    for(auto x : graph[vertex])
    {
        if(graph[x].size() == 0 && info[x] == 1)
            continue;
        
        s.insert(x);
    }
    
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        dfs(*it, info, graph, sheep_cnt, wolf_cnt, s);
    }
    
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> graph(info.size() + 1);
    vector<bool> is_visited(info.size(), false);
    
    for(auto x : edges)
    {
        graph[x[0]].push_back(x[1]);
        
    }
    
    dfs(0, info, graph, 0, 0, { });
    
    return answer;
}