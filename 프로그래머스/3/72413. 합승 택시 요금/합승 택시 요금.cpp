#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

enum
{
    inf = 999999
};

using namespace std;

vector<int> Dijkstra(vector<vector<pair<int, int>>> graph, vector<int> weight, int start)
{
    priority_queue<pair<int, int>> pq;

    weight[start] = 0;
    pq.emplace(weight[start], start);
    
    while(!pq.empty())
    {
        int node = pq.top().second;
        int node_weight = pq.top().first;

        //cout << "current node : " << node << ", weight : " << node_weight << '\n'; 
        pq.pop();

        for(auto x : graph[node])
        {
            //cout << "connect node : " << x.first << ", weight : " << x.second << '\n';
            int connect_node = x.first;
            int connect_node_weight = x.second;
            
            if(connect_node_weight + node_weight < weight[connect_node])
            {
                //cout << "Emplace Node : " << connect_node << ", " << "Before w : " << weight[connect_node];
                weight[connect_node] = connect_node_weight + node_weight;
                pq.emplace(weight[connect_node], connect_node);
                //cout << ", After w : " << weight[connect_node] << '\n';
            }
        }
        //cout << "\n\n";
    }

    return weight;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> weight(n + 1, inf);
    
    for(auto node : fares)
    {
        graph[node[0]].emplace_back(node[1], node[2]);
        graph[node[1]].emplace_back(node[0], node[2]);
    }
    
    vector<int> weight_s = Dijkstra(graph, weight, s);
    vector<int> weight_a = Dijkstra(graph, weight, a);
    vector<int> weight_b = Dijkstra(graph, weight, b);

    int answer = weight_s[a] + weight_s[b];

    for(int i = 1; i <= n; i++)
    {
        int share = weight_s[i] + weight_a[i] + weight_b[i];
        cout << share << '\n';

        if(answer > share)
            answer = share;
    }

    
    //int i = 0;

    /*for(auto x : graph)
    {
        cout << "current : " <<  i << '\n';
        for(auto node : x)
        {
            cout << node.first << ", " << node.second << '\n';
        }
        cout << '\n';
        i++;
    }
    */
    return answer;
}