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

// Naive Method
//  Node *insert_begin(Node *head, int val)
//  {
//      Node *temp = new Node(val);
//      if (head == NULL)
//      {
//          temp->next = temp;
//      }
//      else
//      {
//          Node *curr = head;
//          while (curr != NULL && curr->next != head)
//          {
//              curr = curr->next;
//          }
//          curr->next = temp;
//          temp->next = head;
//      }

//     return temp;
// }

Node *insert_begin(Node *head, int val)
{
    Node *newHead = new Node(val);
    if (head == NULL)
    {
        newHead->next = newHead;
        return newHead;
    }
    else
    {
        newHead->next = head->next;
        head->next = newHead;
        int d = head->data;
        head->data = newHead->data;
        newHead->data = d;
        return head;
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
    insert_begin(head, 58);
    printList(head);
    return 0;
}

//insert after given position
// void insertAtPosition(Node *head, int pos, int data)
// {
//    Node *temp = new Node(data);
//    Node *current = head;
//    int count = 1;
//    do{
//        if(count == pos){
//            temp->next = current->next;
//            current->next = temp;
//        }
//        count++;
//        current = current->next;
//    }while(current != head);
   
// }