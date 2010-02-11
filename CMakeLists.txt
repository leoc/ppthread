CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(ppthread CXX)
ADD_DEFINITIONS(-pthread)

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/src")
ADD_LIBRARY(ppthread SHARED src/condition.cpp src/condition.h src/mutex.cpp src/mutex.h src/thread.cpp src/thread.h)

INSTALL(TARGETS ppthread EXPORT ppthread DESTINATION lib)
INSTALL(DIRECTORY src/ DESTINATION include/ppthread FILES_MATCHING PATTERN "*.h")
INSTALL(EXPORT ppthread DESTINATION lib/ppthread)
