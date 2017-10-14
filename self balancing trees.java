   /* Class node is defined as :
    class Node 
       int val;   //Value
       int ht;      //Height
       Node left;   //Left child
       Node right;   //Right child

   */
    int max(int a, int b)
   {
       if(a>b)
           return a;
       else
           return b;
   }
     int height(Node rr)
    {
        if(rr == null)
            return -1;
        else
            return rr.ht;
    }
     int getbalance(Node rr)
    {
            return height(rr.left) - height(rr.right);
    }
    Node newnode(int val)
    {
        Node temp = new Node();
        temp.val = val;
        temp.right = null;
        temp.left = null;
        temp.ht = 0;
        return temp;
    }
     Node rotateright(Node root) {
       Node temp = root.left;
         root.left = temp.right;
         temp.right = root;
         root.ht = 1 + max(height(root.left), height(root.right));
         temp.ht = 1 + max(height(temp.left), height(temp.right));
         return temp;
    }
 
     Node rotateleft(Node root) {
       Node temp = root.right;
         root.right = temp.left;
         temp.left = root;
         root.ht = 1 + max(height(root.left), height(root.right));
         temp.ht = 1 + max(height(temp.left), height(temp.left));
         return temp;
    }
    Node insert(Node root,int val)
    {
       if(root == null)
       {
           return newnode(val);
       }
       else if(root.val > val)
           root.left = insert(root.left, val);
       else if(root.val < val)
           root.right = insert(root.right, val);
       root.ht = 1 + max(height(root.left),height(root.right));      
       
       if(getbalance(root) > 1 && getbalance(root.left) == 1 )
           return rotateright(root);
        else if(getbalance(root) > 1 && getbalance(root.left) == -1 )
       {
           root.left = rotateleft(root.left);
            return rotateright(root);
       }
       else if(getbalance(root) < -1 && getbalance(root.right) == -1 )
           return rotateleft(root);
        else if(getbalance(root) < -1 && getbalance(root.right ) == 1)
        {
            root.right = rotateright(root.right);
            return rotateleft(root);
        }    
       return root;
    }
