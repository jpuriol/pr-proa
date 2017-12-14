
#include<cassert>
#include "sarray.h"
#include "array_traits.h"
#include <math.h>

/*
 * Classes for representing operations
 */
template <typename T, typename OP1, typename OP2> 
class A_Add { 
    typename A_Traits<OP1>::ExprRef op1;    // first operand 
    typename A_Traits<OP2>::ExprRef op2;    // second operand 

  public: 
    // constructor initializes references to operands 
    A_Add (OP1 const& a, OP2 const& b) : op1(a), op2(b) {} 

    // compute sum when value requested 
    T operator[] (size_t idx) const { 
        return op1[idx] + op2[idx]; 
    } 

    // size is maximum size 
    size_t size() const { 
        assert (op1.size()==0 || op2.size()==0 
                || op1.size()==op2.size()); 
        return op1.size()!=0 ? op1.size() : op2.size(); 
    } 
    
     std::string type() const
    {
        return "A_Add<"+op1.type()+", "+op2.type()+">";
    }
    
}; 

template <typename T, typename OP1, typename OP2> 
class A_Mult { 
      typename A_Traits<OP1>::ExprRef op1;    // first operand 
      typename A_Traits<OP2>::ExprRef op2;    // second operand 

  public: 
    // constructor initializes references to operands 
    A_Mult(OP1 const& a, OP2 const& b) : op1(a), op2(b) {} 

    // compute sum when value requested 
    T operator[] (size_t idx) const { 
        return op1[idx] * op2[idx]; 
    } 

    // size is maximum size 
    size_t size() const { 
        assert (op1.size()==0 || op2.size()==0 
                || op1.size()==op2.size()); 
        return op1.size()!=0 ? op1.size() : op2.size(); 
    } 
    
    std::string type() const
    {     
        return ("A_Mult<"+ op1.type() +", "+ op2.type() +">");
    }
}; 

template <typename T, typename OP1, typename OP2> 
class N_Mult { 
      typename A_Traits<OP1>::ExprRef op1;    // first operand 
      typename A_Traits<OP2>::ExprRef op2;    // second operand 

  public: 
    // constructor initializes references to operands 
    N_Mult(OP1 const& a, OP2 const& b) : op1(a), op2(b) {} 

    // compute sum when value requested 
    T operator[] (size_t idx) const { 
        return pow(op2[idx], op1[idx]); 
    } 

    // size is maximum size 
    size_t size() const { 
        assert (op1.size()==0 || op2.size()==0 
                || op1.size()==op2.size()); 
        return op1.size()!=0 ? op1.size() : op2.size(); 
    } 
    
       std::string type() const
    {
        return "A_Pow<"+op1.type()+", "+op2.type()+">";
    }
}; 

template <typename T> 
class A_Scalar { 
  private: 
    T const& s;  // value of the scalar 

  public: 
    // constructor initializes value 
    A_Scalar (T const& v) : s(v) {} 

    // for index operations the scalar is the value of each element 
    T operator[] (size_t) const { 
        return s; 
    } 

    // scalars have zero as size 
    size_t size() const { 
        return 0; 
    }
    
       std::string type() const
    {
        return "A_Scalar";
    }
}; 


/*
 * Class Array
 */
template <typename T, typename Rep = SArray<T> > 
class Array { 
    Rep expr_rep;   // (access to) the data of the array 

  public: 
    // create array with initial size 
    explicit Array (size_t s) : expr_rep(s) {} 

    // create array from possible representation 
    Array (Rep const& rb) : expr_rep(rb) {} 

    // index operator for constants and variables 
    T operator[] (size_t idx) const { 
        assert(idx<size()); 
        return expr_rep[idx]; 
    } 
    T& operator[] (size_t idx) { 
        assert(idx<size()); 
        return expr_rep[idx]; 
    } 
    
        // assignment operator for same type 
    Array& operator= (Array const& b) { 
        assert(size() == b.size()); 
        for (size_t idx = 0; idx < b.size(); ++idx) { 
            expr_rep[idx] = b[idx]; 
        } 
        return *this; 
    } 
    // assignment operator for arrays of different type 
    template<typename T2, typename Rep2> 
    Array& operator= (Array<T2, Rep2> const& b) { 
        assert(size() == b.size()); 
        for (size_t idx = 0; idx < b.size(); ++idx) { 
            expr_rep[idx] = b[idx]; 
        } 
        return *this; 
    } 

    size_t size() const { 
        return expr_rep.size(); 
    } 
    
     // return what the array currently represents 
    Rep const& rep() const { 
        return expr_rep; 
    } 
    Rep& rep() { 
        return expr_rep; 
    } 
    
    template <typename T2, typename R1, typename R2> 
    friend Array<T2,A_Add<T2,R1,R2> > 
    operator+ (Array<T2,R1> const& a, Array<T2,R2> const& b); 

    template <typename T2, typename R2> 
    friend Array<T2, A_Mult<T2,A_Scalar<T2>,R2> > 
    operator* (T2 const& s, Array<T2,R2> const& b);

    template <typename T2, typename R2> 
    friend Array<T2, A_Add<T2,A_Scalar<T2>,R2> > 
    operator+ (T2 const& s, Array<T2,R2> const& b);
    
    template <typename T2, typename R1, typename R2> 
    friend Array<T2,A_Mult<T2,R1,R2> > 
    operator* (Array<T2,R1> const& a, Array<T2,R2> const& b);

    template <typename T2, typename R2> 
    friend Array<T2, N_Mult<T2,A_Scalar<T2>,R2> > 
    operator^ (Array<T2,R2> const& b, T2 const& s);
    
    std::string type()
    {
        return expr_rep.type() ;
    }
}; 

// Operadores
// addition of scalar and Array 
template <typename T, typename R2> 
Array<T, A_Add<T,A_Scalar<T>,R2> > 
operator+ (T const& s, Array<T,R2> const& b) 
{ 
    return Array<T,A_Add<T,A_Scalar<T>,R2> > 
         (A_Add<T,A_Scalar<T>,R2>(A_Scalar<T>(s), b.rep())); 
} 

// addition of two Arrays 
template <typename T, typename R1, typename R2> 
Array<T,A_Add<T,R1,R2> > 
operator+ (Array<T,R1> const& a, Array<T,R2> const& b) 
{ 
    return Array<T,A_Add<T,R1,R2> > 
           (A_Add<T,R1,R2>(a.rep(),b.rep())); 
} 

// multiplication of scalar and Array 
template <typename T, typename R2> 
Array<T, A_Mult<T,A_Scalar<T>,R2> > 
operator* (T const& s, Array<T,R2> const& b) 
{ 
    return Array<T,A_Mult<T,A_Scalar<T>,R2> > 
         (A_Mult<T,A_Scalar<T>,R2>(A_Scalar<T>(s), b.rep())); 
} 

// multiplication of Array and Array 
template <typename T, typename R1, typename R2> 
Array<T,A_Mult<T,R1,R2> > 
operator* (Array<T,R1> const& a, Array<T,R2> const& b) 
{ 
    return Array<T,A_Mult<T,R1,R2> > 
           (A_Mult<T,R1,R2>(a.rep(),b.rep())); 
} 

// potencia de Array y escalar 
template <typename T, typename R2> 
Array<T, N_Mult<T,A_Scalar<T>,R2> > 
operator^ (Array<T,R2> const& b, T const& s) 
{ 
    return Array<T,N_Mult<T,A_Scalar<T>,R2> > 
         (N_Mult<T,A_Scalar<T>,R2>(A_Scalar<T>(s), b.rep())); 
}

