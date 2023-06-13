//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        
        unordered_map<int,int> mpp;
        Node* curr2 = head2;
        Node* curr1 = head1;
        Node* ans = new Node(0);
        Node* anstail = ans;
        
        while(curr2){
            mpp[curr2->data]+=1;
            curr2 = curr2->next;
        }
        
        while(curr1){
            if(mpp.find(curr1->data)!=mpp.end())
            {
                mpp[curr1->data]--;
                if(mpp[curr1->data]==0){
                    mpp.erase(curr1->data);
                }
                anstail->next = curr1;
                curr1 = curr1->next;
                anstail = anstail->next;
                anstail->next = NULL;
            }
            else
                curr1 = curr1->next;
        }
        
        return ans->next;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends