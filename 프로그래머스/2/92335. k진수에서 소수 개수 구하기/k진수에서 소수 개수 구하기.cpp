#include <string>
#include <vector>
#include <iostream>

using namespace std;

inline int Pow(int Num)
{
    return Num * Num;
}

inline bool PrimeCheck(long Num)
{
    if(Num == 1)
    {
        return false;
    }
    
    for(long i = 2; i * i <= Num; i++)
    {
        if(Num % i == 0)
        {
            return false;
        }
    }
    
    return true;
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
    int answer = 0;
    vector<int> Arr;
    string List = "";
    
    FindDigit(n, k, 0, Arr);
    
    int Point1 = 0;
    int Point2 = 0;
    int Size = Arr.size();

    while(true)
    {
        if(Point1 >= Size || Point2 >= Size)
        {
            if(List != "")
            {
                if(PrimeCheck(stol(List)))
                {
                    answer += 1;
                }
            }
            break;
        }
        
        if(Arr[Point2] != 0)
        {
            List += Arr[Point2] + '0';
        }
        else
        {
            if(List != "")
            {
                if(PrimeCheck(stol(List)))
                {
                    answer += 1;
                }
            }
            List = "";
            Point1 = Point2;
        }
        
        Point2 += 1;
    }
    
    return answer;
}