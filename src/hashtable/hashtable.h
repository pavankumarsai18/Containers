//Venkata Vadrevu
//COP4530
//vv18d
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <fstream>

namespace cop4530
{
    static const unsigned int max_prime = 1301081;
    static const unsigned int default_capacity = 11;

    template <typename K, typename V>
    class HashTable
    {
        public:
            HashTable(size_t size = 101);
            ~HashTable();
            bool contains(const K & k) const;
            bool match(const std::pair<K, V> &kv) const;
            bool insert(const std::pair<K, V> & kv);
            bool insert (std::pair<K,  V> && kv);
            bool remove(const K & k);
            void clear();
            bool load(const char *filename);
            void dump() const;
            bool write_to_file(const char *filename) const;
            size_t size() const;
        
        private:
            std::vector<std::list<std::pair<K,V>>> hash_map;
            int current_size;
        
            void makeEmpty();
            void rehash();
            size_t myhash(const K &k) const;
            unsigned long prime_below (unsigned long) const;
            void setPrimes(std::vector<unsigned long>&) const;

    };
    #include "hashtable.hpp"
}
#endif
