#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data)
    {
        this->data=data;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree{
    public:
    struct TreeNode *root;
    BinarySearchTree(){
        root = NULL;
    }
    TreeNode* insert(TreeNode *, int);
    TreeNode* remove(TreeNode *, int);
    TreeNode* getSuccessor(TreeNode *);
    bool search(TreeNode *, int);
    void preorder(TreeNode *);
    void inorder(TreeNode *);
    void postorder(TreeNode *);
    void levelorder(TreeNode *);
    int getSize(TreeNode *);
    int getMax(TreeNode *);
    int getHeight(TreeNode *);
};

TreeNode* BinarySearchTree::insert(TreeNode *root, int element)
{
    if(root==NULL)
    {
        return new TreeNode(element);
    }
    //initially returned pointer from insert function is assigned to root->left 
    //but then element will inserted at root->left when root->left becomes NULL
    //by creating new root with given element using above function
    if(element<root->data)
    {
        root->left = insert(root->left, element);
    }
    else
    {
        root->right = insert(root->right, element); 
    }
    return root;
} 

TreeNode* BinarySearchTree::remove(TreeNode *root, int element)
{
    if(root==NULL)
    {
        return root;
    }
    if(element<root->data)
    {
        root->left = remove(root->left, element);
    }
    else if(element>root->data)
    {
        root->right = remove(root->right, element); 
    }
    //root->data==element
    else
    {   
        //root with a single child & zero children
        if(root->left==NULL)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        //root with both children
        else
        {
            TreeNode *succ = getSuccessor(root);
            root->data =  succ->data;
            root->right = remove(root->right, succ->data);
        }
    }
    return root;
}

//closest greater value =  left most leaf of right child
TreeNode* BinarySearchTree::getSuccessor(TreeNode *root)
{
    root = root->right;
    while(root!= NULL && root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}

void BinarySearchTree::preorder(TreeNode *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BinarySearchTree::inorder(TreeNode *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void BinarySearchTree::postorder(TreeNode *root)
{   
    if(root!=NULL)
    {
        postorder(root->left);
        postorder (root->right);
        cout<<root->data<<" ";
    }
}

bool BinarySearchTree::search(TreeNode* root, int element)
{
    if(root==NULL || root->data == element)
    {
        return root;
    }
    if(root->data>element)
    {
        return search(root->left, element);
    }
    else
    {
        return search(root->right, element);
    }
}

int BinarySearchTree::getSize(TreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return 1+getSize(root->left)+getSize(root->right);
    }
}

int BinarySearchTree::getMax(TreeNode *root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    else
    {   
        // finding max of 2 elememnts and then 3 elemtns
        int maximum= max(root->data, getMax(root->left));
        return max(maximum, getMax(root->right)); 
    }
}

int BinarySearchTree::getHeight(TreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else  
    {
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
}

int main() {
    BinarySearchTree bst;
    bst.root=bst.insert(bst.root, 0); // initially inserting 0 as root node
    int choice, element;
    bool result = false;
    while (1) {
        cout << endl<<endl;
        cout << " Binary Search Tree Operations " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 1. Insert Element " << endl;
        cout << " 2. Remove Element " << endl;
        cout << " 3. Pre-Order Traversal " << endl;
        cout << " 4. In-Order Traversal " << endl;
        cout << " 5. Post-Order Traversal " << endl;
        cout << " 6. Find Element" << endl;
        cout << " 7. Find Size of BST" << endl;
        cout << " 8. Find Maximum Element in BST" << endl;
        cout << " 9. Find Height of BST" << endl;
        cout << " 0. Exit " << endl;
        cout << " Enter your choice : ";
        cin>>choice;
        switch (choice) {
            case 1: cout << " Enter number to be inserted : ";
                cin>>element;
                bst.insert(bst.root, element);
                break;
            case 2: cout << " Enter number to be deleted : ";
                cin>>element;
                bst.remove(bst.root, element);
            case 3: cout << endl;
                cout << " Pre-Order Traversal " << endl;
                cout << " -------------------" << endl;
                bst.preorder(bst.root);
                break;
            case 4: cout << endl;
                cout << " In-Order Traversal " << endl;
                cout << " -------------------" << endl;
                bst.inorder(bst.root);
                break;
            case 5: cout << endl;
                cout << " Post-Order Traversal " << endl;
                cout << " --------------------" << endl;
                bst.postorder(bst.root);
                break;
            case 6: cout << " Enter number to be search : ";
                cin>>element;
                result = bst.search(bst.root, element);
                if(result) cout<<"Element is found."<<endl;
                else cout<<"Element is not found."<<endl;
                break;
            case 7: cout << " Size of the BST is : "<<bst.getSize(bst.root);
                break;
            case 8: cout << " Maximum element in BST is : "<<bst.getMax(bst.root);
                break;
            case 9: cout << " Height of the BST is : "<<bst.getHeight(bst.root);
                break;
            case 0: exit(0);
            default: cout<<"Try again, wrong choice entered!"<<endl;
        }
    }
}