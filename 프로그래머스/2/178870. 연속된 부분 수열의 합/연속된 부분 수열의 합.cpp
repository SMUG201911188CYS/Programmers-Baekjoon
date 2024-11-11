#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);
    
    int p1 = 0;
    int p2 = 0;
    
    int val = 0;
    int min_k = 1e9;
    int size = sequence.size();
    
    while(p1 < size && p2 < size)
    {
        
        if(val + sequence[p2] > k)
        {
            val -= sequence[p1];
            p1++;
            
            continue;
        }
        else if(val + sequence[p2] == k)
        {
            if(min_k > (p2 - p1))
            {
                min_k = p2 - p1;
                answer[0] = p1;
                answer[1] = p2;
            }
        }
        
        val += sequence[p2];
        p2++;
    }
    return answer;
}