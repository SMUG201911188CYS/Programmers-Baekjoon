#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    queue<pair<string, string>> q;
    
    string message[2] = {"님이 들어왔습니다.", "님이 나갔습니다."};
    
    for(int i = 0; i < record.size(); i++)
    {
        string command;
        string user_id;
        string nickname;
        
        istringstream ss(record[i]);
        ss >> command >> user_id >> nickname; 
        
        //cout << command << ", " << user_id << ", " << nickname << '\n';
        
        if(command == "Enter")
        {
            if(m.count(user_id) == 0)
            {
                //cout << "1" << '\n';
                m[user_id] = nickname;
            }
            else if(m[user_id] != nickname)
            {
                //cout << "2" << '\n';
                m[user_id] = nickname;
            }
        }
        else if(command == "Change")
            m[user_id] = nickname;
        
        if(command != "Change")
            q.emplace(command, user_id);
    }
    
    
    while(!q.empty())
    {
        string command = q.front().first;
        string user_id = q.front().second;
        
        q.pop();
        
        if(command == "Enter")
        {            
            //cout << m[user_id] << "님이 들어왔습니다." << '\n';
            answer.push_back(m[user_id] + message[0]);
        }
        else if(command == "Leave")
        {
            //cout << m[user_id] << "님이 나갔습니다." << '\n';
            answer.push_back(m[user_id] + message[1]);
        }
        
        
        
    }
    
    return answer;
}