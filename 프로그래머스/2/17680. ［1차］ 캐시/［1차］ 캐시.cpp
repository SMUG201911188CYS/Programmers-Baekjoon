#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>

using namespace std;

list<string> List;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    list<string> Caches;
    //unordered_map<string, list<string>::iterator> CacheAddress;
    
    if(cacheSize == 0)
    {
        answer = cities.size() * 5;
        return answer;
    }
    
    for(auto& City : cities)
    {
        transform(City.begin(), City.end(), City.begin(), ::tolower);
        
        bool Flag = false;
        list<string>::iterator CacheIt = Caches.begin();
        for(; CacheIt != Caches.end(); ++CacheIt)
        {
            if(City == *CacheIt)
            {
                Flag = true;
                Caches.erase(CacheIt);
                break;
            }
        }
        
        if(!Flag)
        {
            //cout << "Not Found In Cache." << '\n';
            answer += 5;
            if(Caches.size() == cacheSize)
            {
                //CacheAddress.erase(Caches.back());
                Caches.pop_back();
            }
        }
        else
        {
            answer += 1;
            //cout << "Find In Cache." << '\n';
            //Caches.erase(CacheAddress[City]);
        }
        
        Caches.push_front(City);
        //CacheAddress[City] = Caches.begin();
        
        /*for(const auto& Cache : Caches)
        {
            cout << Cache << ", ";
        }
        cout << '\n';
        */
    }
    
    return answer;
}