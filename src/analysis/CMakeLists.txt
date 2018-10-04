#
#     Copyright (c) 2013 Battelle Memorial Institute
#     Licensed under modified BSD License. A copy of this license can be
#     found
#     in the LICENSE file in the top level directory of this distribution.
#
# -*- mode: cmake -*-
# -------------------------------------------------------------
# file: CMakeLists.txt
# -------------------------------------------------------------
# -------------------------------------------------------------
# Created May  6, 2013 by William A. Perkins
# Last Change: 2014-01-08 09:17:34 d3g096
# -------------------------------------------------------------
add_library(gridpack_analysis
  stat_block.cpp
)

set(target_libraries
    gridpack_analysis
    ${GA_LIBRARIES}
    ${Boost_LIBRARIES}
    ${MPI_CXX_LIBRARIES})

include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})
if (GA_FOUND)
    include_directories(AFTER ${GA_INCLUDE_DIRS})
endif()

# -------------------------------------------------------------
# installation
# -------------------------------------------------------------
install(FILES 
  stat_block.hpp  
  DESTINATION include/gridpack/analysis
)

install(TARGETS 
  gridpack_analysis
  DESTINATION lib
)

