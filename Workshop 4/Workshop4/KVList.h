#pragma once
//Justin Cook
#include <cstddef> //Included to make it compile with -std=c++0x on matrix
#include <cstdint>

template<typename K, typename V, int N>
   class KVList {
      K keys[N];
      V values[N];
      size_t stored;
      

   public:
      KVList() {
         stored = 0;
         for (int i = 0; i < N; i++) {
            keys[i] = { 0 };
            values[i] = { 0 };
         }
      }
      size_t size() const{ 
         return stored; 
      }
      const K& key(int i) const{
         return keys[i];
      }
      const V& value(int i)const{
         return values[i];
      }
      KVList& add(const K& k, const V& v) {
         if (size() < N) {
            keys[size()] = k;
            values[size()] = v;
            stored++;
         }

         return *this;
      }
      int find(const K& k) const {
         int i = 0;
         for (int j = 0; j < N; j++) {
            if (keys[j] == k) {
               i = j;
               j = N;
            }
         }
         return i;
      }
      KVList& replace(int i, const K& k, const V& v) {
         keys[i] = k;
         values[i] = v;
         return *this;
      }
   };
