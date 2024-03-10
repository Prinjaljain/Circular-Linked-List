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
//Naive Method
// Node *insert_end(Node *head, int val)
// {
//     Node *tail = new Node(val);
//     if (head == NULL)
//     {
//         tail->next = tail;
//         return tail;
//     }
//     else
//     {
//         Node*curr=head;
//         while(curr->next!=head){
//             curr=curr->next;
//         }
//         curr->next=tail;
//         tail->next=head;
//         return head;
//     }
// }

Node *insert_end(Node *head, int val)
{
    Node *tail = new Node(val);
    if (head == NULL)
    {
        tail->next = tail;
        return tail;
    }
    else
    {
        tail->next = head->next;
        head->next = tail;
        int d = head->data;
        head->data = tail->data;
        tail->data = d;
        return tail;
    }
}

void printList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}
int main()
{
    Node *head = new Node(45);
    head->next = new Node(54);
    head->next->next = new Node(65);
    head->next->next->next = head;
    head=insert_end(head, 58);
    printList(head);
    return 0;
}