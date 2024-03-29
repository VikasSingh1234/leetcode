//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* curr = head;
        Node* zero = new Node(0);
        Node* one = new Node(1);
        Node* two = new Node(2);
        
        Node* zerotail = zero;
        Node* onetail = one;
        Node* twotail = two;
        
        while(curr){
            if(curr->data==0){
                zerotail->next = curr;
                curr = curr->next;
                zerotail = zerotail->next;
                zerotail->next = NULL;
            }
            else if(curr->data==1){
                onetail->next = curr;
                curr = curr->next;
                onetail = onetail->next;
                onetail->next = NULL;
            }
            else{
                twotail->next = curr;
                curr = curr->next;
                twotail = twotail->next;
                twotail->next = NULL;
            }
        }
        zero = zero->next;
        one = one->next;
        two = two->next;
        if(zero!=NULL){
            if(one!=NULL){
                zerotail->next = one;
                onetail->next = two;
            }
            else{
                zerotail->next = two;
            }
            return zero;
        }
        else if(one!=NULL){
            onetail->next = two;
            return one;
        }
        else{
            return two;
        }
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends