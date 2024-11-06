#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    
    for(auto x : results)
    {
        graph[x[0]][x[1]]++;
        graph[x[1]][x[0]]--;
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {                 
                if(i == j || graph[i][k] == 0 || graph[k][j] == 0)
                {
                    continue;
                }
                
                if(graph[i][k] == 1 && graph[k][j] == 1)
                {
                    graph[i][j] = 1;
                }
                
                if(graph[i][k] == -1 && graph[k][j] == -1)
                {
                    graph[i][j] = -1;
                }
                
            }
        }
    }
    
    answer = n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                continue;
            }
            
            if(graph[i][j] == 0)
            {
                answer--;
                break;
            }
        }
    }
    
    return answer;
}