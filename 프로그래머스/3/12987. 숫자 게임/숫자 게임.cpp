#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int size = A.size();
    
    int p1 = 0;
    int p2 = 0;
    
    while(true)
    {
        if(p1 >= size || p2 >= size)
        {
            break;
        }
        
        if(A[p1] >= B[p2])
        {
            p1++;
        }
        else
        {
            answer++;
            p1++;
            p2++;
        }
    }
    
    
    
    return answer;
}