
// Pavan Vadrevu
// Assignment 4
// 10/22/2019

#ifndef BET_h
#define BET_h
using namespace std;

class BET{
public:
    //BinaryNode
    struct BinaryNode
    {
        string val;
        BinaryNode* left;
        BinaryNode* right;
        //constructor
        BinaryNode();
    };
    
    //default zero-parameter constructor. Builds an empty tree.
    BET();
    
    //one-parameter constructor, where parameter "postfix" is string containing a postfix expression.
    //The tree should be built based on the postfix expression.
    //Tokens in the postfix expression are separated by spaces.
    BET(const string& postfix);
    
    //: copy constructor -- makes appropriate deep copy of the tree
    BET(const BET&);
    
    //: destructor -- cleans up all dynamic space in the tree
    ~BET();
    
    //: parameter "postfix" is string containing a postfix expression.
    //The tree should be built based on the postfix expression.
    //Tokens in the postfix expression are separated by spaces.
    //If the tree contains nodes before the function is called, you need to first delete the existing nodes.
    //Return true if the new tree is built successfully. Return false if an error is encountered.
    bool buildFromPostfix(const string& postfix);
    
    //: assignment operator -- makes appropriate deep copy
    const BET & operator= (const BET &);
    
    //: Print out the infix expression. Should do this by making use of the private (recursive) version
    void printInfixExpression() const;
    
    //: Print the postfix form of the expression. Use the private recursive function to help
    void printPostfixExpression() const;
    
    //: Return the number of nodes in the tree (using the private recursive function)
    size_t size() const;
    
    //: Return the number of leaf nodes in the tree. (Use the private recursive function to help)
    size_t leaf_nodes() const;
    
    //: return true if the tree is empty. Return false otherwise
    bool empty() const;
    
private:
    // outputs true if a has a higher or equal precedence with its child
    bool precedence(const string& a, const string& b) const;
    
    // outputs true if a is an operator
    bool is_operator(const string& a) const;
    
    //: print to the standard output the corresponding infix expression.
    //Note that you may need to add parentheses depending on the precedence of operators.
    //You should not have unnecessary parentheses.
    void printInfixExpression(BinaryNode *n) const;
    
    //: delete all nodes in the subtree pointed to by t.
    void makeEmpty(BinaryNode* &t);
    
    //: clone all nodes in the subtree pointed to by t.
    //Can be called by functions such as the assignment operator=.
    BinaryNode * clone(BinaryNode *t) const;
    
    
    //: print to the standard output the corresponding postfix expression.
    void printPostfixExpression(BinaryNode *n) const;
    
    //: return the number of nodes in the subtree pointed to by t.
    size_t size(BinaryNode *t) const;
    
    //: return the number of leaf nodes in the subtree pointed to by t.
    size_t leaf_nodes(BinaryNode *t) const ;
    
    //checks if the given string is a valid postfix
    bool check_postfix(const string& postfix) const;
    
    //returns true if operator a has higher precedence that operator b
    bool higher_prec(const string& a, const string& b) const;
    
    //member data
    BinaryNode* root;
    
};

#endif /* BET_h */
