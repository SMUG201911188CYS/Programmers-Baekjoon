#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> PQ;
    
    for(const auto Food : scoville)
    {
        PQ.push(Food);
    }
    
    int FirstLessScovilleFood = 0;
    int SecondLessScovileFood = 0;
    while(!PQ.empty())
    {
        FirstLessScovilleFood = PQ.top();
        PQ.pop();
        
        if(FirstLessScovilleFood < K)
        {
            if(PQ.empty())
            {
                return -1;
            }
            SecondLessScovileFood = PQ.top();
            PQ.pop();
            
            PQ.push(FirstLessScovilleFood + (SecondLessScovileFood * 2));
            answer += 1;
        }
    }
    return answer;
}