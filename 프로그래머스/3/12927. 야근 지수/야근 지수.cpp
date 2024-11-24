#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long VectorSum = 0;
    
    priority_queue<int> PQ;
    
    for(const int Num : works)
    {
        VectorSum += Num;
        PQ.push(Num);
    }
    
    if(VectorSum < n)
    {
        return answer;
    }
    
    int CurrentNum = 0;
    
    for(int i = 0; i < n; i++)
    {
        CurrentNum = PQ.top();
        PQ.pop();
        
        CurrentNum -= 1;
        
        PQ.push(CurrentNum);
    }
    
    while(!PQ.empty())
    {
        CurrentNum = PQ.top();
        PQ.pop();
        
        answer += CurrentNum * CurrentNum;
    }
    
    return answer;
}