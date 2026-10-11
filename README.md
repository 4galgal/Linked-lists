
# Linked Lists — Kanban Board in C

## Overview

A command-line Kanban board built in C to manage tasks across multiple lists. The project uses **doubly linked lists** to represent board columns and the tasks within them, allowing users to create, edit, and organise their board dynamically.

The board can also be saved to a text file and loaded again later, demonstrating how dynamic data structures can be serialised into a persistent format and reconstructed when needed.

## Features

- **Board Management:** Organise tasks into separate lists representing different stages of a workflow.
- **List Management:** Add, rename, and delete board lists.
- **Task Management:** Add, search for, and delete tasks within individual lists.
- **Save and Load:** Export the board to a text file and reconstruct the board from a saved file.
- **Dynamic Memory Management:** Allocate and free memory as lists and tasks are created or removed.
- **Modular Design:** Separate functionality into dedicated C source and header files to improve code organisation and maintainability.

## Technical Implementation

### Doubly Linked Lists

The board consists of two interconnected levels of doubly linked lists:

- **Lists:** Each list represents a column on the board and contains pointers to the previous and next lists, as well as its tasks.
- **Items:** Each task is stored in a separate node, linked to the previous and next tasks within its list.

This structure supports traversal in both directions and allows nodes to be inserted or removed by updating their neighbouring pointers.

### File Persistence

The board is saved as a plain-text file, with each list name followed by a colon and its tasks written on separate lines.

When loading a board, the program parses the file line by line to distinguish list headers from tasks, dynamically allocates the required nodes, and rebuilds the linked-list structure.

### Memory Management

The project uses dynamic memory allocation to create lists and task nodes at runtime. When deleting a list, its associated tasks are freed before the list itself is deallocated. Existing board memory is also released before a saved board is loaded, helping prevent memory leaks.

### Modular Architecture

The implementation separates board persistence and editing functionality into dedicated modules, including `loadBoard` and `saveBoard` for file operations, and `editBoard.c` and `editList.c` for managing lists and tasks.

## Concepts Demonstrated

- C programming and structured code organisation
- Structures (`struct`) and pointers
- Doubly linked lists and nested data structures
- Dynamic memory allocation and deallocation
- Pointer manipulation and double pointers
- File I/O using text files
- Linear search algorithms
- Modular programming and separation of concerns
- Time complexity analysis for linked-list operations

## Technologies

- **Language:** C
- **Data Structures:** Doubly linked lists
- **Storage:** Plain-text files
- **Build System:** CMake, if configured in the project

## Getting Started

Clone the repository:

```bash
git clone https://github.com/4galgal/Linked-lists.git
cd Linked-lists
```

Build and run the project using the build instructions for the included source files and build configuration.

## Author

Developed as part of my computer science studies to apply data structures and memory management concepts in a practical programming project.
