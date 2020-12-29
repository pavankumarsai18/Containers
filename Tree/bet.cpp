#include <stack>
#include <string>
#include <iostream>
#include "bet.h"
using namespace std;

BET::BinaryNode::BinaryNode()
{
    //Countructor of a binaryNode
    val = "";
    left = nullptr;
    right = nullptr;
}

BET::BET()
{
    root = nullptr;
}


BET::BET(const string& postfix)
{
    //If the given postfix expression is a wrong one then we simply print
    // Wrong postfix expression and create a empty tree
    if(!check_postfix(postfix))
    {
        cout<<"Wrong postfix expression"<<endl;
        root = nullptr;
    }
    
    // if the given postfix is a valid string
    // then we use a stack based algorithm
    // if we encounter an operator we push a tree  with a single node whose value is postfix[i]
    // onto stack
    // if we encounter an operato we pop two items and create a tree with
    // root as operator and the left and right children as the poped items
    else
    {
        if(postfix.size() > 0)
        {
            stack<BET> tree_stack;
            for(int i = 0; i < postfix.size(); i++)
            {
                if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
                {
                    BET* A = new BET(tree_stack.top());
                    tree_stack.pop();
                    BET* B = new BET(tree_stack.top());
                    tree_stack.pop();
                    
                    BET* C = new BET();
                    string temp = ""; // temp = ""
                    temp += postfix[i]; // temp = "" + "+" = "+"
                    
                    BinaryNode * c = new BinaryNode();
                    c->val = temp;
                    
                    C->root = c;
                    C->root->right = A->root;
                    C->root->left = B->root;
                    
                    tree_stack.push(*C);
                    
                }
                else if(postfix[i] == ' ')
                    ;
                else
                {
                    string temp = "";
                    while(i < postfix.size() && postfix[i] != ' ')
                    {
                        temp += postfix[i];
                        i++;
                    }
                    BET* var = new BET();
                    BinaryNode* n = new BinaryNode();
                    n->val = temp;
                    var->root = n;
                    tree_stack.push(*var);
                }
            }
            root = clone(tree_stack.top().root);
            makeEmpty(tree_stack.top().root);
            tree_stack.pop();
        }
    }
}

BET::BET(const BET& tree)
{
    //clones or copies the tree recursively
    root = clone(tree.root);
}

BET::~BET()
{
    //Empties the tree and sets the root to nullptr
    makeEmpty(root);
    root = nullptr;
    
}

bool BET::buildFromPostfix(const string& postfix)
{
     //we check if the tree is a valid postfix
    if(!check_postfix(postfix))
    {
        cout<<"Wrong postfix expression"<<endl;
        return false;
    }
    //clears the tree
    makeEmpty(root);
    //builds a tree based on postfix expression
    BET temp(postfix);
    *this = temp; //assignment overload
    return true;
}

const BET& BET::operator= (const BET & tree)
{
    //clones the tree
    this->root = clone(tree.root);
    return *this;
}

void BET::printInfixExpression() const
{
    // If the tree is empty we do not print anything
    if(size() == 0)
    {
        return;
    }
    //else if the tree has nodes in it
    // we print the left child then our value then the right child
    // L Parent R
    printInfixExpression(root);
    cout<<endl;
    
}


void BET::printPostfixExpression() const
{
    // If the tree is empty we do not print anything
    if(size() == 0)
    {
        return;
    }
    //else if the tree has nodes in it
    // we print the left child then right child then our value
    //L R parent
    printPostfixExpression(root);
    cout<<endl;
}


size_t BET::size() const
{
    //returns the size of the tree
    return size(root);
}

size_t BET::leaf_nodes() const
{
    //returns the number of leaf nodes
    return leaf_nodes(root);
}

bool BET::empty() const
{
    //if the tree is empty the root should be null
    return root == nullptr;
}


void BET::printPostfixExpression(BinaryNode *n) const
{
    // We implement a recursive function
    // where we print the Left child then the right child the node value
    if(n == nullptr)
        return;
    
    if(n->left != nullptr)
        printPostfixExpression(n->left);
    
    if(n->right != nullptr)
        printPostfixExpression(n->right);
    cout<<n->val<<" ";
    
    return;
}

