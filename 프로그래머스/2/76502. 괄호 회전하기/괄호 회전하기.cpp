#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

int solution(string s) {
    int Length = s.length();
    int answer = Length;
    int CurrentIndex = 0;

    unordered_map<char, char> PairChar;
    
    PairChar[']'] = '[';
    PairChar['}'] = '{';
    PairChar[')'] = '(';
    
    for(int Idx1 = 0; Idx1 < Length; ++Idx1)
    {
        CurrentIndex = Idx1;
        bool Flag = false;
        unordered_map<char, int> CountChar;
        unordered_map<char, int> PosChar;
        stack<char> S;
        
        for(int Count = 0; Count < Length; ++Count, ++CurrentIndex)
        {
            if(CurrentIndex >= Length)
            {
                CurrentIndex = 0;
            }
            
            if(s[CurrentIndex] == '[' || s[CurrentIndex] == '{' || s[CurrentIndex] == '(' )
            {
                CountChar[s[CurrentIndex]] += 1;
                S.push(s[CurrentIndex]);
            }
            else
            {
                CountChar[PairChar[s[CurrentIndex]]] -= 1;
                
                if(S.empty())
                {
                    Flag = true;
                    break;
                }
                
                char PreviewChar = S.top();
                S.pop();
                
                if(PreviewChar != PairChar[s[CurrentIndex]] || CountChar[PairChar[s[CurrentIndex]]] < 0)
                {
                    Flag = true;
                    break;
                }
            }
        }
        cout << '\n';
        
        if(Flag || (CountChar['['] != 0 || CountChar['{'] != 0 || CountChar['('] != 0))
        {
            answer -= 1;
        }
    }
    return answer;
}