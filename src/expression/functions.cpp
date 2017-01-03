// -------------------------------------------------------------
/*
 *     Copyright (c) 2013 Battelle Memorial Institute
 *     Licensed under modified BSD License. A copy of this license can be found
 *     in the LICENSE file in the top level directory of this distribution.
 */
// -------------------------------------------------------------
// -------------------------------------------------------------
/**
 * @file   functions.cpp
 * @author William A. Perkins
 * @date   2016-11-01 12:30:58 d3g096
 * 
 * @brief  
 * 
 * 
 */
// -------------------------------------------------------------
// -------------------------------------------------------------
// Created October 31, 2016 by William A. Perkins
// Last Change: 2013-05-03 12:23:12 d3g096
// -------------------------------------------------------------

#include <algorithm>
#include <numeric>
#include <boost/bind.hpp>

#include "functions.hpp"

// Cannot do this because these classes have a boost::shared_ptr member
// #include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/weak_ptr.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

BOOST_CLASS_EXPORT_IMPLEMENT(gridpack::optimization::Function);

namespace gridpack {
namespace optimization {

// -------------------------------------------------------------
//  class Function
// -------------------------------------------------------------

// -------------------------------------------------------------
// Function constructors/destructors
// -------------------------------------------------------------

Function::Function(const std::string& name, 
                   const std::vector<ExpressionPtr>& args)
  : Expression(0),
    p_fname(name), p_args(args)
{}

Function::Function(void)
  : Expression(0), 
    p_fname(), p_args()
{}

Function::~Function(void)
{}

// -------------------------------------------------------------
// Function::p_null
// -------------------------------------------------------------
bool
Function::p_null(void) const
{
  bool result(p_fname.size() == 0);
  // check to see if any of the arguments are null
  result = std::accumulate(p_args.begin(), p_args.end(), false,
                           boost::bind(std::logical_or<bool>(), _1, 
                                       boost::bind(&Expression::null, _2)));
  return result;
}

// -------------------------------------------------------------
// ExpressionVisitor::visit
// -------------------------------------------------------------
void ExpressionVisitor::visit(Function& e) 
{
  e.accept(*this);
}

// -------------------------------------------------------------
// sin
// -------------------------------------------------------------
ExpressionPtr
sin(ExpressionPtr e)
{
  std::vector<ExpressionPtr> args;
  args.push_back(e);
  FunctionPtr f(new Function("sin", args));
  return f;
}

// -------------------------------------------------------------
// cos
// -------------------------------------------------------------
ExpressionPtr
cos(ExpressionPtr e)
{
  std::vector<ExpressionPtr> args;
  args.push_back(e);
  FunctionPtr f(new Function("cos", args));
  return f;
}

} // namespace optimization
} // namespace gridpack

