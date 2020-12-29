//Venkata Vadrevu
//COP4530
//vv18d

#include <iostream>
#include "passserver.h"
using namespace std;

void Menu()
{
    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice : ";
}
int main()
{
    char input;
    unsigned int preferred_size;
    
    cout<<"Enter preferred hash table capacity: ";
    cin>>preferred_size;
    
    PassServer server(preferred_size);
    
    cout<<" "<<endl<<" "<<endl;
    

    do
    {
        Menu();
        cin>>input;
        
        switch(input)
        {
            case 'l':
                {
                    cout<<"Enter password file name to load from: ";
                    string filename;
                    cin>>filename;
                    bool success = server.load(filename.c_str());
                    if(!success)
                    {
                        cerr<<"Error: Cannot open file \n";
                    }
                    
                }
                break;
            case 'a':
                {
                    string username = "",password = "";
                    cout<<"Enter username: ";
                    cin>>username;
                    cout<<"Enter password: ";
                    cin>>password;
                    bool success = server.addUser(pair<string,string>(username,password));
                    cout<<""<<endl;
                    if(success)
                        cout<<"User "<<username<<" added.\n";
                    else
                        cout<<"*****Error: User already exists. Could not add user.\n";
                    
                }
                break;
            case 'r':
                {
                    string username = "";
                    cout<<"Enter username: ";
                    cin>>username;
                    bool success = server.removeUser(username);
                    if(success)
                        cout<<"User "<<username<<" deleted.\n";
                    else
                        cout<<"*****Error: User not found.  Could not delete user\n";
                }
                break;
            case 'c':
                {
                    string username, password, new_password;
                    username = password = new_password = "";
                    
                    cout<<"Enter username    : ";
                    cin>>username;
                    cout<<"Enter password    : ";
                    cin>>password;
                    
                    cout<<" \n";
                    cout<<"Enter new password: ";
                    cin>>new_password;
                    
                    bool success = server.changePassword(pair<string,string>(username, password), new_password);
                    cout<<" \n";
                    if(success)
                        cout<<"Password changed for user "<<username<<endl;
                    else
                        cerr<<"*****Error: Could not change user password"<<endl;

                    
                }
                break;
            case 'f':
                {
                    string username = "";
                    cout<<"Enter username    : ";
                    cin>>username;
                    cout<<" \n";
                    bool success = server.find(username);
                    cout<<"User \'"<<username<<"\'";
                    if(!success)
                        cout<<" not ";
                    cout<<"found.\n";
                }
                break;
            case 'd':
                {
                    server.dump();
                }
                break;
            case 's':
                {
                    cout<<"Size of hashtable: "<<server.size()<<endl;
                }
                break;
            case 'w':
                {
                    string filename;
                    cout<<"Enter password file name to write to: ";
                    cin>>filename;
                    bool success = server.write_to_file(filename.c_str());
                    if(success)
                        ;
                    else
                        cerr<<"Error: Cannot open file \n";
                }
                break;
            case 'x':
                {
                    exit(0);
                }
            default:
                {
                    cout<<"*****Error: Invalid entry.  Try again.\n";
                }
                break;
        }
        cout<<" \n \n";
    }
    while(input != 'x');
    
    return 0;
}
