#include "stack.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool is_operator(char c);
bool is_operator(string c);
bool is_paren(char c);
bool is_paren(string c);
bool has_higher_precedence(char op1, char op2);

float post_fix_evaluator(const string& s);
float string_to_num(const string & s);


int main()
{
    cop4530::Stack<char> operators; // helps in conversion from infix to postfix
    
    cop4530::Stack<char> paren_matcher; // helps in checkeing balenced parenthesis
    cop4530::Stack<string> infix_checker; // heosin checking whter we have a valid infix expression
    
    string expression;
    string result = "";
    do
    {
        
        bool hasVariables = false;
        bool hasFloats = false;
        bool invalid_infix = false;
        
        //clear the strings
        result = "";
        expression = "";
        
        cout<<"Enter infix expression(\"exit\" to quit): ";
        getline(cin, expression);

        // if the user typed "exit" we quit the program
        if(expression == "exit")
            break;
    
        //else we check if the expression has valid parenthesis
        for(int i = 0; i < expression.size(); i++)
        {
            if(expression[i] == '(')
            {
                paren_matcher.push('(');
            }
            
            else if(expression[i] == ')')
            {
                if(paren_matcher.empty())
                {
                    cout << "Error: Infix expression " << expression << " has mismatched parens!" << endl;
                    break;
                }
                
                else
                {
                    paren_matcher.pop();
                }
            }
        }
        
        //check if size of paren_matcher == 0
        // if it is not empty then we have a mismatched parenthesis
        // and we go back to the top of the loop
        if(!paren_matcher.empty())
        {
            cout << "Error: Infix expression " << expression << " has mismatched parens!" << endl;
            continue;
        }
        
        //clear the stack paren_matcher after use
        paren_matcher.clear();
        
        
        //check if the expression is a valid infix
        // we use the stack of strings because we need to accomodate
        // variables whose size is more than 1
        for(int i = 0; i < expression.size(); i++)
        {
            //cout<<expression[i]<<endl;
            if(expression[i] == '(')
            {
                // if the expression[i] == '('
                // then we check if the previous element is either an operator
                // or the previous element is '(' or we do not have any elements yet
                
                if(infix_checker.empty())
                {
                    infix_checker.push("(");
                }
                
                else
                {
                    if(is_operator(infix_checker.top()) || infix_checker.top() == "(")
                    {
                        infix_checker.push("(");
                    }
                    else
                    {
                        cout<<"Error: Missing operators in postfix string."<<endl;
                        invalid_infix = true;
                        break;
                    }
                }
                
            }
            
            else if(expression[i] == ')')
            {
                //if the previous item is an operand we push into stack
                if(!is_operator(infix_checker.top()) && !is_paren(infix_checker.top()) )
                {
                    infix_checker.push(")");
                }
                
                else
                {
                    //if the previous item is a ')' we push it into a stack
                    if(infix_checker.top() == ")")
                    {
                        infix_checker.push(")");
                    }
                    
                    else
                    {
                        cout << "Error: Missing operand in postfix string. Unable to evaluate the postfix string " << endl;
                        invalid_infix = true;
                        break;
                    }
                }
            }
            else if(expression[i] == ' ')
                ; // do nothing if the current element is a string
            
            else if( is_operator(expression[i]) )
            {
                //an operator should always have an operand or a ) to its left
                if(infix_checker.empty())
                {
                    cout << "Error: Missing operand in postfix string. Unable to evaluate the postfix string " << endl;
                    invalid_infix = true;
                    break;
                }
                else
                {
                    if(is_operator(infix_checker.top()) || infix_checker.top() == "(")
                    {
                        cout << "Error: Missing operand in postfix string. Unable to evaluate the postfix string " << endl;
                        invalid_infix = true;
                        break;
                    }
                    
                    else {
                        string op = "";
                        op += expression[i];
                        infix_checker.push(op);
                    }
                }
            }
            
            //if it is an operand
            else
            {
                string temp = "";
                int j = i;
                bool isnum = false;
                
                while(j < expression.size() && expression[j] != ' ')
                {
                    //if the operand begins with a zero or a . we have floats
                    // if the operand begins with an alphabet  then we have variables
                    if(j == i)
                    {
                        if((48 <= int(expression[j]) && int(expression[j]) <= 57) || expression[j] == '.')
                        {
                            isnum = true;
                        }
                        else if( hasVariables == false)
                        {
                            hasVariables = true;
                        }
                    }
                    if(isnum && expression[j] == '.' && hasFloats == false)
                    {
                        hasFloats = true;
                    }
                    
                    temp += expression[j];
                    j++;
                }
                
//                cout<< "temp: " << temp << " j" <<" "<< j<< endl;
//                cout<< "top" << infix_checker.top() << endl;
                i = j - 1;
                //if we only have an operand in the beginning we simply push it into the stack
                if(infix_checker.empty())
                {
                    infix_checker.push(temp);
                }
                // an operand should be preceded by a '(' or an operator
                else
                {
                    if(infix_checker.top() == "(" || is_operator(infix_checker.top()) )
                    {
                        infix_checker.push(temp);
                    }
                    else
                    {
                        cout<<"Error: Missing operators in postfix string."<<endl;
                        invalid_infix = true;
                        break;
                    }
                }
            }
        }
        
        //clear stack after use
        infix_checker.clear();
        
        if(invalid_infix)
            continue;
        
        // change the infix to postfix
        // and evaluate the expression if it doe not have any variables
        for(int i = 0; i < expression.size(); i++)
        {
            //if(!operators.empty())
                //cout<<operators.top()<<endl;
            if(is_operator(expression[i]))
            {
                if(operators.empty())
                {
                    operators.push(expression[i]);
                }
                //we compare the precedence of expression[i] with the preceding value in the stack operators
                //if the precedence level of the item in the stack is higher we pop it and push expression[i]
                //else we push expression[i]
                
                else if(has_higher_precedence(operators.top(), expression[i]))
                {
                    result += operators.top();
                    result += " ";
                    operators.pop();
                    operators.push(expression[i]);
                }
                
                else
                {
                    operators.push(expression[i]);
                }
                
            }
            
            else if( expression[i] == '(')
            {
                //we just push into the stack
                operators.push('(');
            }
            
            else if( expression[i] == ')')
            {
                //we just pop the items till we hit '('
                while(operators.top() != '(')
                {
                    result += operators.top();
                    result += " ";
                    
                    operators.pop();
                }
                
                operators.pop();
            }
            
            else if (expression[i] == ' ')
                ; //do nothing
            
            //if we encounter operators we just add them to the postfix
            else
            {
                string temp = "";
                while (i < expression.size() && expression[i] != ' ') {
                    temp+= expression[i];
                    i ++;
                    
                }
                result += temp;
                result += " ";
            }
            
        }
        while(!operators.empty())
        {
            result += operators.top();
            if(operators.size() > 1)
                result += " ";
            operators.pop();
        }
        cout<<"Postfix expression: " << result<< endl;
        if(hasVariables)
        {
            cout<<"Postfix evaluation: " << result << " = " << result<<endl;
        }
        
        else
        {
            float value = post_fix_evaluator(result);
            cout<<"Postfix evaluation: " << result << " = " << value <<endl;
        }
    }while(expression != "exit");
    
    
    return 0;
}

