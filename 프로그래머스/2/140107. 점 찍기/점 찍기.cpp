#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

inline long long Pow(const long long a)
{
    return a * a;
}

long long solution(int k, int d) {
    long long answer = 0;
    long long PosY = 0;
    long long Radius = Pow(d);
    for(int PosX = 0; PosX <= d; PosX += k)
    {
        PosY = sqrt(Radius - Pow(PosX));
        //cout << "PosX : " << PosX << ", PosY : " << PosY << '\n';
        answer += PosY / (long long)k + 1;
        }
    
    return answer;
}