#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    if(a % b == 0)
        return b;
    else
        return GCD(b, a % b);
}

int solution(vector<int> arr) {
    
    if(arr.size() == 1)
        return arr[0];
    
    sort(arr.begin(), arr.end());

    
    int lcm = arr[0] * arr[1] / GCD(arr[0], arr[1]);
    
    //cout << lcm << '\n';
    
    for(int i = 2; i < arr.size(); i++)
    {
        lcm = lcm * arr[i] / GCD(arr[i], lcm);
        
        //cout << lcm << '\n';
    }
    
    return lcm;
}