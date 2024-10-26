#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int p1 = 0;
    int p2 = people.size() - 1;
    
    while(true)
    {
        if(p1 == p2)
        {
            answer++;
            break;
        }
        
        if(p1 > p2)
        {
            break;
        }
        
        if(limit >= people[p1] + people[p2])
        {
            p1++;
            p2--;
        }
        else
        {
            p2--;
        }
        
        answer++;
    }
    
    
    return answer;
}