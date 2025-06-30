#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer;

inline void PrimeCheck(long Num)
{
    if(Num == 1)
    {
        return;
    }
    
    for(long i = 2; i * i <= Num; i++)
    {
        if(Num % i == 0)
        {
            return;
        }
    }
    
    answer += 1;
}

void FindDigit(const int n, const int k, int cnt, vector<int>& Arr)
{
    if(n / k == 0)
    {
        Arr.push_back(n % k);
        return;
    }
    
    FindDigit(n / k, k, cnt + 1, Arr);
    
    Arr.push_back(n % k);
}

int solution(int n, int k) {
    vector<int> Arr;
    string List = "";
    answer = 0;
    
    FindDigit(n, k, 0, Arr);
    
    int Size = Arr.size();

    for(int Point = 0; Point <= Size; ++Point)
    {
        if(Point == Size)
        {
            if(List != "")
            {
                PrimeCheck(stol(List));
            }
            break;
        }
        
        if(Arr[Point] != 0)
        {
            List += Arr[Point] + '0';
        }
        else
        {
            if(List != "")
            {
                PrimeCheck(stol(List));
            }
            List = "";
        }
    }
    return answer;
}