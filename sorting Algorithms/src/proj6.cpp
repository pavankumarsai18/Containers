//Venkata Vadrevu
//vv18d
//COP4530

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <iomanip>

//Function that compares two characters
//return true if a has lower precedence than b
bool compare(const std::pair <char, int>& a, const std::pair<char, int>& b);

//Function that compares two strings
// returns true if a has lower precedence than b
bool compare_str(const std::pair<std::string,std::pair<int, int>>& a, const std::pair<std::string,std::pair<int, int>>& b);

int main()
{
    // The number if items we need to output
    const int max = 10;
    
    // The spacing between two columns in the ouput
    const int spacing = 12;

    //A string that stores all the input
    std::string input = "";
    
    // A string that stores one line
    std::string line;
    
    //reading each line through getline function and appending it to
    //a string called input
    while(std::getline(std::cin, line))
    {
        //appending the line to the strign called input
        input += line;
        
        //we add '\n' because getline throws the delimiter
        input += '\n';
        
        //then we clear the line
        line.clear();
    }
    
    
    //Unordered maps which sotre the data and the number of times they apperaed in the string
    std::unordered_map<char, int> char_count;
    std::unordered_map<std::string, int> string_count;
    std::unordered_map<std::string, int> num_count;
    std::unordered_map<std::string, int>string_index;
    
    //reading characters and storing them into a hash_map
    for(int i = 0; i < input.size(); i++)
    {
        auto itr = char_count.find(input[i]);
        if(itr == char_count.end())
            char_count[input[i]] = 1;
        else
            char_count[input[i]]++;
    }
    
    //reading words and storing them into a hash_map
    // along with their starting indices
    for(int i = 0; i < input.size(); i++)
    {
        std::string temp = "";
        while(i < input.size() && isalpha(input[i]) && input[i] != ' ' && input[i] != '\n')
        {
            temp += static_cast<char>(std::tolower(input[i]));
            i++;
        }
        
        //if the string is empty we do nothing
        // we need to cintinue the for loop
        if(temp == "")
            continue;
        
        //in the string_count
        auto itr = string_count.find(temp);
        if(itr == string_count.end())
            string_count[temp] = 1;
        else
            string_count[temp]++;
        
        //in the string_index
        auto itr_ = string_index.find(temp);
        if(itr_ == string_index.end())
            string_index[temp] = i - static_cast<int>(temp.size());
        
    }
    
    //reading numbers and storing them into a hash_map
    // along with their starting indices
    for(int i = 0; i < input.size(); i++)
    {
        std::string temp = "";
        while(i < input.size() && isdigit(input[i]) && input[i] != ' ' && input[i] != '\n')
        {
            temp += static_cast<char>(std::tolower(input[i]));
            i++;
        }
        
        //if the string is empty we do nothing
        // we need to continue the for loop
        if(temp == "")
            continue;
        
        auto itr = num_count.find(temp);
        
        if(itr == num_count.end())
            num_count[temp] = 1;
        else
            num_count[temp]++;
        
        
        auto itr_ = string_index.find(temp);
        if(itr_ == string_index.end())
            string_index[temp] = i - static_cast<int>(temp.size());
    }
    
    //clear string
    input.clear();
    
    //Vectors to store the words and numbers
    std::vector<std::pair<char, int>> letters;
    
    //Vector to store a word  and pair<int, int>
    // in the pair<int, int> the first value is set to the number of times it
    // occurs in the string
    // and the second value is set to the starting index that string appears in
    //file
    std::vector<std::pair<std::string, std::pair<int, int>>> words;
    
    //same format as mentioned in the previous vector words
    std::vector<std::pair<std::string, std::pair<int, int>>> numbers;
    
    
    
    //we iterate through the unordered list and insert pairs into a vector
    for(auto itr = char_count.begin(); itr != char_count.end(); itr++)
    {
        letters.push_back(std::pair<char, int>(itr->first, itr->second));
    }
    //clear unordered_map
    char_count.clear();
    
    //we iterate through the unordered list and insert pairs into a vector
    for(auto itr = string_count.begin(); itr != string_count.end(); itr++)
    {
        std::pair<int, int>p;
        p.first = itr->second;
        p.second = string_index[itr->first];
        
        words.push_back(std::pair<std::string, std::pair<int, int>>(itr->first, p));
    }
    //clear uonrdered_map
    string_count.clear();
    

    //we iterate through the unordered list and insert pairs into a vector
    for(auto itr = num_count.begin(); itr != num_count.end(); itr++)
    {
        std::pair<int, int>p;
        p.first = itr->second;
        p.second = string_index[itr->first];
        
        numbers.push_back(std::pair<std::string, std::pair<int, int>>(itr->first, p));
    }
    //clear unordered_map
    num_count.clear();
    
    
    //Builiding heaps
    //Making the vectors into heaps
    //O(n)
    
    //we use the compare and compare_str functions to haepify the vector
    // the vector is partially ordered in a way that satisfies the functions requrements
    std::make_heap(letters.begin(), letters.end(), compare);
    std::make_heap(words.begin(), words.end(), compare_str);
    std::make_heap(numbers.begin(), numbers.end(), compare_str);
    
    
    std::cout<<"Total "<<letters.size()<<" different characters, "
    <<(max < letters.size() ? max: letters.size())<<" most used characters:\n";
    
    //O(10*logn)
    //O(logn)
    
    for(int i = 0; i < max; i++)
    {
        if(!letters.empty())
        {
            std::cout<<"No. "<<i<<": ";
            
            //if the character is an endline or a tab
            // we output '\n' or '\t'
            if(letters[0].first == '\n' || letters[0].first == '\t')
            {
                if(letters[0].first == '\n')
                    std::cout<<std::setw(spacing + 2)<<std::left<<"\\n"<<" "<<letters[0].second<<std::endl;
                else
                    std::cout<<std::setw(spacing + 2)<<std::left<<"\\t"<<" "<<letters[0].second<<std::endl;
            }
            else
                std::cout<<std::setw(spacing + 2)<<std::left<<letters[0].first<<" "<<letters[0].second<<std::endl;
            
            //Then we pop the head
            //we use the compare function
            std::pop_heap(letters.begin(), letters.end(), compare);
            
            // We remove the back because the maximum element
            // is transfered to the last index in the array
            letters.pop_back();
        }
        else
            break;
    }
    
    std::cout<<"\n";
    std::cout<<"Total "<<words.size()<<" different words, "
    <<(max < words.size() ? max : words.size())<<" most used words:\n";
    
    
    //O(10*logn)
    //O(logn)
    for(int i = 0; i < max; i++)
    {
        
        if(!words.empty())
        {
            std::cout<<"No. "<<i<<": ";
            std::cout<<std::left<<std::setw(spacing + 2)
            <<words[0].first<<" "
            <<words[0].second.first<<std::endl;
            std::pop_heap(words.begin(), words.end(), compare_str);
            words.pop_back();
        }
        else
            break;
    }
    
    
    std::cout<<"\n";
    std::cout<<"Total "<<numbers.size()<<" different numbers, "
    <<(max < numbers.size()? max : numbers.size())<<" most used numbers:\n";
    
    //O(10*logn)
    //O(logn)
    for(int i = 0; i < max; i++)
    {
        if(!numbers.empty())
        {
            std::cout<<"No. "<<i<<": "<<
            std::left<<std::setw(spacing + 2)
            <<numbers[0].first<<" "<<
            numbers[0].second.first<<std::endl;
            std::pop_heap(numbers.begin(), numbers.end(), compare_str);
            numbers.pop_back();
        }
        else
            break;
    }
    
    
    return 0;
}



bool compare(const std::pair <char, int>& a, const std::pair<char, int>& b)
{
    //if a has lower count than b we return true
    if(a.second < b.second)
    {
        return true;
    }
    // if a has equal count as b
    // we return the character which has a higher ascii value
    else if(a.second == b.second)
    {
        return (a.first > b.first);
    }
    //if a has igher count than b we return false
    return false;
}

bool compare_str(const std::pair<std::string,std::pair<int, int>>& a, const std::pair<std::string,std::pair<int, int>>& b)
{
    //if a has lower count than b we return true
    if(a.second.first < b.second.first)
        return true;
    // if a has the same count as b then
    else if(a.second.first == b.second.first)
    {
        // we return the string which has a higher starting index
        // ie we return a string which occured later in the input
        return a.second.second > b.second.second;
    }
    // if a has hogher count than b we return false
    return false;
}
