# Library Management System

A simple **_Library Management System_** written in **C++** and built using **Cmake**. Designed as a clean, modular project to practice real world **Object Oriented Programming** and **C++ structures**.

---

## Features

- Store and manage books in a local dataset
- Modular codebase with seperated headers and source files
- Cmake used for building the program
- Seperates different roles and responsibilities depending on the users role (Customer/Admin)

---

## Project Structure

The program is structured like below:

```text
.
├── Include/         # Header files
├── src/             # Source files
├── Books.csv        # Book database (CSV storage, temporary)
├── CMakeLists.txt   # Build configuration
```

---

## Building and running

#### Requirements:

- CMake (3.16+ is recommended)
- A C++ compiler

#### Build and Run:

From the repo root:

```bash
mkdir -p build
cmake -S . -B build
cmake --build build
```

Then, once built proceed to run the program using:

```bash
./build/library
```