bool is_operator(string c)
{
    if( c == "+" || c == "-" || c == "*" || c == "/")
       return true;
    return false;
}

bool is_operator(char c)
{
    if( c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}


bool is_paren(char c)
{
    if( c == '(' || c == ')')
        return true;
    return false;
}

bool is_paren(string c)
{
    if( c == "(" || c == ")")
        return true;
    return false;
}

bool has_higher_precedence(char op1, char op2)
{
    if(op1 == '/')
        return true;
    else if( op1 == '*')
    {
        if(op2 == '/')
            return false;
        return true;
    }
    
    else if(op1 == '+' || op1 == '-')
    {
        if(op2 == '*' || op2 == '/')
            return false;
        return true;
    }
    return false;
}

float post_fix_evaluator(const string& s)
{
    cop4530::Stack<float> numbers;// stores all the number (floats and ints) in a stack
    for(int i = 0; i < s.size(); i++)
    {
        //cout<<"numbers: "<< numbers;
        
        if(s[i]== ' ')
            continue;
        
        else if(is_operator(s[i]))
        {
            float y = numbers.top();
            numbers.pop();
            float x = numbers.top();
            numbers.pop();
            
            if(s[i] == '+')
                numbers.push(x + y);
            else if(s[i] == '-')
                numbers.push(x - y);
            else if(s[i] == '*')
                numbers.push(x * y);
            else if(s[i] == '/')
                numbers.push(x/y);
            
        }
        else
        {
            string val = "";
            while(s[i] != ' ')
            {
                val += s[i];
                i++;
            }
            
            float n = string_to_num(val);
            numbers.push(n);
        }
    }
    
    return numbers.top();
    
}

float string_to_num(const string & s)
{
    float result = 0;
    int is_float = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '.')
        {
            is_float = i;
        }
        else
        {
            if(is_float)
            {
                result += (int(s[i]) - 48)* pow(10, is_float - i);
            }
            else
            {
                if(result == 0)
                    result += int(s[i]) - 48;
                else {
                    result *= 10;
                    result += int(s[i]) - 48;
                }
            }
        }
    }
    return result;
}
