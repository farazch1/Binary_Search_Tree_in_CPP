//
//  main.cpp
//  BST
//
//  Created by Mian Muhammad Faraz  on 10/4/2023
//  Updated on 21/4/2023
//  Copyright Â© 2023 Mian Muhammad Faraz . All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/////////////////BST

class treeNode
{
public:
    treeNode * left;
    treeNode * right;
    string  data;
    treeNode* parent;
};


class BST
{

public:

    treeNode * root;

    BST()
    {
        root=NULL;
    }

    ////////// Inorder Traversal

    void InorderTraverse(treeNode *n )
    {
        if (n!=NULL)
        {
            InorderTraverse(n->left);
            cout<<n->data<<"\t";
            InorderTraverse(n->right);
        }
    }

    ////////// Postorder Traversal

    void PostorderTraverse(treeNode *n)
    {
        if(n!=NULL)
        {
            PostorderTraverse(n->left);
            PostorderTraverse(n->right);
            cout<<n->data<<"\t";
        }
    }

    ////////// Preorder Traversal

    void PreorderTraverse(treeNode * n)
    {
        if(n!=NULL)
        {
            cout<<n->data<<"\t";
            PreorderTraverse(n->left);
            PreorderTraverse(n->right);

        }
    }

    ////////// Insert in Tree

    void insert( string m)
    {
        treeNode *z=new treeNode();
        z->data=m;
        z->left=NULL;
        z->right=NULL;

        treeNode *y=NULL;
        treeNode *x=root;

        while(x!=NULL)
        {

            y=x;
            if(x->data.compare(z->data)>0)
                x=x->left;
            else
                x=x->right;

        }

        z->parent=y;
        if(root==NULL)
            root=z;
        else if(y->data.compare(z->data)<0)
            y->right=z;
        else
            y->left=z;
    }


    ////////// Min Tree

    string TreeMin(treeNode* x=NULL)
    {
        if (x==NULL)         //  to make function usable for both kind of function calls use in this code
            x=root;
        while(x->left !=NULL)
            x=x->left;
        return x->data;
    }

    ////////// Max Tree

    string TreeMax(treeNode* x=NULL)
    {
        if (x==NULL)         //  to make function usable for both kind of function calls use in this code
            x=root;
        while(x->right !=NULL)
            x=x->right;
        return x->data;
    }


    /////////// Tree Search


