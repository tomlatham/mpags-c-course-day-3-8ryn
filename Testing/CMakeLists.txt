# - Build sub-script for the MPAGSCipher library unit tests

# Most basic test
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# Create Interface Library for Catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# First Catch-based test
add_executable(testCatch testCatch.cpp)
target_include_directories(testCatch PRIVATE ${CMAKE_CURRENT_LIST_DIR})
add_test(NAME test_catch COMMAND testCatch)

# Test TransformChar
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformchar COMMAND testTransformChar)
