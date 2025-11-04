====================================================
LIBRARY MANAGEMENT SYSTEM PROJECT  (Two-Person Version)
====================================================

Participants:
    Person A  →  SYSTEM ARCHITECT & CLASS DEVELOPER  
    Person B (Joshua)  →  MAIN PROGRAM INTEGRATOR  

Compiler:
    MinGW-w64 g++ 15.2.0 (64-bit, POSIX, SEH, UCRT)

Build command:
    g++ main.cpp Book.cpp BookManager.cpp Member.cpp LibrarySystem.cpp -o Library.exe

----------------------------------------------------
PROJECT DIRECTORY STRUCTURE
----------------------------------------------------
📁 LibraryProject/
│
├── main.cpp                     ← Person B (Joshua)
│
├── Book.h                       ← Person A
├── Book.cpp                     ← Person A
│
├── BookManager.h                ← Person A
├── BookManager.cpp              ← Person A
│
├── Member.h                     ← Person A
├── Member.cpp                   ← Person A
│
├── LibrarySystem.h              ← Person A
├── LibrarySystem.cpp            ← Person A
│
└── README.txt                   ← this file

----------------------------------------------------
PERSON A — SYSTEM ARCHITECT & CLASS DEVELOPER
----------------------------------------------------

Goal: Design and implement all object-oriented modules that form the core of the system.  
Focus: All classes, logic, data handling, and file I/O.

STEP-BY-STEP TASKS (chronological)
----------------------------------
1- Book Class  
 • Create Book.h / Book.cpp  
 • Members: int id, string title, string author, bool isBorrowed  
 • Methods: constructors, getters, borrowBook(), returnBook(), display()

2- BookManager Class  
 • Create BookManager.h / BookManager.cpp  
 • Manage vector<Book> collection  
 • Implement: addBook(), removeBook(), findBookById(), borrowBookById(), returnBookById(), displayAll(), saveToFile(), loadFromFile()

3- Member Class  
 • Create Member.h / Member.cpp  
 • Members: int memberID, string name  
 • Methods: constructors, getters, display()

4- Testing & Verification  
 • Verify each class compiles and works individually.  
 • Ensure file I/O, add/borrow/return functions are correct.  
 • Comment every function for clarity.

----------------------------------------------------
PERSON B (JOSHUA) — MAIN PROGRAM INTEGRATOR
----------------------------------------------------

Goal: Write main.cpp and librarySystem.h and corresponding cpp to interface with Person A’s classes and run the menus.

STEP-BY-STEP TASKS
-------------------
1- LibrarySystem Class  
 • Create LibrarySystem.h / LibrarySystem.cpp  
 • Contains BookManager object  
 • Provides mainMenu(), bookMenu(), memberMenu()  
 • Handles user logic so main.cpp only needs to call mainMenu() 
2- Create the main() function:
       #include "LibrarySystem.h"
       int main() {
            LibrarySystem system;
            system.mainMenu();
            return 0;
       }
3- Handle user menu input inside LibrarySystem methods.  
4- Run tests and ensure the system responds properly.  
5- Document and prepare for submission.

----------------------------------------------------
FUNCTION OF THE PROJECT
----------------------------------------------------

Purpose:
 A console-based Library Management System that lets the user add, borrow, return, remove, display, and store books using C++ OOP and file I/O.

Main Capabilities:
 1. Store book records (ID, title, author, status).  
 2. Add books dynamically (using std::vector).  
 3. Borrow and return books (changing availability status).  
 4. Search and display all books in a formatted table.  
 5. Save and load book data to/from books.txt.  
 6. Provide menu-driven navigation through the console.

----------------------------------------------------
HOW THE SYSTEM WORKS (INTERNALLY)
----------------------------------------------------

• Book Class – Represents a single book and its state.  
• BookManager Class – Stores and manages all Book objects in a vector.  
• Member Class – Represents a library user (future expansion).  
• LibrarySystem Class – Coordinates menu logic and delegates work to BookManager.  
• main.cpp – Starts the program by creating a LibrarySystem and calling mainMenu().

----------------------------------------------------
USER FLOW (EXECUTION)
----------------------------------------------------
1️⃣ Program launches → loads books.csv 
2️⃣ Main menu appears:
 ===== LIBRARY MENU =====
 1. Manage Books  
 2. Exit  
 Choice: _

3️⃣ Book menu:
 --- BOOK MENU ---
 1. Add Book  
 2. Borrow Book  
 3. Return Book  
 4. Display All  
 5. Back  

4️⃣ User inputs choices → BookManager executes corresponding function.  
5️⃣ Program saves changes to books.txt on exit.

----------------------------------------------------
DATA FLOW (ARCHITECTURE)
----------------------------------------------------
main.cpp  
 ↓  
LibrarySystem → BookManager → Book objects  
 ↓  
books.csv (file storage)

----------------------------------------------------
TECHNICAL SUMMARY
----------------------------------------------------
• Encapsulation: Each class owns its own data.  
• Composition: LibrarySystem contains BookManager; BookManager contains Books.  
• File I/O: BookManager saves/loads data persistently.  
• Dynamic Data: std::vector used for scalable storage.  
• Interface: Text-based menus via cout/cin.  
• Error Handling: Check for invalid input and missing files.  
• Documentation: Every function well-commented.

----------------------------------------------------
WORKFLOW TIMELINE
----------------------------------------------------
🕐 Phase 1 – Person A builds all classes and tests individually.  
🕑 Phase 2 – Person A hands off finished modules to Joshua.  
🕒 Phase 3 – Joshua creates main.cpp and LibrarySystem and integrates system.  
🕓 Phase 4 – Both run debug and function tests.  
🕔 Phase 5 – Finalize README and submit.

----------------------------------------------------
NOTES & REMINDERS
----------------------------------------------------
• Person A owns and maintains all headers and classes.  
• Person B writes and tests only main.cpp.  
• Always use include guards in headers.  
• Use consistent naming and commenting across files.  
• Final testing should verify data persistence and menu flow.

====================================================
END OF README FILE
====================================================
