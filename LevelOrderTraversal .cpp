
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/
void print(node* root, int level)
{
    if(root == NULL)
        return;
    else if(level == 1)
        cout<<root->data<<" ";
    else if(level > 1)
    {
        print(root->left, level-1);
        print(root->right, level-1);
    }
}
int height(node* root)
{
    if(root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh > rh)
        return lh+1;
    else
        return rh+1;
}
void levelOrder(node * root) 
{
    int h = height(root);
    int i;
    for(i = 1; i<=h ;i++)
        print(root, i);
}


