#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> dist;
    int num;
    cin>>num;
    for(int i = 0; i < 2*num - 1; i++)
    {
        if(i%2 == 0)
        {
            int temp;
            cin>>temp;
            dist.push_back(temp);
        }
    }
    
    for(int i = 0; i < dist.size(); i++)
    {
        cout<<dist[i]<<" ";
    }
    
    return 0;
}

