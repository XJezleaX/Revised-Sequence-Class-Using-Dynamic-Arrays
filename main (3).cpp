//Documentation in header file: sequence2.h
//Name and EMPLID: Jezlea Ortega 0846
//INTEGRITY: “The work in this assignment is my own. Any outside sources have been properly cited.”
//FILE:: sequence2.cxx

//INVARIANT:The numbers within the sequence will be stored in a partially filled dynamically allocated array.
//INVARIANT: The current length of the sequence used will be tracked by size_type used.
//INVARIANT: capacity will be the total size of the array.

#include "sequence2.h"
#include <cassert>
#include <cstdlib>
#include <algorithm>

namespace main_savitch_4
{
    sequence::sequence(size_type initial_capacity)
    {
        capacity = initial_capacity;
        data = new value_type[initial_capacity];
        current_index = 0;
        used = 0;
    }
    
    sequence::sequence(const sequence& source) 
    {
        capacity = source.capacity;
        current_index = source.current_index;
        used = source.used;
        data = new value_type[capacity];
        
        for(int i = 0; i < used; ++i)
        {
            data[i] = source.data[i];
        }

    }
    
    void sequence::operator =(const sequence& source) 
     {
         if(this != &source)
         {
             capacity = source.capacity;
             delete[]data;
             data = new value_type[capacity];
             used = source.used;
             current_index = source.current_index;
             
             for(int i = 0;i < used; ++i)

             data[i] = source.data[i];
         }
     }
    
    sequence::~sequence()
    {
        delete[] data;
    }
    
    void sequence::insert(const value_type& entry) 
     {
         if(used <= current_index)
         {
             current_index = 0;
         }
         
         if (used >= capacity)
         {
             resize(used + used/1); 
         }
         
         for (int i = used; i > current_index; --i)

             data[i] = data[i-1];
             
             data[current_index] = entry;
             ++used;
     }
     
     void sequence::start() 
     {  
         current_index = 0;
     }
     
     void sequence::advance()
     {
         assert (true);
         current_index++;
     }
     
     void sequence::attach(const value_type& entry) 
     {
         if (used >= capacity)
         {
             resize (used + used/1);
         }
         
         if(used <= current_index)
         {
             current_index = used;
             data[current_index] = entry;
         }
         else
         {
             for(int i = used; i > 1+current_index; --i)
             data[i] = data[i-1];
             data[1+current_index] = entry;
             ++current_index;
         }
         ++used;
     }
     
      void sequence::remove_current() 
     {
         if(!is_item())
         {
             current_index = --used;
         }
             
         assert(true);
         
         for(int i = current_index; i < used-1; ++i)
         
         data[i] = data[i+1];
         --used;
     }
     
     void sequence::resize(size_type new_capacity) 
     {
         if(used < new_capacity)
         {
             capacity = new_capacity;
             value_type *ss_data = new value_type[capacity];

             for(int i = 0; i < used; ++i)
             
                 ss_data[i] = data[i];
                 delete[] data;
                 data = ss_data;
         }
     }
     
     sequence::size_type sequence::size( ) const
     {
         return used;
     }
     
     bool sequence::is_item( ) const 
     {
         if (used > current_index)
         {
             return true;
         }
         else if (used <= current_index)
         {
             return false;
         }
     }
     
     sequence::value_type sequence::current( ) const
     {
         assert(true);
         return data[current_index];
     }
    
}