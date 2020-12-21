//Problem 25.d
// An algorithm takes 0.05 milliseconda for input size 500. How long will it take for input size 2000
// if the running time analysis is each of the following
// Theta(logN)
// --> given answer 0.05 * log(2000/500) = 0.05*log(4) = 0.05*2 = 0.1ms
// --> my answer 0.05 * log(2000)/log(500) is approximately = 0.05*1.22 = 0.06 ms


// The hypothesis that I am testing is if the algorithm took 1 seconds to complete for input
// of size 500 then my prediction would be that the alorithm would take 1.22 seconds (log(2000)/log(500)) for an
// input of size 2000. But the given answer would predict that it would take 2 seconds (log(2000/500)) = log(4)


#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;

bool binary_search(vector<int>& arr, int val);

int main() {
    
    srand(time(0));
    
    float time_sum = 0;
    const int num_iterations = 10000;
    
    
    // ***----------------IMPORTANT -----------------***
    // To get a significant difference between my prediction and the proposed method we could change A = 100 and B = 1000
    // then my prediction would be log(1000)/log(100) = 1.5
    // but the propsed method would predict log(1000/100) = log(10) which is around 3.2
    // so there is a proposed method would predict double the time that my method would predict
    
    const int size_A = 100;
    const int size_B = 1000;
    
    
    
    // Note that one iteration would not be sufficient to prove or disprove any claim
    // if the claim is correct then it needs to be valid across most of the iterations and
    // performing multiple trials of this experiment would to reduce random error and noise
    // ie as "num_iterations" increases we get more and more accurate value of the
    // time
    
    // ALSO taking average does not mean that I am considering THETA as average time of time complexites
    for(int j = 0; j < num_iterations; j++)
    {
        //creating a sorted array of size 500 elements
        vector<int> arr1;
        for(int i = 0; i < size_A; i++)
        {
            arr1.push_back(rand()%size_A);
        }
        sort(arr1.begin(),arr1.end());
        //doing a binary search to find the last element 499

        //storing the start time in a varible
        auto start_1 = chrono::high_resolution_clock::now();
        binary_search(arr1, rand()%(size_A + 10));
        //storing the end time in a varible
        auto end_1 = chrono::high_resolution_clock::now();;
        
        auto time_500 = std::chrono::duration_cast<chrono::nanoseconds>(end_1 - start_1).count();
        //creating a sorted array of size 2000 elements
        vector<int> arr2;
        for(int i = 0; i < size_B; i++)
        {
            arr2.push_back(rand()%size_B);
        }
        
        //sort
        sort(arr2.begin(), arr2.end());
        
        //storing the start time in a varible
        auto start_2 = chrono::high_resolution_clock::now();
        //doing a binary search to find the last element 1999
        binary_search(arr2,rand()%(size_B+40));
        //storing the end time in a varible
        auto end_2 = chrono::high_resolution_clock::now();

        auto time_2000 = std::chrono::duration_cast<chrono::nanoseconds>(end_2 - start_2).count();

        
        //we can uncomment the cout satments to get a better understanding of the distribution of the values
        
        cout<<"The the two execution times are: time taken for "<<size_B<<" is ";
        cout<<time_2000<<"ns "<<"and"<< "time for "<<size_A <<" is "<<time_500<<" ns in the "<< j + 1<< "th iteration."<<endl;
        cout<<"Time ratio is " <<float(time_2000)/float(time_500)<< endl;
        
        time_sum += float(time_2000)/float(time_500);
        
    }
    
    // we need to finnd the ratio of the time taken for 2000 and the time taken for 500
    // my hypothesis is that the ratio is  around log(2000) / log (500)
    // log(2000) = log(500 * 4)
    // so log(2000)/log(500) = log(500*4)/ log (500)
    //                       = ( log(500) + log(4) )/log(500)
    //                       = ( log(500)/log(500) ) + ( log(4)/log(500) )
    //                       =           1           +  0.22307      ( I used a calulator to compute it)
    //                       =           1.22307
    // so the ratio should be around 1.22307
    // not log(4) = 2
    cout<<"------------------------------------------------------------------------------\n";
    cout<<"Avg_time_ratio is "<<time_sum/num_iterations<<endl;
    cout<<"log(" << size_B << ")" <<"/ log("<<size_A<< ")"<<" = "<<log2(size_B)/log2(size_A)<<endl;
    cout<<"But, "<< "log("<<size_B/size_A<<"), ie the log(size_B/size_A) is " << log2(size_B/size_A)<<endl;
    


    
    return 0;
}

//Binary search
bool binary_search(vector<int> & arr, int val)
{
    int lo, hi;
    lo = 0;
    hi = arr.size() - 1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        
        if(arr[mid] > val)
        {
            hi = mid - 1;
        }
        else if(arr[mid] < val)
        {
            lo = mid + 1;
        }
        else if(arr[mid] == val)
        {
            return true;
        }
        
    }
    return false;
}
