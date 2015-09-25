// Emacs Mode Line: -*- Mode:c++;-*-
// -------------------------------------------------------------
/*
 *     Copyright (c) 2013 Battelle Memorial Institute
 *     Licensed under modified BSD License. A copy of this license can be found
 *     in the LICENSE file in the top level directory of this distribution.
 */
// -------------------------------------------------------------
// -------------------------------------------------------------
/**
 * @file   cplex_optimizer_implementation.hpp
 * @author William A. Perkins
 * @date   2015-09-01 14:22:31 d3g096
 * 
 * @brief  
 * 
 * 
 */
// -------------------------------------------------------------


#ifndef _cplex_optimizer_implementation_hpp_
#define _cplex_optimizer_implementation_hpp_

#include "optimizer.hpp"

namespace gridpack {
namespace optimization {



// -------------------------------------------------------------
//  class CPlexOptimizerImplementation
// -------------------------------------------------------------
class CPlexOptimizerImplementation 
  : public OptimizerImplementation
{
public:

  /// Default constructor.
  CPlexOptimizerImplementation(const parallel::Communicator& comm)
    : OptimizerImplementation(comm)
  {}

  /// Destructor
  ~CPlexOptimizerImplementation(void)
  {}

protected:
  
  /// Do the problem (specialized)
  void p_solve(const p_optimizeMethod& m);
  
};


} // namespace optimization
} // namespace gridpack


#endif