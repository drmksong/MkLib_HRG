CMAKE_MINIMUM_REQUIRED(VERSION 3.15.0)

SET(proj_name "MkLib")
PROJECT(${proj_name})

SET(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(src)

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)
# ADD_SUBDIRECTORY(googletest)

# SET (srcs MkArray.cpp MkColor.cpp MkMatrix.cpp MkMisc.cpp MkPoint.cpp MkPointData.cpp )

# ADD_DEFINITIONS(-DMKDEBUG)
# ADD_LIBRARY(MkLib ${srcs})
# ADD_EXECUTABLE(test test.cpp)



# PROJECT( ${proj_name} )

# C++ settings
