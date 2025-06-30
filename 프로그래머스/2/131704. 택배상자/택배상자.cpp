#include <string>
#include <vector>
#include <iostream>
#include <stack>


using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int Index = 1;
    int CurrentPost = 0;
    int PostNum = order.size();
    
    stack<int> SubContainer;
    
    
    while(Index <= PostNum + 1)
    {
        if(Index == order[CurrentPost])
        {
            answer += 1;
            CurrentPost += 1;
            Index += 1;
        }
        else if(Index < order[CurrentPost])
        {
            SubContainer.push(Index);
            Index += 1;
        }
        else
        {
            if(!SubContainer.empty())
            {
                int SubContainerTopPost = SubContainer.top();
                SubContainer.pop();
                
                if(SubContainerTopPost == order[CurrentPost])
                {
                    answer += 1;
                    CurrentPost += 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return answer;
}