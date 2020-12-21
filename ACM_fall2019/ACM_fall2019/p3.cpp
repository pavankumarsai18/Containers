//#include <iostream>
//#include <stack>
//#include <vector>
//#include <string>
//using namespace std;
//
//void infix_postfix(string S);
//bool higher_prec(string a, string b);
//bool is_operator(string a);
//bool is_paren(string a);
//
//int main()
//{
//    stack<char> p_c;
//    vector<string> input;
//    string result;
//
//    while(1)
//    {
//        string temp = "";
//        getline(cin, temp);
//        if(temp == "")
//            break;
//        input.push_back(temp);
//    }
//
//    for(int i = 0; i < input.size() ;i++)
//    {
//        result += input[i];
//    }
//
//
//    //paren check
//    for(int i = 0; i < result.size(); i++)
//    {
//        if(result[i] == '(' || result[i] == '{' || result[i] == '[')
//            p_c.push(result[i]);
//
//        else if(result[i] == ')' || result[i] == '}' || result[i] == ']')
//        {
//            if(p_c.empty())
//            {
//                cout<<"False ";
//                break;
//            }
//            char temp = p_c.top();
//
//            if( (temp == '(' && result[i] == ')') || (temp == '{' && result[i] == '}') || (temp == '[' && result[i] == ']'))
//            {
//                p_c.pop();
//
//            }
//        }
//        else
//            ;
//
//    }
//
//    if(p_c.empty())
//        cout<<"True ";
//    else
//        cout<<"False ";
//
//
//    //i_p
//    string temp = "";
//    for(int i = 0; i < result.size(); i++)
//    {
//
//        if(result[i] == '=')
//        {
//
//            i += 2;//go to nearest var
//            while(i < result.size() && result[i] != ';')
//            {
//                temp += result[i];
//                i++;
//            }
//        }
//        if(temp != "")
//        {
//            infix_postfix(temp);
//        }
//        temp.clear();
//    }
//
//    return 0;
//}
//
//void infix_postfix(string expression)
//{
//    stack<string> infix;
//    for(int i = 0; i < expression.size(); i++)
//    {
//        string token = "";
//        while(i < expression.size() && expression[i] != ' ')
//        {
//            token += expression[i];
//            i++;
//        }
//
//        if(is_paren(token))
//        {
//            if(token == "(" || token == "{" || token == "[" )
//                infix.push(token);
//            else
//            {
//                string temp = token;
//                while(1)
//                {
//                    if((infix.top() == "(" && temp == ")") || (infix.top() == "{" && temp == "}") || (infix.top() == "{" && temp == "}") )
//                        break;
//                    else
//                    {
//                    cout<<infix.top()<<" ";
//                    infix.pop();
//                    }
//                }
//                infix.pop();
//            }
//
//        }
//        else if(is_operator(token))
//        {
//            if(infix.empty())
//            {
//                infix.push(token);
//            }
//            else
//            {
//                if(is_operator(infix.top()))
//                {
//                    if(higher_prec(infix.top(), token))
//                    {
//                        while(!infix.empty() && (higher_prec(infix.top(), token) || infix.top() == token))
//                        {
//                            cout<<infix.top()<<" ";
//                            infix.pop();
//                        }
//                        infix.push(token);
//
//                    }
//                    else if(higher_prec(token, infix.top()))
//                    {
//                        infix.push(token);
//
//                    }
//                    else
//                    {
//                        cout<<infix.top()<<" ";
//                        infix.pop();
//                        infix.push(token);
//                    }
//
//                }
//                else
//                {
//                    infix.push(token);
//                }
//            }
//
//        }
//        else
//        {
//            cout<<token<<" ";
//        }
//    }
//
//    while(!infix.empty())
//    {
//        cout<<infix.top()<<" ";
//        infix.pop();
//    }
//
//}
//
//bool higher_prec(string a, string b)
//{
//    if( a == "+" || a == "-")
//        return false;
//    else if ( (a == "*"  || a == "/") && (b == "+" || b ==  "-") )
//        return true;
//    else if (a == b)
//        return false;
//    return false;
//}
//
//bool is_operator(string a)
//{
//    if(a == "+" || a == "*" || a == "*" || a == "/")
//        return true;
//    return false;
//}
//
//bool is_paren(string a)
//{
//    if(a == "(" || a == "{" || a == "["||a == ")" || a == "}" || a == "]")
//        return true;
//    return false;
//
//}
