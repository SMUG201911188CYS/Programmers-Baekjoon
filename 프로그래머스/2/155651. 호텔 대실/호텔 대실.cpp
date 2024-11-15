#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if(a[0] < b[0])
    {
        return true;
    }
    if(a[0] == b[0])
    {
        if(a[1] < b[1])
        {
            return true;
        }
    }
    return false;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<vector<int>> BookTimeInt(book_time.size(), vector<int>(2, 0));
    
    for(int i = 0; i < book_time.size(); i++)
    {
        BookTimeInt[i][0] = stoi(book_time[i][0].substr(0, 2)) * 60 + stoi(book_time[i][0].substr(3));
        BookTimeInt[i][1] = stoi(book_time[i][1].substr(0, 2)) * 60 + stoi(book_time[i][1].substr(3));
    }
    
    sort(BookTimeInt.begin(), BookTimeInt.end(), cmp);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(const auto time : BookTimeInt)
    { 
        cout << "current : " << time[0] << ", " << time[1] << '\n';
        if(pq.empty())
        {
            if(answer == 0)
            {
                answer++;
                pq.push(time[1]);
            }
            else
            {
                pq.push(time[1]);
            }
        }
        else
        {
            if(time[0] < pq.top() + 10)
            {
                pq.push(time[1]);
                
                if(answer < pq.size())
                {
                    answer++;
                }
            }
            else
            {
                pq.pop();
                pq.push(time[1]);
            }
        }
        
        cout << pq.size() << '\n';
    }
    return answer;
}