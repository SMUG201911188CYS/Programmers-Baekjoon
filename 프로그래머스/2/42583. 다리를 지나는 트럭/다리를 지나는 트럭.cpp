#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int Second = 1;
    int TotalWeight = 0;
    int InTruckCount = 0;
    queue<pair<int, int>> Q;
    
    for(int Idx = 0; Idx < truck_weights.size(); ++Idx)
    {    
        if(bridge_length == InTruckCount || TotalWeight + truck_weights[Idx] > weight)
        {
            pair<int, int> Truck = Q.front();
            Q.pop();
                
            TotalWeight -= Truck.first;
            InTruckCount -= 1;
            
            if(Second < Truck.second + bridge_length)
            {
                Second = Truck.second + bridge_length; 
            }
            
            Idx--;
        }
        else
        {
            InTruckCount += 1;
            TotalWeight += truck_weights[Idx];
            Q.emplace(truck_weights[Idx], Second);
            
            Second += 1;
        }
    }
    
    while(!Q.empty())
    {
        Second = Q.front().second + bridge_length;
        Q.pop();
    }
    
    return Second;
}