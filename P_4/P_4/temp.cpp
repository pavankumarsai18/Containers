//// Pavan Vadrevu
//// Assignment 4
//// 10/22/2019
//
//#include <stack>
//#include <iostream>
//#include <string>
//using namespace std;
//
//class BET{
//public:
//    struct BinaryNode
//    {
//        string val;
//        BinaryNode* left;
//        BinaryNode* right;
//        //constructor
//        BinaryNode();
//    };
//    BET();
//    //: default zero-parameter constructor. Builds an empty tree.
//
//    BET(const string& postfix);
//    //: one-parameter constructor, where parameter "postfix" is string containing a postfix expression. The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by spaces.
//
//    BET(const BET&);
//    //: copy constructor -- makes appropriate deep copy of the tree
//
//    ~BET();
//    //: destructor -- cleans up all dynamic space in the tree
//
//    bool buildFromPostfix(const string& postfix);
//    //: parameter "postfix" is string containing a postfix expression. The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by spaces. If the tree contains nodes before the function is called, you need to first delete the existing nodes. Return true if the new tree is built successfully. Return false if an error is encountered.
//    const BET & operator= (const BET &);
//    //: assignment operator -- makes appropriate deep copy
//
//    void printInfixExpression() const;
//    //: Print out the infix expression. Should do this by making use of the private (recursive) version
//
//    void printPostfixExpression() const;
//    //: Print the postfix form of the expression. Use the private recursive function to help
//
//    size_t size() const;
//    //: Return the number of nodes in the tree (using the private recursive function)
//
//    size_t leaf_nodes() const;
//    //: Return the number of leaf nodes in the tree. (Use the private recursive function to help)
//
//    bool empty() const;
//    //: return true if the tree is empty. Return false otherwise.
//
//    //Private helper functions (all the required private member functions must be implemented recursively):
//private:
//
//    void printInfixExpression(BinaryNode *n) const;
//    //: print to the standard output the corresponding infix expression. Note that you may need to add parentheses depending on the precedence of operators. You should not have unnecessary parentheses.
//    void makeEmpty(BinaryNode* &t);
//    //: delete all nodes in the subtree pointed to by t.
//
//    BinaryNode * clone(BinaryNode *t) const;
//
//    //: clone all nodes in the subtree pointed to by t. Can be called by functions such as the assignment operator=.
//    void printPostfixExpression(BinaryNode *n) const;
//    //: print to the standard output the corresponding postfix expression.
//
//    size_t size(BinaryNode *t) const;
//    //: return the number of nodes in the subtree pointed to by t.
//
//    size_t leaf_nodes(BinaryNode *t) const ;
//    //: return the number of leaf nodes in the subtree pointed to by t.
//
//    BinaryNode* root;
//
//};
//
//
//
//
//
//
//BET::BinaryNode::BinaryNode()
//{
//    val = "";
//    left = nullptr;
//    right = nullptr;
//}
//
//BET::BET()
//{
//    cout<<"In the default constructor\n";
//    root = nullptr;
//}
////: default zero-parameter constructor. Builds an empty tree.
//BET::BET(const string& postfix)
//{
//    cout<<"In the postfix constructor\n";
//    stack<BET> tree_stack;
//    for(int i = 0; i < postfix.size(); i++)
//    {
//        if(tree_stack.size() != 0)
//            cout<<"size: "<< tree_stack.top().size() << endl;
//
//        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
//        {
//            BET* A = new BET();
//            *A = tree_stack.top();
//            tree_stack.top().printInfixExpression();
//            tree_stack.pop();
//
//            BET* B = new BET();
//            *B = tree_stack.top();
//            tree_stack.top().printInfixExpression();
//            tree_stack.pop();
//
//            BET C;
//            string temp = "";
//            temp += postfix[i];
//            BinaryNode * c = new BinaryNode();
//            c->val = temp;
//            C.root = c;
//            C.root->left = A->root;
//            C.root->right = B->root;
//
//            tree_stack.push(C);
//        }
//        if(postfix[i] == ' ')
//            continue;
//        else
//        {
//            string temp = "";
//            while(i < postfix.size() && postfix[i] != ' ')
//            {
//                temp += postfix[i];
//                i++;
//            }
//
//            cout<<"temp = "<<temp<<endl;
//
//            BET var;
//            BinaryNode* n = new BinaryNode();
//            n->val = temp;
//            var.root = n;
//            var.printInfixExpression();
//            tree_stack.push(var);
//        }
//
//    }
//
//    root = clone(tree_stack.top().root);
//    tree_stack.pop();
//
//
//}
////: one-parameter constructor, where parameter "postfix" is string containing a postfix expression. The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by spaces.
//
//BET::BET(const BET& tree)
//{
//    cout<<"in the tree constructor\n";
//    root = clone(tree.root);
//}
////: copy constructor -- makes appropriate deep copy of the tree
//
//BET::~BET()
//{
//    cout<<"In the destructor\n";
//    makeEmpty(root);
//}
////: destructor -- cleans up all dynamic space in the tree
//
//bool BET::buildFromPostfix(const string& postfix)
//{
//    cout<<"In the buildFromPostfix\n";
//    return true;
//}
////: parameter "postfix" is string containing a postfix expression. The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by spaces. If the tree contains nodes before the function is called, you need to first delete the existing nodes. Return true if the new tree is built successfully. Return false if an error is encountered.
//
//const BET& BET::operator= (const BET & tree)
//{
//    cout<<"In the assignment overload\n";
//    this->root = clone(tree.root);
//    return *this;
//}
////: assignment operator -- makes appropriate deep copy
//
//void BET::printInfixExpression() const
//{
//    cout<<"In the printInfixExpression\n";
//    // L Parent R
//    printInfixExpression(root);
//
//}
////: Print out the infix expression. Should do this by making use of the private (recursive) version
//
//void BET::printPostfixExpression() const
//{
//    cout<<"In the printPostfixExpression\n";
//    //L R parent
//    printPostfixExpression(root);
//}
////: Print the postfix form of the expression. Use the private recursive function to help
//
//size_t BET::size() const
//{
//    cout<<"In the size\n";
//    return size(root);
//}
////: Return the number of nodes in the tree (using the private recursive function)
//
//size_t BET::leaf_nodes() const
//{
//    cout<<"In the leaf_nodes\n";
//    return leaf_nodes(root);
//}
////: Return the number of leaf nodes in the tree. (Use the private recursive function to help)
//
//bool BET::empty() const
//{
//    cout<<"In the empty() function\n";
//    return root == nullptr;
//}
////: return true if the tree is empty. Return false otherwise.
////Private helper functions (all the required private member functions must be implemented recursively):
//
//void BET::printInfixExpression(BinaryNode *n) const
//{
//    cout<<"In recursive printInfixExpression(BinaryNode *n)\n";
//    if(n == nullptr)
//        return;
//
//    if(n->left != nullptr)
//        printInfixExpression(n->left);
//
//    cout<<n->val<<" ";
//
//    if(n->right == nullptr)
//        printInfixExpression(n->right);
//
//    return;
//
//
//}
////: print to the standard output the corresponding infix expression. Note that you may need to add parentheses depending on the precedence of operators. You should not have unnecessary parentheses.
//
//void BET::makeEmpty(BinaryNode* &t)
//{
//    cout<<"In the makeEmpty\n";
//    if(t != nullptr)
//    {
//        if(t ->left != nullptr)
//            makeEmpty(t->left);
//        if(t ->right != nullptr)
//            makeEmpty(t->right);
//
//        delete t;
//        t = nullptr;
//
//    }
//    return;
//}
////: delete all nodes in the subtree pointed to by t.
//
//BET::BinaryNode* BET::clone(BinaryNode *t) const
//{
//    cout<<"In the clone function\n";
//    //prefix traversal
//    BinaryNode* Node = new BinaryNode();
//
//    if(t->left != nullptr)
//        Node->left = clone(t->left);
//    if(t->right != nullptr)
//        Node->right = clone(t->right);
//
//    Node->val = t->val;
//    return Node;
//}
////: clone all nodes in the subtree pointed to by t. Can be called by functions such as the assignment operator=.
//
//void BET::printPostfixExpression(BinaryNode *n) const
//{
//    cout<<"In the printPostfixExpression recursive\n";
//    if(n == nullptr)
//        return;
//
//    if(n->left != nullptr)
//        printInfixExpression(n->left);
//
//    if(n->right == nullptr)
//        printInfixExpression(n->right);
//
//    cout<<n->val<<" ";
//    return;
//}
////: print to the standard output the corresponding postfix expression.
//size_t BET::size(BinaryNode *t) const
//{
//    cout<<"In the recursive size function\n";
//    size_t result = 0;
//    if(t == nullptr)
//        return 0;
//    result = 1;
//    result += size(t->left) + size(t->right);
//    return result;
//}
//
////: return the number of nodes in the subtree pointed to by t.
//size_t BET::leaf_nodes(BinaryNode *t) const
//{
//    cout<<"In the leaf_nodes recursive\n";
//    size_t result = 0;
//    if(t-> left == nullptr && t->right == nullptr)
//        return 1;
//
//    result += leaf_nodes(t->left) + leaf_nodes(t->right);
//    return result;
//
//}
////: return the number of leaf nodes in the subtree pointed to by t.
//
//
//int main()
//{
//    string s = "2 x +";
//    cout<<s<<endl;
//    BET a(s);
//    a.printInfixExpression();
//    return 0;
//}
//
//
//
