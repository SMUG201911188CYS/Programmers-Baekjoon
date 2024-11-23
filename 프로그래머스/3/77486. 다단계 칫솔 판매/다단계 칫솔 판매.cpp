#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int Money;
    string Referral;
};

unordered_map<string, Node> Graph;

void AddNode(const string& Name, const string& ReferralName)
{
    Graph[Name].Referral = ReferralName;
    Graph[Name].Money = 0;
}

void DistributionToReferral(const string& Name, int Revenue)
{
    if(Graph[Name].Referral == "NULL")
    {
        Graph[Name].Money += Revenue;
        //cout << "End : " << Name << " get money : " << Revenue << ", Total : " << Graph[Name].Money << '\n';
        
        return;
    }
    
    int DistributionMoney = Revenue / 10;
    int Money = Revenue - DistributionMoney;
    
    Graph[Name].Money += Money;
    
    //cout << Name << " get money : " << Money << ", Total : " << Graph[Name].Money << '\n';
    
    if(DistributionMoney != 0)
    {
        DistributionToReferral(Graph[Name].Referral, DistributionMoney);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    
    AddNode("-", "NULL");
    
    for(int i = 0; i < enroll.size(); ++i)
    {
        AddNode(enroll[i], referral[i]);
    }
    
    for(int i = 0; i < seller.size(); i++)
    {
        DistributionToReferral(seller[i], amount[i] * 100);
    }
    
    for(int i = 0; i < enroll.size(); i++)
    {
        answer[i] = Graph[enroll[i]].Money;
    }
    
    return answer;
}