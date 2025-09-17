# Project: Library System
 
 > Authors: [Kevin Tam](https://github.com/ktamtc255), [Brandon Ng](https://github.com/BrandonNg-UCR), [Sujith Shen](https://github.com/sshen070), [Steve Carl Cordero](https://github.com/SteveCordero)

## Project Description

 * Library System: 
 * Importance/Interests: Allows you to digitally view books rather than needing to borrow or buy a physical copy. Digital access can be more convenient for some people.
 * Languages/Tools/Technologies: C++ , VsCode, GDB, Valgrind
 * Input: Log-in info, payment info, book title, book genre, borrow request, purchase request, etc.
 * Output: Account status, list of books, borrow status, purchase status, etc.
 * Features: Recommendations, sorting based on rating, sorting based on popularity, other forms of sorting, reviews, addition/removal of book availability, etc.
   * Reccomendations: Displays a list of books that the user might enjoy based on their reading history, or a list of popular books if no reading history
   * Sorting: books can be filtered and sorted by their rating(descending/ascendin g), genre, popularity(# of book sales), or alphabetical, each will be displayed a list
   * Reviews: Users can submit their personal opinions on books, along with providing a rating(1-5)
   * Addition/Removal of book availability: User can add books into the library, and system will display whether a book is available or unavailble  

> 
 ## Phase II
 
## User Interface Specification


### Navigation Diagram
![image](https://github.com/user-attachments/assets/3b6f27d5-4945-4f1d-bea6-3bb654c64b1e)
  * The librarian or reader of the program will enter the program and be presented with a login screen, where it will only take valid input to access respective menu screen based on the account type of the user(Reader or Librarian). The menu will allow reader to view books, while the librarian can add/remove books, view books, search accounts. They are also presented with the optiont to logout. The view book screen will display a list of books in alphabetical order. The view books will lead to other screen that will display the books in order by rating, popularity, or genre. The book details screen will show the detail of each back. The menu also present the search account screen, which will let the library find and edit accounts. The option to remove and add books is also available and will let the library add or remove books that are present in the system.


### Screen Layouts
> <img width="393" alt="Screenshot 2025-02-10 at 9 26 03 PM" src="https://github.com/user-attachments/assets/6d4a98d5-aae1-476c-9a13-db2e08ebe531" />
  * Login Screen - Login screen where the user or librarian will be prompted to enter their login details, and only be accepted when password matches.
    
> <img width="499" alt="Screenshot 2025-02-10 at 3 35 29 PM" src="https://github.com/user-attachments/assets/9ea784f9-a8b1-497a-b197-a6254d7f0811" />
  * Login Menu - List of options User can have after logging in successfully. The Librarian will have access to add/remove books, logout, search accounts, and view books. The Readers can only view books.
    
> <img width="774" alt="Screenshot 2025-02-10 at 4 04 50 PM" src="https://github.com/user-attachments/assets/308f3bb0-eea4-4b4b-990a-9cd3f7d0764c" />
  * Book List View - List of books, viewed in alphabetical order. The Reader or Librarian can view a list of books on this screen and are prompted to enter a name of a displayed book to view its content and details.
   
> <img width="451" alt="Screenshot 2025-02-10 at 4 07 42 PM" src="https://github.com/user-attachments/assets/2f5cfd54-8989-41ab-9563-310b2dcb1ba4" />
  * Book Details View - Shows book's details: Title, Genre, Copies Sold, Rating, Reviews.

> <img width="875" alt="Screenshot 2025-02-10 at 4 39 44 PM" src="https://github.com/user-attachments/assets/ec7e4b89-5d5f-40d9-9508-f7251e8bfccf" />
  * Account Search Screen - Gives the library an option to remove an account from the account database, or to add an account into it
    
> <img width="696" alt="Screenshot 2025-02-10 at 5 24 31 PM" src="https://github.com/user-attachments/assets/51f256b6-7361-431e-ba5d-41361e9d6956" />
  * Book Remove/Add Screen - Prompts the user to choose between adding or removing a book from the library and brings them to their respective screen
    
> <img width="635" alt="Screenshot 2025-02-10 at 5 36 20 PM" src="https://github.com/user-attachments/assets/b99c8f3c-6e53-4fd0-bb45-42d0b85a5db9" />
  * Book Add Screen - This will prompt the librarian to enter valid input regarding details about the book such as the title, genre, and it's total sales








## Class Diagram
![CD](https://github.com/user-attachments/assets/4a23de83-8ffb-4268-be57-ec9574de5da7)
  * Our program will require us to use 4 main classes, which include the library class, book class, AccountDatabase class, Account Class, and review class. The library class will handle the main function of remove, adding, and storing the books of the library. The book class will hold all the information of each book that is in the library. The Review class will hold all the information in one user review of each book which will all be held in the book class. The Accoutn database class will simply act as a container for all the accounts that the library will store, and the account class will hold all the information of each account such as usernames, passwords, and accout type. The account type will be used to determine the menu screen presented to the account user (librarian or reader)

 
 ## Phase III
 
 
<img width="1024" alt="Screenshot 2025-02-28 at 2 46 46 PM" src="https://github.com/user-attachments/assets/5145b9fd-d7b4-46f6-af56-8eb417187455" />
 * Our updated class diagram takes into consideration Single Responsibility, Open Close, Liskov Substituion, and Interface Segregation.
   
 * This is shown with how we split up Accounts and Library to have to have subclasses so they do not handle too many functions, this will help us develop better organization with the classes we use.
   
 * Open close is shown by these subclasses handling one feature, so extending or adding another function is possible without changing prior source code such as Account class where it is open to add more account types without having to change existing code. This helps us make better code by leaving future features open to implementation without disrupting already working code.
 
 * Liskov subsitution is handled by instances where subclasses such as sorted libraries can be used in other classes (librarian/user) instead of the library object. This will help our code with being able to pass an already made class without completely relying on the subclass.
 
 * Interface segregation is handled by organizing the methods of our superclass into their respective subclasses which was done to Libmenu and Umenu for the seperate accounts, helping us prevent writing redundant code that we would have to work around otherwise.

 * Note: The arrows are suppose to be the diamonds for composition and aggregation besides the one connecting from account to librarian and user which are suppose to be inheritance

 
  ## Final deliverable
  # Updated Class Diagram
  <img width="1024" alt="Screenshot 2025-03-14 at 2 58 05 PM" src="https://github.com/user-attachments/assets/bb6b71f4-d646-43e0-8fdb-c850e6e5056f" />

 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ![image](https://github.com/user-attachments/assets/01840dbc-22cb-4f05-891e-57237d23e23a)
 ![image](https://github.com/user-attachments/assets/4532663d-f1c8-4706-a8f0-c49d4c1ba962)


 ## Installation/Usage
 1. Clone the repository(if you want to run the tests clone recursively)
 2. run cd final-project-cs100projectgroup3-lab023
 3. run cd CppFile/
 4. run g++ -o program main.cpp AccountDatabase.cpp Account.cpp User.cpp Librarian.cpp Login.cpp SignUp.cpp Library.cpp Book.cpp UserMenu.cpp
 5. run ./program
 6. enjoy our library!
 ## Testing
 * Tests were done through an executable made using cmake, make, and googletest. The executable is called "runAllTests" and it is found in the "TestFiles" folder after running cmake and make.
 * Library Feature: Tests were done on the book constructor, setting copies, view book, ... (add more)
 * Review Feature: Tests were done on the review constructor, setting comments and ratings, adding reviews, removing reviews, editing reviews, view reviews, and setting the average rating.
 * User Account: Tests were done on the User constructor, BookisCheckedOut, checkOutBook, and returnBook functions
 
