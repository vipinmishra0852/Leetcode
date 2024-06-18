/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
       ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Node *dummy = new Node(100);
    Node *tempC = dummy;
    Node *temp = head;

    while (temp)
    {
      Node *a = new Node(temp->val);
      tempC->next = a;
      tempC = tempC->next;
      temp = temp->next;
    }
    Node *b = dummy->next;
    Node* a = head ;
    unordered_map<Node*,Node*>m;
    Node* tempA=a;
    Node* tempB=b;
    while(tempA!=NULL)
    {
        m[tempA] = tempB;
        tempA = tempA -> next;
        tempB = tempB -> next;
    }
    for(auto i:m)
    {
        Node* o = i.first;
        Node* d = i.second;
        if(o->random!=NULL)
        {
           Node* oRandom = o->random;
           Node* dRandom = m[oRandom] ; 
           d->random = dRandom;
        }
    }
    return b;
    }
};