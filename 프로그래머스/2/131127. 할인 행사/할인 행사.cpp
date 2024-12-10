#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int Index = 0;
    bool CheckProduct = true;
    
    unordered_map<string, int> DiscountProduct;
    
    for(; Index < 10; ++Index)
    {
        DiscountProduct[discount[Index]] += 1;
    }
    
    for(; Index <= discount.size(); ++Index)
    {
        CheckProduct = true;
        for(int j = 0; j < want.size(); ++j)
        {
            if(DiscountProduct[want[j]] < number[j])
            {
                CheckProduct = false;
                break;
            }
        }
        
        if(CheckProduct)
        {
            answer += 1;
        }
        
        if(Index == discount.size())
        {
            break;
        }
        DiscountProduct[discount[Index]] += 1;
        DiscountProduct[discount[Index - 10]] -= 1;
    }
    
    return answer;
}