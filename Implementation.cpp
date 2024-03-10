#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *head)
{
    if(head==NULL){
        return;
    }
    Node*curr=head;
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr!=head);
}
int main()
{
    Node *head = new Node(45);
    head->next = new Node(54);
    head->next->next = new Node(65);
    head->next->next->next = head;
    printList(head);
    return 0;
}