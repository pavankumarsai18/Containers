////
////    // insert code here...
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////
////int main()
////{
////    vector<int> dist;
////    int num;
////    cin>>num;
////    for(int i = 0; i < 2*num - 1; i++)
////    {
////        if(i%2 == 0)
////        {
////            int temp;
////            cin>>temp;
////            dist.push_back(temp);
////        }
////        else
////        {
////            cin.get();
////        }
////    }
////
////    //count num -neg
////    int neg = 0;
////    int pos = 0;
////    for(int i = 0; i < dist.size(); i++)
////    {
////        if(dist[i] < 0)
////            neg++;
////        if(dist[i] > 0)
////            pos ++;
////
////    }
////
////    if(pos == 0)
////    {
////         cout<<0;
////        return 0;
////    }
////
////    sort(dist.begin(),dist.end());
////
//////    for(int i = 0; i < dist.size(); i++)
//////    {
//////        cout<<dist[i]<<" ";
//////    }
//////    cout<<endl;
////
////    int res = 1;
////    long double result = 1;
////    if(neg%2 == 1)
////        neg --;
////
////    for(int i = 0; i < neg;i++)
////    {
////        if(dist[i] < 0)
////        {
////            res *= dist[i];
////            result *= dist[i];
////        }
////        else
////            break;
////    }
////
////    for(int i = 0; i < dist.size(); i++)
////    {
////        if(dist[i] <= 0)
////            ;
////        else
////        {
////            res*= dist[i];
////            result *= dist[i];
////        }
////    }
////
////    if(result > 0 )
////    {
////        if(result < 1000000000)
////            cout<<res;
////        else
////            cout<<result;
////    }
////    else
////        cout<<0;
////    return 0;
////}
////
////
//
//#include <vector>
//#include <string>
//#include <map>
//#include <iostream>
//#include <sstream>
//using namespace std;
//
//struct person
//{
//    string name;
//    vector<string> candy;
//};
//
//int main()
//{
//    
//    int num;
//    cin>>num;
//    vector<person> P;
//    int count = 0;
//    while(count < num)
//    {
//        string temp;
//        cin >>temp;
//        person p;
//        p.name = temp;
//        
//        
//        string can;
//        getline(cin, can);
//        for(int i = 0; i < can.size(); i++)
//        {
//            string temp = "";
//            while(i < can.size() && can[i] != ' ')
//            {
//                temp += can[i];
//            }
//            p.candy.push_back(temp);
//        }
//        P.push_back(p);
//        count ++;
//    }
//    
//    char n;
//    cin>>n;
//    
//    map <string, int> result;
//    for(int i = 0; i < num; i++)
//    {
//        
//        for(int j = 0; j < P[i].candy.size();j++)
//        {
//            for(int k = 0; k < (P[i].candy[j]).size(); k++)
//            {
//                if( P[i].candy[j][k]) == n)
//                {
//                    
//                    map[P[i].name] =
//                }
//            }
//        }
//            P[i].name
//    }
//    
//    
//}
