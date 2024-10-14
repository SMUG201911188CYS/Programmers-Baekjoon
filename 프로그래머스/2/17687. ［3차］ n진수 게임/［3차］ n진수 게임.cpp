#include <string>
#include <vector>
#include <iostream>

using namespace std;


void convert_bit(int num, int n, string & bit_temp)
{
    if(num == 0)
        return;
    
    convert_bit(num / n, n, bit_temp);
    
    int bit = num % n;
    if(bit > 9)
    {
        bit_temp += 'A' + (bit - 10);
    }
    else
    {
        bit_temp += to_string(bit);
    }
}


string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0;
    int cnt = 1;
    
    while(true)
    {
        if(answer.size() == t)
            break;
        
        int temp = num;
        string bit_temp;
        
        //cout << "current : " << num << '\n';
        
        convert_bit(temp, n, bit_temp);
        //cout << bit_temp << '\n';
        
        if(temp == 0)
            bit_temp += '0';
        
        for(auto x : bit_temp)
        {
            if(answer.length() == t)
                break;
            
            if(cnt > m)
                cnt = 1;
        
            if(cnt == p)
            {
                answer += x;
                //cout << "input : " << x << ", " << "answer : " << answer << '\n';
            }
            cnt++;
        }
        
        num++;
    }
    
    return answer;
}