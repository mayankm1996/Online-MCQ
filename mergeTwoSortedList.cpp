/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
    // This is a "method-only" submission. 
    // You only need to complete this method
    if(headA == NULL) return headB;
    if(headB == NULL) return headA;
    
    Node *mergedHead = NULL;
    Node* current = NULL;
    
    while(headA != NULL && headB != NULL)
    {
        if(headA->data <= headB->data) {
            if(mergedHead == NULL) {
                mergedHead = headA;
                current = headA;
            }
            else {
                current->next = headA;
                current = current->next;
            }
            headA = headA->next;
        }
        else {
            if(mergedHead == NULL) {
                mergedHead = headB;
                current = headB;
            }
            else {
                current->next = headB;
                current = current->next;
            }
            headB = headB->next;
        }
    }
    
    if(headA != NULL)
        current->next = headA;
    
    if(headB != NULL)
        current->next = headB;
    
    return mergedHead;
    
}

