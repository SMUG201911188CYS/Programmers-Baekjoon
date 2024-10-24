#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    queue<char> q;
    
    int check = 0;
    
    for(int i = 0; i < s.length(); i++)
        q.push(s[i]);

    while(!q.empty())
    {
        char c = q.front();
        q.pop();
        
        if(c == '(')
            check++;
        else
            check--;
        
        if(check < 0)
        {
            answer = false;
            break;
        }
    }
    
    if(check != 0)
        return false;
    
    return answer;
}