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
Node *delete_head(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

Node *delete_K(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (k == 1)
    {
        return delete_head(head);
    }
    Node *temp1 = head;
    for (int i = 0; i < k - 2; i++)
    {
        temp1 = temp1->next;
    }
    Node *temp = temp1->next;
    temp1->next = temp1->next->next;
    delete temp;
    return head;
}
int main()
{
    Node *head = new Node(45);
    head->next = new Node(54);
    head->next->next = new Node(65);
    head->next->next->next = new Node(75);
    head->next->next->next->next = head;
    delete_K(head,3);
    printList(head);
    return 0;
}