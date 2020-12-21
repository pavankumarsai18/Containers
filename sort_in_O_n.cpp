#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
//apparently this is called as counting sort
int main()
{
    srand(time(0));
    vector<int> arr;
    for(int i = 0; i < 100;  i++)
    {
         arr.push_back(rand()%100);
    }

	for(int i = 0; i < arr.size(); i++)
	{
	    cout<<arr[i]<<" ";
	}

	vector<int> srt;
	int min = arr[0];
	int max = arr[0];


    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] < min)
             min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

	for(int i = min; i <= max; i++)
		srt.push_back(0);

	for(int i = 0; i < arr.size(); i++)
		srt[arr[i] - min] += 1;

	vector<int> result;

	for(int i = 0; i < srt.size(); i++){
		if(srt[i] != 0)
		{
			for(int j = 0; j < srt[i]; j++)
				result.push_back(i + min);
		}

	}
	cout<<"\n--------------------\n";
	for(int i = 0; i < result.size(); i++)
		cout<<result[i]<<" ";

	cout<<"\n--------------------\n";
	sort(arr.begin(), arr.end());
	for(int i = 0; i < arr.size(); i++)
		cout<<arr[i]<<" ";

	return 0;
}