void BET::makeEmpty(BinaryNode* &t)
{
    //does a postorder traversal
    // because we need to delete the children befor the parent
    if(t != nullptr)
    {
        if(t ->left != nullptr)
            makeEmpty(t->left);
        if(t ->right != nullptr)
            makeEmpty(t->right);
        
        delete t;
        t = nullptr;
    
    }
    return;
}


BET::BinaryNode* BET::clone(BinaryNode *t) const
{
    
    if(t == nullptr)
        return nullptr;
    
    //we clone in pre order traversa;
    // because we need to create children before the parent
    BinaryNode* Node = new BinaryNode();

    if(t->left != nullptr)
        Node->left = clone(t->left);
    if(t->right != nullptr)
        Node->right = clone(t->right);
    
    Node->val = t->val;
    return Node;
}


void BET::printInfixExpression(BinaryNode *n) const
{
   //Print infix print parenthtesis whenever required
    
    bool paren_req = false;
    if(n == nullptr)
        return;
    
    if(n->left != nullptr)
    {
        if(is_operator(n->val) && is_operator((n->left)->val ))
        {
            if(higher_prec(n->val, n->left-> val))
            {
               
                    paren_req = true;
                    cout << "( ";
            }
        }
        
        printInfixExpression(n->left);
        if(paren_req)
        {
            cout<<") ";
        }
    }
    paren_req = false;
    
    cout<<n->val<<" ";
    
    if(n->right != nullptr)
    {
        if(is_operator(n->val) && is_operator((n->right)->val ))
        {
            if(precedence(n->val, n->right->val) )
            {
                paren_req = true;
                cout << "( ";
            }
        }
        printInfixExpression(n->right);
        
        if(paren_req)
        {
            cout<<") ";
        }
        
    }
}


size_t BET::size(BinaryNode *t) const
{
    //count the number of nodes
    //we add 1 recursively till we hit a nullptr
    if(t == nullptr)
        return 0;
    
    size_t result = 0;
    result = 1;
    result += size(t->left) + size(t->right);
    return result;
}


size_t BET::leaf_nodes(BinaryNode *t) const
{
    //count the leaf nodes
    // if we enconuter a node with no left and right child we increase the
    // leaf_nodes count by
    size_t result = 0;
    if(t-> left == nullptr && t->right == nullptr)
        return 1;
    
    result += leaf_nodes(t->left) + leaf_nodes(t->right);
    return result;
    
}

bool BET::precedence(const string& a, const string& b) const // >=
{
    // returns true if operator a has higher or equal precendence to operator b
    if( (a == "+" || a == "-") && (b == "+"  || b == "-") )
        return true;
    else if(a == "*" || a == "/")
        return true;
    return false;
}

bool BET::is_operator(const string& a) const // >=
{
    //returns true if the string is an operator
    if( a == "+" || a == "-" || a == "*" || a == "/")
        return true;
    return false;
}


bool BET::check_postfix(const string & postfix) const
{
    //checks if the given string is a vlid postfix or not
    // we use a stack based algorith to check for a valid postfix string
    //if we encounter an operand we push it into the stack
    // if we encounter an operator we pop two operands and push "X"
    //at the end if we have one element in the stack the string given is valid else it is invalid
    stack<string> postfix_checker;
    for(int i = 0; i < postfix.size(); i++)
    {
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            if(postfix_checker.size() >= 2)
            {
                postfix_checker.pop();
                postfix_checker.pop();
                postfix_checker.push("X");
            }
            else
            {
                return false;
            }
        }
        else if(postfix[i] == ' ')
            ;
        else
        {
            string temp = "";
            while(i < postfix.size() && postfix[i] != ' ')
            {
                temp += postfix[i];
                i++;
            }
            postfix_checker.push(temp);
        }
    }
    if(postfix_checker.size() != 1)
        return false;
    return true;
}

bool BET::higher_prec(const string& a, const string& b) const
{
    //return strue if operator a has higher precedence than operator b
    if(a == "+" || a == "-")
        return false;
    if((a == "*" || a == "/") && (b != "*" && b!= "/"))
        return true;
    return false;
} // >

