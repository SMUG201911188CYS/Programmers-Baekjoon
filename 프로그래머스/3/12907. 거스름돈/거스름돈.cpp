#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer;

int solution(int n, vector<int> money) {
    
    vector<int> dp(n + 1, 0);
    int size = money.size();
    
    dp[0] = 1;
    
    
    for(int i = 0; i < size; i++)
    {
        for(int k = 1; k <= n; k++)
        {
            if(money[i] > k)
            {
                continue;
            }
            
            dp[k] += dp[k - money[i]];
        }
    }

    return dp[n];
}