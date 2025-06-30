#include <string>
#include <vector>
#include <queue>

using namespace std;

// x * 2^a * 3^b + n * c = y

struct Info
{
    int Value;
    int Cnt;
    int Check;
    
    Info(int VALUE, int CNT, int CHECK) : Value(VALUE), Cnt(CNT), Check(CHECK) {}
};

int solution(int x, int y, int n) {
    int answer = 1e9;
    vector<int> IsCheck(1000001, 1e9);
    
    queue<pair<int, int>> Q;
    
    Q.emplace(x, 0);
    
    int Value = Q.front().first;
    int Cnt = Q.front().second;
    
    while(!Q.empty())
    {
        Value = Q.front().first;
        Cnt = Q.front().second;
        
        Q.pop();
        
        if(answer <= Cnt)
        {
            continue;
        }
        
        if(Value == y)
        {
            answer = min(answer, Cnt);
        }
        
        if(Value + n <= y && Cnt + 1 < IsCheck[Value + n])
        {
            IsCheck[Value + n] = Cnt + 1;
            Q.emplace(Value + n, Cnt + 1);
        }
        if(Value * 2 <= y && Cnt + 1 < IsCheck[Value * 2])
        {
            IsCheck[Value * 2] = Cnt + 1;
            Q.emplace(Value * 2, Cnt + 1);
        }
        if(Value * 3 <= y && Cnt + 1 < IsCheck[Value * 3])
        {
            IsCheck[Value * 3] = Cnt + 1;
            Q.emplace(Value * 3, Cnt + 1);
        }
    }
    
    
    if(answer == 1e9)
    {
        answer = -1;
    }
    return answer;
}