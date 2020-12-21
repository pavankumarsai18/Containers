//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int S_num(string S);
//
//int main()
//{
//    vector<int> S;
//    string num;
//    string input;
//    getline(cin, input);
//    
//    for(int i = 0; i < input.size(); i++)
//    {
//    
//        num = "";
//        
//        while(i < input.size() && input[i] != ' ')
//        {
//            num += input[i];
//            i++;
//        }
//        
//        if(num == "")
//            break;
//        
//        int res = S_num(num);
//        
//        if(res < 0)
//        {
//            res *= -1;
//            if(res < S.size() && res >= 0)
//                S[res] = 0;
//            
//        }
//        else if(res == 0)
//        {
//            S.pop_back();
//        }
//        
//        else if(res > 0)
//        {
//            res = res ^ S.size();
//            S.push_back(res);
//        }
//        
//    }
//    
//    
//    for(int i = S.size() - 1; i >= 0; i--)
//    {
//        if(S[i] != 0)
//            cout<<S[i]<<" ";
//    }
//    return 0;
//}
//
//int S_num(string S)
//{
//    int result  = 0;
//    if(S[0] == '-')
//    {
//        
//        for(int i = 1; i < S.size(); i++)
//        {
//            result += static_cast<int>(S[i]) - 48;
//            if(i != S.size() - 1)
//                result *= 10;
//        }
//        
//        result *= -1;
//    }
//    
//    else
//    {
//        for(int i = 0; i < S.size(); i++)
//        {
//            result += static_cast<int>(S[i]) - 48;
//             if(i != S.size() - 1)
//                 result *= 10;
//        }
//    }
//    return result;
//}
