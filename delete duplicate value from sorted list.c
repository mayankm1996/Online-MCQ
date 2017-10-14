/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  struct Node* temp = head;
  while(temp != NULL && temp->next != NULL)
  {
      struct Node* temp1 = temp->next;
      if(temp->data == temp1->data)
      {
          temp->next = temp1->next;
            free(temp1);
      }
      else
      {
          temp = temp->next;
      }
  }
    return head;
}

