cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/TestFiles")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/CppFiles")

add_executable(runAllTests
  TestReview.cpp
  TestLibrarian.cpp 
  TestAccount.cpp 
  TestLibary.cpp 
  TestLibrarianMenu.cpp 
  TestLibrarySort.cpp 
  TestLogin.cpp 
  TestReccomendations.cpp 
  TestSearchAccount.cpp 
  TestSignUp.cpp 
  TestUser.cpp 
  TestUserMenu.cpp 
  TestBook.cpp
  
)

target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests simpleLibrary)