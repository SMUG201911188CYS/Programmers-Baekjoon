#include <string>
#include <iostream>
#include <unordered_map>
#include <set>
#include <cmath>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    unordered_map<string, int> S1;
    unordered_map<string, int> S2;
    unordered_map<string, int>* UM;
    
    set<string> S;
    
    string* StrRef;
    
    for(int k = 1; k <= 2; ++k)
    {
        if(k == 1)
        {
            StrRef = &str1;
            UM = &S1;
        }
        else
        {
            StrRef = &str2;
            UM = &S2;
        }
        
        for(int i = 0; i < StrRef->length() - 1; ++i)
        {
            string Temp;
            
            if(((*StrRef)[i] >= 'a' && (*StrRef)[i] <= 'z') || ((*StrRef)[i] >= 'A' && (*StrRef)[i] <= 'Z'))
            {
                Temp += tolower((*StrRef)[i]);
            }
            else
            {
                continue;
            }

            if(((*StrRef)[i+1] >= 'a' && (*StrRef)[i+1] <= 'z') || ((*StrRef)[i+1] >= 'A' && (*StrRef)[i+1] <= 'Z'))
            {
                Temp += tolower((*StrRef)[i+1]);
            }
            else
            {
                i += 1;
                continue;
            }

            (*UM)[Temp] += 1;
            
            S.insert(Temp);
        }
    }
    
    int Union = 0;
    int Intersection = 0;
    
    for(const auto& x : S)
    {
        Union += max(S1[x], S2[x]);
        Intersection += min(S1[x], S2[x]);
    }
    
    if(Union == 0 && Intersection == 0)
    {
        return 65536;
    }
    
    answer = (float)Intersection / (float)Union * 65536;
    return answer;
}