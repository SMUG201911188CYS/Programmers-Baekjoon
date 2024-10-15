#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(int a, int b)
{
    if(a > b)
        return true;
    else
        return false;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    deque<int> deq;
    
    for(auto x : operations)
    {
        string n;

        switch (x[0])
        {
            case 'I' :
                n = x.substr(2);
                if(n[0] == '-')
                    deq.push_back(stoi(n.substr(1)) * - 1);
                else
                    deq.push_back(stoi(n));
                break;
            case 'D' :
                if(!deq.empty())
                {
                    sort(deq.begin(), deq.end(), cmp);
            
                    if(x[2] == '-')
                        deq.pop_back();
                    else
                        deq.pop_front();
                    break;
                }
            default:
                break;
        }
        
        //cout << "current deque element" << '\n';
        //for(auto deq_element : deq)
        //    cout << deq_element << ", ";
        //cout << '\n';
    }

    //cout << "End, deque element : " << '\n';
    //for(auto deq_element : deq)
    //    cout << deq_element << ", ";
    //cout << '\n';

    if(!deq.empty())
    {
        sort(deq.begin(), deq.end(), cmp);
        answer[0] = deq.front();
        answer[1] = deq.back();
    }
    
    return answer;
}