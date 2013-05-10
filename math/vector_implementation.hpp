// Emacs Mode Line: -*- Mode:c++;-*-
// -------------------------------------------------------------
/**
 * @file   vector_implementation.h
 * @author William A. Perkins
 * @date   2013-05-10 09:00:43 d3g096
 * 
 * @brief  
 * 
 * 
 */
// -------------------------------------------------------------
// -------------------------------------------------------------
// Created March 26, 2013 by William A. Perkins
// Last Change: Thu Jun  3 06:45:08 2010 by William A. Perkins <d3g096@PE10900.pnl.gov>
// -------------------------------------------------------------

#ifndef _vector_implementation_h_
#define _vector_implementation_h_


#include "gridpack/parallel/distributed.hpp"
#include "gridpack/utilities/uncopyable.hpp"
#include "gridpack/math/math_type.hpp"

namespace gridpack {
namespace math {

class ImplementationVisitor;
class ConstImplementationVisitor;

// -------------------------------------------------------------
//  class VectorImplementation
// -------------------------------------------------------------
class VectorImplementation 
  : private utility::Uncopyable,
    public parallel::Distributed
{
public:

  /// Default constructor.
  VectorImplementation(const parallel::Communicator& comm);

  /// Destructor
  ~VectorImplementation(void);

  /// Get the global length
  int size(void) const
  {
    return this->p_size();
  }

  /// Get the local length
  int local_size(void) const
  {
    return this->p_local_size();
  }

  /// Get the local min/max global indexes
  void local_index_range(int& lo, int& hi) const
  {
    return this->p_local_index_range(lo, hi);
  }

  /// Set an individual element
  void set_element(const int& i, const complex_type& x)
  {
    this->p_set_element(i, x);
  }

  /// Set an several elements
  void set_elements(const int& n, const int *i, const complex_type *x)
  {
    this->p_set_elements(n, i, x);
  }

  // /// Add to an individual element
  // void add_element(const int& i, const complex_type& x)
  // {
  //   this->p_add_element(i, x);
  // }

  // /// Add to an several elements
  // void add_elements(const int& n, const int *i, const complex_type *x)
  // {
  //   this->p_add_elements(n, i, x);
  // }

  /// Get an individual element
  void get_element(const int& i, complex_type& x) const
  {
    this->p_get_element(i, x);
  }

  /// Get an several elements
  void get_elements(const int& n, const int *i, complex_type *x) const
  {
    this->p_get_elements(n, i, x);
  }

  /// Make all the elements zero
  void zero(void)
  {
    this->p_zero();
  }

  /// Make all the elements the specified value
  void fill(const complex_type& v)
  {
    this->p_fill(v);
  }

  // FIXME: more ...

  /// Make this instance ready to use
  void ready(void)
  {
    this->p_ready();
  }

  /// Allow visits by implemetation visitor
  void accept(ImplementationVisitor& visitor)
  {
    this->p_accept(visitor);
  }

  /// Allow visits by implemetation visitor
  void accept(ConstImplementationVisitor& visitor) const
  {
    this->p_accept(visitor);
  }

protected:

  /// Get the global vector length (specialized)
  virtual int p_size(void) const = 0;

  /// Get the size of the vector local part (specialized)
  virtual int p_local_size(void) const = 0;

  /// Get the local min/max global indexes (specialized)
  virtual void p_local_index_range(int& lo, int& hi) const = 0;

  /// Set an individual element (specialized)
  virtual void p_set_element(const int& i, const complex_type& x) = 0;

  /// Set an several elements (specialized)
  virtual void p_set_elements(const int& n, const int *i, const complex_type *x) = 0;

  // /// Add to an individual element (specialized)
  // virtual void p_add_element(const int& i, const complex_type& x) = 0;

  // /// Add to an several elements (specialized)
  // virtual void p_add_elements(const int& n, const int *i, const complex_type *x) = 0;

  /// Get an individual element (specialized)
  virtual void p_get_element(const int& i, complex_type& x) const = 0;

  /// Get an several elements (specialized)
  virtual void p_get_elements(const int& n, const int *i, complex_type *x) const = 0;

  /// Make all the elements zero (specialized)
  virtual void p_zero(void) = 0;

  /// Fill all the elements with the specified value (specialized)
  virtual void p_fill(const complex_type& v) = 0;

  // FIXME: more ...
  /// Make this instance ready to use
  virtual void p_ready(void) = 0;

  /// Allow visits by implementation visitors
  virtual void p_accept(ImplementationVisitor& visitor) = 0;

  /// Allow visits by implementation visitors
  virtual void p_accept(ConstImplementationVisitor& visitor) const = 0;

};

} // namespace math
} // namespace gridpack



#endif
