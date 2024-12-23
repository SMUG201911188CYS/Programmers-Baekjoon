#include <iostream>
#include <vector>

using namespace std;


int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    vector<int> Stations;
    
    Stations.emplace_back(0 - w);
    for(const auto& x : stations)
    {
        Stations.emplace_back(x);
    }
    Stations.emplace_back(n + w + 1);
    
    
    for(int Index = 1; Index < Stations.size(); ++Index)
    {
        //cout << "CurrentPos : " << Stations[Index] - w - 1 << '\n';
        //cout << "PrevPos : " << Stations[Index - 1] + w + 1 << '\n';
        int NotReachedCount = (Stations[Index] - w - 1) - (Stations[Index - 1] + w + 1) + 1;
        
        //cout << NotReachedCount << '\n';
        
        if(NotReachedCount <= 0)
        {
            continue;
        }
        
        answer += NotReachedCount / (w * 2 + 1);
        if(NotReachedCount % (w * 2 + 1) != 0)
        {
            answer += 1;
        }
        
    }
    //Efficiency Test
    /*for(int Index = 1; Index < Stations.size(); ++Index)
    {
        int CurrentPosition = Stations[Index] - w - 1;
        
        //cout << "Current Index : " << Index << ", Current Pos : " << CurrentPosition << '\n';  
        while(true)
        {
            //cout << "Current Pos : " << CurrentPosition << '\n';
            if(CurrentPosition <= Stations[Index - 1] + w)
            {
                //cout << "CurrnetPos > Prev Pos : " << Stations[Index - 1] + w << '\n';
                break;
            }
            
            bool Flag = false;
            for(int i = w; i >= 0; --i)
            {
                //cout << "Check : " << CurrentPosition - i << ", i : " << i << '\n';
                
                if(CurrentPosition - i <= 0 || CurrentPosition - i <= Stations[Index - 1] + w)
                {
                    //cout << "Pass" << '\n';
                    continue;
                }
                answer += 1;
                //cout << "Install : " << CurrentPosition - i << '\n';
                CurrentPosition = CurrentPosition - i - w - 1;
                //cout << "Move : " << CurrentPosition << '\n';
                Flag = true;
                break;
            }
            
            if(!Flag)
            {
                //cout << "Cant Move " << '\n';
                break;
            }
        }
    }
    */
    return answer;
}