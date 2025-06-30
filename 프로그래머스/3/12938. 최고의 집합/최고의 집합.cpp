#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s)
    {
        answer.push_back(-1);
        
        return answer;
    }

    int quotient = s / n;
    int remainder = s % n;
    
    for(int i = 0; i < n; i++)
    {
        answer.push_back(quotient);
    }
    
    int index = n - 1;
    
    while(remainder > 0)
    {
        answer[index] += 1;
        
        remainder--;
        
        if(index < 0)
        {
            index = n - 1;
        }
        else
        {
            index--;
        }
    }
    
    return answer;
}