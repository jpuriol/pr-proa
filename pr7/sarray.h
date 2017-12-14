/*
 * Clase Simple Array (SArray)
 * Obtenida de transparencias de clase
 * 
 */

#ifndef _SARRAY_H
#define _SARRAY_H

template<typename T> 
class SArray {   // Simple Array
  T*     storage;       // storage of the elements 
  size_t storage_size;  // number of elements 

public: 
  // create array with initial size 
  explicit SArray (size_t s)
  : storage(new T[s]), storage_size(s) { 
    init(); 
  } 

  // copy constructor 
  SArray (SArray<T> const& orig) 
  : storage(new T[orig.size()]), storage_size(orig.size()) { 
    copy(orig); 
  } 
  ~SArray() { 
        delete[] storage; 
    } 

    SArray<T>& operator= (SArray<T> const& orig) { 
        if (&orig != this) { 
            copy(orig); 
        } 
        return *this; 
    } 

    size_t size() const { 
        return storage_size; 
    } 

    T operator[] (size_t idx) const { 
        return storage[idx]; 
    } 
    T& operator[] (size_t idx) { 
        return storage[idx]; 
    }
    
    /**
     * Fuction for returning type
     * @return type as string
     */
    std::string type() const
    {
        return "SArray";
    }
    
    protected: 
    // init values with default constructor 
    void init() { 
        for (size_t idx = 0; idx<size(); ++idx) { 
            storage[idx] = T(); 
        } 
    } 

    // copy values of another array 
    void copy (SArray<T> const& orig) { 
        assert(size() == orig.size()); 
        for (size_t idx = 0; idx<size(); ++idx) { 
            storage[idx] = orig.storage[idx]; 
        } 
    } 

};

#endif
