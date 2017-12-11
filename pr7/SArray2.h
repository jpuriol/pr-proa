/*
 * Clase Simple Array (SArray)
 * Obtenida de transparencias de clase
 * 
 */

#ifndef _SARRAY2_H
#define _SARRAY2_H

template<typename T> 
class SArray2 {   // Simple Array
  T*     storage;       // storage of the elements 
  size_t storage_size;  // number of elements 

public: 
  // create array with initial size 
  explicit SArray2 (size_t s)
  : storage(new T[s]), storage_size(s) { 
    init(); 
  } 

  // copy constructor 
  SArray2 (SArray2<T> const& orig) 
  : storage(new T[orig.size()]), storage_size(orig.size()) { 
    copy(orig); 
  } 
  ~SArray2() { 
        delete[] storage; 
    } 

    SArray2<T>& operator= (SArray2<T> const& orig) { 
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
     * Sobrecarga de operador +
     * Array+Array
     */
    SArray2<T> operator+ (SArray2<T> const& b) 
    {
        if(storage_size==b.size())
        {
            SArray2 result (storage_size);
            for(unsigned i=0;i<storage_size;i++)
            {
                result[i]=storage[i]+b[i];
            }
            return result;
        }
        else
        {
            //throw runtime_error("Sizes of Arrays Must Agree");
            return SArray2(storage_size);   //COMPROBAR SI ES NECESARIO CUANDO FUNCIONE EL RUNTIME ERROR
        }
    }
    
    /**
     * Sobrecarga de operador *
     * Array*Array
     */
    SArray2<T> operator* (SArray2<T> const& b) 
    {
        if(storage_size==b.size())
        {
            SArray2 result (storage_size);
            for(unsigned i=0;i<storage_size;i++)
            {
                result[i]=storage[i]*b[i];
            }
            return result;
        }
        else
        {
            //throw runtime_error("Sizes of Arrays Must Agree");
            return SArray2(storage_size); //COMPROBAR SI ES NECESARIO CUANDO FUNCIONE EL RUNTIME ERROR
        }
    }
    
    /**
     * Sobrecarga de operador +
     * Array+Scalar
     */
    SArray2<T> operator+ (T const& a) 
    {
        SArray2 result (storage_size);
        for(unsigned i=0;i<storage_size;i++)
        {
            result[i]=a+storage[i];
        }
        return result;
    }
    
    /**
     * Sobrecarga de operador *
     * Array*Scalar
     */
    SArray2<T> operator* (T const& a) 
    {
        SArray2 result (storage_size);
        for(unsigned i=0;i<storage_size;i++)
        {
            result[i]=a*storage[i];
        }
        return result;
    }
    
    /**
     * Sobrecarga de operador ^
     * Array^Scalar
     */
    SArray2<T> operator^ (T const& a) 
    {
        SArray2 result (storage_size);
        for(unsigned i=0;i<storage_size;i++)
        {
            result[i]=pow(storage[i],a);
        }
        return result;
    }
    
    protected: 
    // init values with default constructor 
    void init() { 
        for (size_t idx = 0; idx<size(); ++idx) { 
            storage[idx] = T(); 
        } 
    } 

    // copy values of another array 
    void copy (SArray2<T> const& orig) { 
        assert(size() == orig.size()); 
        for (size_t idx = 0; idx<size(); ++idx) { 
            storage[idx] = orig.storage[idx]; 
        } 
    } 
    
    
};

#endif
