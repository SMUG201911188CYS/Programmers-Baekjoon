#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int bfs(int x, int y, int n, vector<vector<int>> graph)
{
    //cout << "x : " << x << ", " << "y : " << y << '\n';
    int cnt = 0;
    int diff = 0;
    
    vector<bool> check(n + 1, false);
    stack<int> s;

    s.push(x);
    check[x] = true;
    cnt += 1;

    while(!s.empty())
    {
        int vertex = s.top();

        //cout << "vertex : " << vertex << '\n';

        s.pop();

        for(int i = 0; i < graph[vertex].size(); i++)
        {
            if(graph[vertex][i] != y && !check[graph[vertex][i]])
            {    
                s.push(graph[vertex][i]);
                check[graph[vertex][i]] = true;
                cnt++;
                //cout << "push : " << graph[vertex][i] << '\n';
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999999;
    int max_node = 0;
    int max_vertex = 0;
    
    vector<vector<int>> graph(n + 1);
    
    for(auto x : wires)
    {
        graph[x[0]].push_back(x[1]);
        graph[x[1]].push_back(x[0]);
    }
        
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        
        for(auto x : graph[i])
        {
            cnt = bfs(i, x, n, graph);
            //cout << cnt << '\n';
            
            int diff = (n - cnt) - cnt > 0 ? (n - cnt) - cnt : ((n - cnt) - cnt) * -1;
            //cout << "diff : " << diff << '\n';

            if(diff < answer)
                answer = diff;
        }
    }

    return answer;
}