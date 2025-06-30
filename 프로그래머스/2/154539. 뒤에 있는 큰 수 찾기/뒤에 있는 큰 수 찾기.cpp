#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    vector<int> Index(numbers.size(), -1);
    int MaxValue = -1;
    int MaxValueIndex = 0;
    for(int i = numbers.size() - 1; i >= 0; i--)
    {
        //cout << "current : " << numbers[i] << '\n';
        if(numbers[i] >= MaxValue)
        {
            //cout << numbers[i] << " is bigger than " << MaxValue << '\n';
            MaxValue = numbers[i];
            answer[i] = -1;
            Index[i] = i;
            MaxValueIndex = i;
            //cout << "Max index : " << MaxValueIndex << '\n';
        }
        else
        {
            //cout << numbers[i] << " is smaller than " << MaxValue << '\n';
            
            for(int j = i + 1; j <= MaxValueIndex;)
            {
                //cout << "current index : " << j << ", Value : " << numbers[j] << '\n';
                if(numbers[i] < numbers[j])
                {
                    //cout << "find : " << numbers[i] << ", " << numbers[j] << '\n';
                    answer[i] = numbers[j];
                    Index[i] = j;
                    break;
                }
                else
                {
                    j = Index[j];
                    //cout << "change Index : " << j << '\n';
                }
            }
        }
    }
    return answer;
}