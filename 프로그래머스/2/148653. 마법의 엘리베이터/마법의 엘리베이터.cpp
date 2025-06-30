#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int storey) {
    int answer = 0;
    string StoreyToString = to_string(storey);
    
    vector<int> StoreyVec;
    StoreyVec.push_back(0);
    
    for(int i = 0; i < StoreyToString.length(); ++i)
    {
        StoreyVec.push_back(StoreyToString[i] - '0');
    }
    
    for(int i = StoreyVec.size() - 1; i >= 1; --i)
    {
        if(StoreyVec[i] < 5)
        {
            answer += StoreyVec[i];
        }
        else if(StoreyVec[i] > 5)
        {
            answer += 10 - StoreyVec[i];
            StoreyVec[i - 1] += 1;
        }
        else
        {
            if(StoreyVec[i - 1] < 5)
            {
                answer += StoreyVec[i];
            }
            else
            {
                answer += 10 - StoreyVec[i];
                StoreyVec[i - 1] += 1;
            }
        }
    }
    
    answer += StoreyVec[0];
    
    return answer;
}