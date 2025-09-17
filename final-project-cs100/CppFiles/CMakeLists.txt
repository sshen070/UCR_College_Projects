add_library(simpleLibrary
  Account.cpp
  AccountDatabase.cpp
  Book.cpp
  Librarian.cpp
  Library.cpp
  # LibrarySorts.cpp
  Login.cpp 
  Review.cpp
  SignUp.cpp 
  User.cpp
  UserMenu.cpp
  
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})