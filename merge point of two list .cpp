/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    int c1 = 0, c2 = 0;
    struct Node* temp = headA;
    struct Node* temp1 = headB;
    while(temp != NULL)
    {
        c1++;
        temp = temp->next;
    }
    while(temp1 != NULL)
    {
        c2++;
        temp1 = temp1->next;
    }
    temp = headA;
    temp1 = headB;
    if(c1>c2)
    {
        while(c1-c2 != 0)
        {
            temp = temp->next;
            --c1;
        }
    }
    else
    {
        while(c2-c1 != 0)
        {
            temp1 = temp1->next;
            --c2;
        }
    }
    while(temp->next != temp1->next)
    {
        temp = temp->next;
        temp1 = temp1->next;
    }
    temp = temp->next;
    return temp->data;
}

