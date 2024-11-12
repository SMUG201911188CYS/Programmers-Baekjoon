#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

// X^2 + Y^2 = R^2

inline long long _pow(long long n)
{
    return n * n;
}


long long solution(int r1, int r2) {
    long long answer = 0;
    
    long long PointR1 = 0;
    long long PointR2 = 0;
    
    long long SquareR1 = _pow((long long)r1);
    long long SquareR2 = _pow((long long)r2);
    
    long long temp = 0;
    long long y1 = 0;
    long long y2 = 0;
    
    for(int i = 0; i <= r2; i++)
    {
        y1 = SquareR1 - _pow((long long)i);
        y2 = SquareR2 - _pow((long long)i);
        
        if(y1 < 0)
        {
            y1 = 0;
        }
        
        y1 = ceil(sqrt(y1));
        y2 = floor(sqrt(y2));
        
        answer += y2 - y1 + 1;
        
        if(i == 0)
        {
            temp = (y2 - y1 + 1) * 4;
        }
    }
    
    answer *= 4;
    answer -= temp;
    
    return answer;
}