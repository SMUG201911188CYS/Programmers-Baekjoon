#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

enum
{
    inf = 999999
};

void Dijkstra(vector<vector<pair<int, int>>> graph, vector<int> & weight)
{
    priority_queue<pair<int, int>> pq;
    
    weight[1] = 0;
    
    pq.emplace(weight[1], 1);
    
    while(!pq.empty())
    {
        int current_node = pq.top().second;
        int current_edge_weight = pq.top().first;
        pq.pop();
        
        for(auto node : graph[current_node])
        {
            int connect_node = node.first;
            int connect_edge_weight = node.second;
            
            if(connect_edge_weight + current_edge_weight < weight[connect_node])
            {
                //cout << "emplace, " << connect_node << '\n';
                weight[connect_node] = connect_edge_weight + current_edge_weight;
                pq.emplace(weight[connect_node], connect_node);
            }
        }
    }
}

bool cmp(int a, int b)
{
    return a == b ? false : a > b;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> graph(n+1);
    vector<int> weight(n+1, inf);
    weight[0] = -1;
    
    for(auto x : edge)
    {
        graph[x[0]].emplace_back(x[1], 1);
        graph[x[1]].emplace_back(x[0], 1);
    }

    Dijkstra(graph, weight);
    
    sort(weight.begin(), weight.end(), cmp);
    
    int max = weight[0];
    
    for(int i = 0; i < n; i++)
    {
        cout << weight[i] << '\n';
        
        if(max != weight[i])
            break;
        
        answer++;
    }
    return answer;
}