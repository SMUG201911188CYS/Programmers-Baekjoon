#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, map<int, int>> Graph;

void Dijkstra(int StartVertex, int N, int K, vector<int>& ValueList)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > PQ;
    int CurrentVertex = 0;
    
    ValueList[1] = 0;
    
    PQ.emplace(0, StartVertex);
    
    while(!PQ.empty())
    {
        CurrentVertex = PQ.top().second;
        PQ.pop();
        
        //cout << "Current : " << CurrentVertex << '\n';
        for(const auto& Info : Graph[CurrentVertex])
        {
            if(ValueList[CurrentVertex] + Info.second < ValueList[Info.first])
            {
                //cout << "Update Value : " << Info.first << ", " << ValueList[Info.first] << " -> " << ValueList[CurrentVertex] + Info.second << '\n';
                ValueList[Info.first] = ValueList[CurrentVertex] + Info.second;
                PQ.emplace(ValueList[Info.first], Info.first);
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> ValueList(N + 1, 1e9);
    for(const auto& Road : road)
    {
        int Vertex1 = Road[0];
        int Vertex2 = Road[1];
        int Value = Road[2];
        
        if(Graph[Vertex1][Vertex2] != 0 && Graph[Vertex1][Vertex2] <= Value)
        {
            continue;
        }
        
        Graph[Vertex1][Vertex2] = Value;
        Graph[Vertex2][Vertex1] = Value;
    }

    Dijkstra(1, N, K, ValueList);
    
    for(const auto& Result : ValueList)
    {
        if(Result <= K)
        {
            answer += 1;
        }
    }
    
    return answer;
}