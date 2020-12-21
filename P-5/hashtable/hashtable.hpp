//Venkata Vadrevu
//COP4530
//vv18d
#ifndef hash_table_hpp
#define hash_table_hpp



template <typename K, typename V>
unsigned long HashTable<K,V>::prime_below (unsigned long n) const
{
    if (n > max_prime)
    {
        std::cerr << "** input too large for prime_below()\n";
        std::cout <<"set to default capacity\n";
       return 0;
    }
    if (n == max_prime)
    {
       return max_prime;
    }
    if (n <= 1)
    {
        std::cerr << "** input too small \n";
        std::cout <<"set to default capacity\n";
       return 0;
    }

    // now: 2 <= n < max_prime
    std::vector <unsigned long> v (n+1);
    setPrimes(v);
    while (n > 2)
    {
       if (v[n] == 1)
           return n;
       --n;
    }

    return 2;
}

template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes) const
{
    int i = 0;
    int j = 0;

    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();

    for (i = 2; i < n; ++i)
       vprimes[i] = 1;

    for( i = 2; i*i < n; ++i)
    {
       if (vprimes[i] == 1)
           for(j = i + i ; j < n; j += i)
               vprimes[j] = 0;
    }
}


template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size)
{
    int Size = prime_below(size);
    std::cout<<Size<<std::endl;
    for(int i = 0; i < Size; i++)
    {
        std::list<std::pair<K,V>> a; //empty fist of pairs
        hash_map.push_back(a); // push_back an empty list into hash_table
                                //for size times
    }
    current_size = 0;
}


template <typename K, typename V>
HashTable<K, V>::~HashTable()
{
    clear();
}

template <typename K, typename V>
bool HashTable<K, V>::contains(const K & k) const
{

    if(current_size == 0 || hash_map[myhash(k)].empty())
        return false;
    else
    {
        int index = myhash(k);
        if(index >= hash_map.size())
            return false;
        for(auto itr = hash_map[index].begin(); itr != hash_map[index].end(); itr++)
        {
            if(itr->first == k)
                return true;
        }
    }
    return false;
}


template <typename K, typename V>
bool HashTable<K, V>::match(const std::pair<K, V> &kv) const
{
    if(current_size == 0)
        return false;
    auto index = myhash(kv.first);
    if(index >= hash_map.size())
        return false;
    for(auto itr = hash_map[index].begin(); itr != hash_map[index].end(); itr ++)
    {
        if(itr->second == kv.second && itr->first == kv.first)
            return true;
    }
    return false;

}


template <typename K, typename V>
bool HashTable<K, V>::insert(const std::pair<K, V> & kv)
{
    if(match(kv))
        return false;
    else
    {
        if(contains(kv.first))
        {
            for(auto itr = hash_map[myhash(kv.first)].begin(); itr != hash_map[myhash(kv.first)].end(); itr++)
            {
                if(itr->first == kv.first)
                {
                    itr->second = kv.second;
                }
            }
        }
        else
        {
            hash_map[myhash(kv.first)].push_back(kv);
            current_size++;
        }

 
        if(current_size >= hash_map.size())
            rehash();
        return true;
    }
}

template <typename K, typename V>
bool HashTable<K, V>::insert (std::pair<K, V> && kv)
{
    if(match(kv))
       return false;
    else
    {
       if(contains(kv.first))
       {
           for(auto itr = hash_map[myhash(kv.first)].begin(); itr != hash_map[myhash(kv.first)].end(); itr++)
           {
               if(itr->first == kv.first)
               {
                   std::pair<K,V> temp;
                   temp = kv;
                   itr->second = temp.second;
               }
           }
       }
       else
       {
           std::pair<K,V> temp;
           temp = kv;
           hash_map[myhash(temp.first)].push_back(temp);
           current_size++;
       }

       
       if(current_size >= hash_map.size())
           rehash();
       return true;
    }
}

template <typename K, typename V>
bool HashTable<K, V>::remove(const K & k)
{
    if(!contains(k))
       return false;
    int index = myhash(k);
    for(auto itr = hash_map[index].begin(); itr != hash_map[index].end(); itr++)
    {
       if(itr->first == k)
       {
           hash_map[index].erase(itr);
           current_size --;
           return true;
       }
    }
    return false;
}


template <typename K, typename V>
void HashTable<K, V>::clear()
{
    makeEmpty();
}

template <typename K, typename V>
bool HashTable<K, V>::load(const char *filename)
{
    std::ifstream fin;
    fin.clear();
    fin.open(filename);
    if(!fin)
    {
       return false;
    }

    while(!fin.eof())
    {
       K temp_key;
       V temp_val;

       fin>>temp_key;
       fin>>temp_val;

        insert(std::pair<K,V>(temp_key, temp_val));
    }
    fin.close();
    return true;
}

template <typename K, typename V>
void HashTable<K, V>::dump() const
{
    for(int i = 0; i < hash_map.size(); i++)
    {
        std::cout<<"v["<<i<<"]: ";
       if(hash_map[i].size() > 0)
       {
           int count = 0;
           for(auto itr = hash_map[i].begin(); itr != hash_map[i].end(); itr++)
           {
               std::cout<<itr->first<<" "<<itr->second;
               count ++;
               if(count < hash_map[i].size())
               {
                   std::cout<<" : ";
               }
           }
       }
        std::cout<<std::endl;
    }
}

template <typename K, typename V>
bool HashTable<K, V>::write_to_file(const char *filename) const
{
    std::ofstream fout;
    fout.clear();
    fout.open(filename);
    if(!fout)
    {
       return false;
    }
    for(int i = 0; i < hash_map.size(); i++)
    {
       for(auto itr = hash_map[i].begin(); itr != hash_map[i].end(); itr++)
       {
           fout<<itr->first<<" "<<itr->second<<std::endl;
       }
    }
    
    fout.close();
    return true;

}


template <typename K, typename V>
void HashTable<K, V>::makeEmpty()
{
    for(int i = 0; i < hash_map.size(); i++)
    {
        if(hash_map[i].size())
            hash_map[i].clear();
    }
    hash_map.clear();
    current_size = 0;
}

template <typename K, typename V>
void HashTable<K, V>::rehash()
{
    int size = prime_below(2*current_size);

    std::vector<std::list<std::pair<K,V>>> temp;


    for(int i = 0; i < size; i++)
    {
        std::list<std::pair<K,V>> a;
        temp.push_back(a);
    }

    for(int i = 0; i < hash_map.size(); i++)
    {
        if(!hash_map[i].empty())
        {
           for(auto itr = hash_map[i].begin(); itr != hash_map[i].end(); itr++)
           {
               static std::hash<K> hf;
               int new_index = (hf(itr->first))%size;
               temp[new_index].push_back(std::pair<K,V>(itr->first, itr->second));
           }
        }
    }

    hash_map = temp;

}

template <typename K, typename V>
size_t HashTable<K, V>::myhash(const K & k) const
{
    static std::hash<K> hf;
    return hf(k)%hash_map.size();
}

template <typename K, typename V>
size_t HashTable<K, V>::size() const
{
    return current_size;
}

#endif
