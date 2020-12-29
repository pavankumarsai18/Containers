//Venkata Vadrevu
//COP4530
//vv18d
#ifndef passserver_cpp
#define passserver_cpp

#include "passserver.h"

PassServer::PassServer(size_t size):cop4530::HashTable<string, string>(size)
{}


PassServer::~PassServer()
{
    this->cop4530::HashTable<string,string>::clear();

}
bool PassServer::load(const char *filename)
{
    return this->cop4530::HashTable<string, string>::load(filename);
    
}
bool PassServer::addUser(std::pair<string,  string> & kv)
{
        return this->cop4530::HashTable<string,string>::insert(std::pair<std::string,std::string>(kv.first,encrypt(kv.second)));
    
}
bool PassServer::addUser(std::pair<string, string> && kv)
{
    return this->cop4530::HashTable<string,string>::insert(std::pair<std::string,std::string>(kv.first,encrypt(kv.second)));
}
bool PassServer::removeUser(const string & k)
{
    return this->cop4530::HashTable<string,string>::remove(k);
}
bool PassServer::changePassword(const pair<string, string> &p, const string & newpassword)
{
    if(this->cop4530::HashTable<string,string>::contains(p.first))
    {
        if(this->cop4530::HashTable<string,string>::match(pair<string, string>(p.first, encrypt(p.second))))
        {
            string crypt_pass = encrypt(newpassword);
            if(p.second != crypt_pass)
            {
                std::pair<string, string> new_pair;
                new_pair.first = p.first;
                new_pair.second = crypt_pass;
                this->cop4530::HashTable<string,string>::insert(new_pair);
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
    
}
bool PassServer::find(const string & user)
{
    return this->cop4530::HashTable<string,string>::contains(user);
}
void PassServer::dump()
{
    this->cop4530::HashTable<string,string>::dump();
}
size_t PassServer::size()
{
    return this->cop4530::HashTable<string,string>::size();
}
bool PassServer::write_to_file(const char *filename)
{
    return this->cop4530::HashTable<string,string>::write_to_file(filename);
}
string PassServer::encrypt(const string & str)
{
    char Salt[] = "$1$########";
    string result =  crypt(str.c_str(), Salt);
    
    int count = 0;
    int i;
    for(i = 0; i < result.size(); i++)
    {
        if(result[i] == '$')
            count ++;
        if(count == 3)
            break;
    }
    
    auto password = result.substr(i+1, 22);
    return password;
}

#endif
