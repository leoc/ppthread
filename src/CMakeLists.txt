ADD_DEFINITIONS(-pthread)

SET(HEADER_FILES condition.h mutex.h thread.h)
SET(SOURCE_FILES condition.cpp mutex.cpp thread.cpp)
ADD_LIBRARY(ppthread SHARED ${HEADER_FILES} ${SOURCE_FILES})

INSTALL(TARGETS ppthread DESTINATION lib)
INSTALL(FILES ${HEADER_FILES} DESTINATION include/ppthread)
