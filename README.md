# Library Management System

A C++17 library management project focused on object-oriented design, collection management, borrowing state, and CSV persistence. The current executable is a demonstration harness that exercises the core library operations rather than an interactive end-user application.

## Features

- Model books and members with separate C++ classes
- Store books in an `std::unordered_map` keyed by ID
- Add, remove, find, borrow, and return books
- Reject duplicate book IDs and invalid borrowing operations
- Load the book collection from `Books.csv`
- Save the current collection back to `Books.csv`
- Track a member role value for future role-aware behavior
- Organize declarations and implementations across headers and source files
- Build with CMake

> **Current scope:** Member roles are represented in the domain model, but role-specific permissions and authentication are not implemented.

## Project Structure

```text
.
├── Include/              # Header files
├── src/                  # Implementations and demonstration main()
├── Books.example.csv     # Example CSV input
├── CMakeLists.txt        # Build configuration
└── README.md
```

The runtime `Books.csv` file is intentionally ignored by Git because the program reads from and writes to it locally. To start with sample data:

```bash
cp Books.example.csv Books.csv
```

## Building and Running

### Requirements

- CMake 3.16+
- A C++17-compatible compiler

### Build

```bash
cmake -S . -B build
cmake --build build
```

### Run

```bash
./build/library
```

The current `main.cpp` demonstrates loading data, adding and removing books, saving to CSV, and a borrow/return cycle.

## Current Limitations

- The executable is a fixed demonstration rather than an interactive CLI.
- Authentication is not implemented.
- Member roles are stored but do not currently enforce different permissions.
- Automated tests have not yet been added.
