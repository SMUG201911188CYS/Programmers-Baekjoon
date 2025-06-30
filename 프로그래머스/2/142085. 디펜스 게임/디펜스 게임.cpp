#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int Size = enemy.size();
    
    int UsedSoldier = 0;
    int Index = 0;
    int SkillGuard = 0;
    priority_queue<int> PQ;

    if(k >= Size)
    {
        return Size;
    }
    
    UsedSoldier = 0;
    
    while(true)
    {
        if(Index == Size)
        {
            break;
        }
        
        UsedSoldier += enemy[Index];
        PQ.emplace(enemy[Index]);
        
        //cout << "UsedSoldier : " << UsedSoldier << '\n';
        
        if(UsedSoldier <= n)
        {
            //cout << "answer ++" << '\n';
            answer++;
        }
        else
        {            
            if(k == 0)
            {
                //cout << "End (k < 0) " << answer << '\n';
                return answer;
            }

            SkillGuard = PQ.top();
            PQ.pop();

            //cout << "Use Skill, Guard Enemy : " << SkillGuard << '\n'; 
            UsedSoldier -= SkillGuard;
            k -= 1;
            answer++;
            //cout << "answer ++" << '\n';
            //cout << "Remain K : " << k << ", UsedSoldier : " << UsedSoldier << '\n'; 
        }
        
        Index += 1;
    }
    
    return answer;
}