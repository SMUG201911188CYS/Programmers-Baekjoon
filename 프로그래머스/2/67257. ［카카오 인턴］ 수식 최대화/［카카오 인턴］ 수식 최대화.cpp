#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    Node * next_node;
    long long value;
    char opr;
};

class LinkedList
{
private:
    Node * head;
    Node * tail;
public:
    LinkedList() : head(NULL), tail(NULL) {}
    ~LinkedList()
    {
        while(head != NULL)
        {
            Node * temp = head->next_node;
            //cout << head->value << "is delete."  << '\n';
            delete head;
            head = temp;
        }
    }
    void insert_node(Node * prev_node, long long n, char opr)
    {
        Node * temp = new Node;
        
        temp->value = n;
        temp->opr = opr;
        temp->next_node = prev_node->next_node;
        prev_node->next_node = temp;
    }

    void add_node(long long n, char opr)
    {
        Node * temp = new Node;

        temp->value = n;
        temp->opr = opr;
        temp->next_node = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail-> next_node = temp;
            tail = temp;
        }
    }

    void delete_node(Node * target)
    {
        //cout << "Delete target : " << target->value << '\n';
        if(target == head)
        {
            Node * temp = head;
            head = head->next_node;
            delete temp;
        }
        else
        {
            Node * target_prev = circuit_node(target, head);

            Node * temp = target_prev->next_node;
            target_prev->next_node = temp->next_node;
            delete temp;
        }
    }

    Node * circuit_node(Node * target, Node * temp)
    {
        if(temp->next_node == target)
            return temp;
        else
            return circuit_node(target, temp->next_node);
    }

    void cal(Node * temp, char opr)
    {
        if(temp == NULL)
        {
            //cout << "cal end. " << '\n';
            return;
        }
        
        if(temp->opr == opr)
        {
            //cout << "cal start : " << temp->value << ", " << temp->next_node->value << ", " << temp->opr << '\n';
            
            if(opr == '*')
                temp->next_node->value *= temp->value;
            else if(opr == '-')
                temp->next_node->value = temp->value - temp->next_node->value;
            else
                temp->next_node->value = temp->value + temp->next_node->value;

            Node * next = temp->next_node;
            
            delete_node(temp);
            
            /*if(next->next_node != NULL)
                cout << "cal end : " << next->value << ", next node : " << next->next_node->value << '\n';
            else
                cout << "cal end : " << next->value << ", next node : NULL" << '\n';
            */
            cal(next, opr);
        }
        else
        {
            cal(temp->next_node, opr);
        }
    }
    
    void print_list(Node * temp)
    {
        if(temp == NULL)
            cout << '\n';
        else
        {
            cout << temp->value << " " << temp->opr << ", ";
            print_list(temp->next_node);
        }
    }

    Node * get_head() { return head;}
    Node * get_tail() { return tail;}
    
};

long long solution(string expression) {
    long long answer = 0;
    vector<char> opr;
    vector<char> opr_list;
    vector<long long> exp;

    string temp;

    if(expression.find('+') != -1)
        opr.push_back('+');
    if(expression.find('-') != -1)
        opr.push_back('-');
    if(expression.find('*') != -1)
        opr.push_back('*');
    
    for(int i = 0; i < expression.length(); i++)
    {
        if(expression[i] <= '9' && expression[i] >= '0')
            temp += expression[i];
        else
        {
            exp.push_back(stoll(temp));
            opr_list.push_back(expression[i]);
            //list.add_node(stoll(temp), expression[i]);
            temp = "";
        }
        
    }
    exp.push_back(stoll(temp));
    opr_list.push_back(' ');
    
    sort(opr.begin(), opr.end());
    
    do
    {
        LinkedList list;
        
        for(int i = 0; i < exp.size(); i++)
        {
            list.add_node(exp[i], opr_list[i]);
        }
        
        temp = "";
        
        for(auto it = opr.begin(); it != opr.end(); ++it)
            temp += *it;
        
        for(int i = 0; i < 3; i++)
        {
            list.cal(list.get_head(), temp[i]);
        }
        
        long long result;
            
        if(list.get_head()->value < 0)
        {
            result = list.get_head()->value * -1;
        }
        else
        {
            result = list.get_head()->value;
        }
        //list.print_list(list.get_head());
            
        if(result >= answer)
            answer = result;
        
    }while(next_permutation(opr.begin(), opr.end()));

    cout << answer << '\n';
    
    return answer;
}