    string search(string s)
    {
        if (root == NULL)
        {
            return "Tree is empty!";
        }
        treeNode* curr = root;
        while (curr != NULL)
        {
            if (curr->data == s)
            {
                return "Found!";
            }
            else if (curr->data > s)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        return "Not found!";
    }


    ////////// Predecessor of x

    string Predecessor(string s)
    {
        treeNode* curr = root;
        treeNode* target = NULL;
        treeNode* pred = NULL;

        while (curr != NULL)
        {
            if (curr->data == s)
            {
                target = curr;
                break;
            }
            else if (curr->data > s)
            {
                curr = curr->left;
            }
            else
            {
                pred = curr;
                curr = curr->right;
            }
        }
        if (target == NULL)
        {
            return "String not found in tree";
        }

        if (target->left != NULL)
        {
            treeNode* curr = target->left;
            while (curr->right != NULL)
            {
                curr = curr->right;
            }
            pred = curr;
        }
        else
        {
            pred = target->parent;
            while (pred != NULL && target == pred->left)
            {
                target = pred;
                pred = pred->parent;
            }
        }
        if (pred == NULL)
        {
            return "No predecessor found";
        }
        return pred->data;
    }


    ////////// Successor of x


    string Successor(string s)
    {
        treeNode* curr = root;
        treeNode* target = NULL;
        treeNode* succ = NULL;
        while (curr != NULL)
        {
            if (curr->data == s)
            {
                target = curr;
                break;
            }
            else if (curr->data > s)
            {
                succ = curr;
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (target == NULL)
        {
            return "String not found in tree";
        }
        if (target->right != NULL)
        {
            treeNode* curr = target->right;
            while (curr->left != NULL)
            {
                curr = curr->left;
            }
            succ = curr;
        }
        else
        {
            succ = target->parent;
            while (succ != NULL && target == succ->right)
            {
                target = succ;
                succ = succ->parent;
            }
        }
        if (succ == NULL)
        {
            return "No successor found";
        }
        return succ->data;
    }


    ////////// Delete from tree

    string deleteT(string x)
    {
        if (root == NULL)
        {
            return "Tree is empty!";
        }

        treeNode* curr = root;
        while (curr != NULL)
        {
            if (curr->data == x)
            {
                // Found the node to be deleted

                if (curr->left == NULL && curr->right == NULL)
                {
                    // Case 1: Node with no children
                    if (curr->parent == NULL)
                    {
                        // Node is root
                        root = NULL;
                    }
                    else if (curr->parent->left == curr)
                    {
                        // Node is left child of parent
                        curr->parent->left = NULL;
                    }
                    else
                    {
                        // Node is right child of parent
                        curr->parent->right = NULL;
                    }
                    delete curr;
                    return "Node deleted!";
                }
                else if (curr->left == NULL && curr->right != NULL)
                {
                    // Case 2: Node with only a right child
                    if (curr->parent == NULL)
                    {
                        // Node is root
                        root = curr->right;
                        curr->right->parent = NULL;
                    }
                    else if (curr->parent->left == curr)
                    {
                        // Node is left child of parent
                        curr->parent->left = curr->right;
                        curr->right->parent = curr->parent;
                    }
                    else
                    {
                        // Node is right child of parent
                        curr->parent->right = curr->right;
                        curr->right->parent = curr->parent;
                    }
                    delete curr;
                    return "Node deleted!";
                }
                else if (curr->left != NULL && curr->right == NULL)
                {
                    // Case 3: Node with only a left child
                    if (curr->parent == NULL)
                    {
                        // Node is root
                        root = curr->left;
                        curr->left->parent = NULL;
                    }
                    else if (curr->parent->left == curr)
                    {
                        // Node is left child of parent
                        curr->parent->left = curr->left;
                        curr->left->parent = curr->parent;
                    }
                    else
                    {
                        // Node is right child of parent
                        curr->parent->right = curr->left;
                        curr->left->parent = curr->parent;
                    }
                    delete curr;
                    return "Node deleted!";
                }
                else
                {
                    // Case 4: Node with two children
                    // Find the inorder successor of curr
                    treeNode* inorderSuccessor = curr->right;
                    while (inorderSuccessor->left != NULL)
                    {
                        inorderSuccessor = inorderSuccessor->left;
                    }
                    // Copy the value of inorder successor to curr
                    curr->data = inorderSuccessor->data;
                    // Delete the inorder successor node recursively
                    return deleteT(inorderSuccessor->data);
                }
            }
            else if (curr->data > x)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        return "Node not found!";
    }

};

int main()
{
    BST St;
    St.insert("pat");
    St.insert("use");
    St.insert("zoo");
    St.insert("try");
    St.insert("bat");
    St.insert("hay");
    St.insert("key");
    St.insert("jig");
    St.insert("tab");

    cout<<"TreeMin"<<endl;
    cout<<St.TreeMin()<<endl;


    cout<<"TreeMax"<<endl;
    cout<<St.TreeMax()<<endl;



    cout<<"Search Tree "<<endl;

    cout<<St.search("bat")<<endl;


    cout<<"Predecessor"<<endl;
    cout<<St.Predecessor("pat")<<endl;

    cout<<"Successor"<<endl;
    cout<<St.Successor("pat")<<endl;


    treeNode * oi= St.root;

    cout<<"PreOrder Traversal"<<endl;
    St.PreorderTraverse(oi);
    cout<<endl;

    cout<<"PostOrder Traversal"<<endl;

    St.PostorderTraverse(oi);
    cout<<endl;

    cout<<"InOrder Traversal"<<endl;
    St.InorderTraverse(oi);
    cout<<endl;


    St.deleteT("jig");
    cout<<"Traversal after deleting "<<endl;
    St.InorderTraverse(oi);
    cout<<endl;



    /*   cout<<St.TreeMax()<<endl;




       St.PreorderTraverse();
       cout<<endl;
       St.PostorderTraverse();
       cout<<endl;

       treeNode* sNode=St.search("");
       if(sNode!=NULL)
           cout<<sNode->data<<endl;
       else
           cout<<"Data not found"<<endl;

       St.delete("jig");
       St.InorderTraverse(St.root);
       cout<<endl;

       St.delete("bat");
       St.InorderTraverse(St.root);
       cout<<endl;

       St.delete("use");
       St.InorderTraverse(St.root);
       cout<<endl;
*/

}

