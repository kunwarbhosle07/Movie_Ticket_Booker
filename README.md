# MovieTicketBooker-DSA

A console-based Movie Ticket Booking System implemented in C++ that demonstrates core **Data Structures and Algorithms** concepts learned in a DSA course.

---

## Table of Contents

- [Overview](#overview)
- [Data Structures Used](#data-structures-used)
- [Algorithms Used](#algorithms-used)
- [Features](#features)
- [How to Compile and Run](#how-to-compile-and-run)
- [Menu Options](#menu-options)
- [Project Structure](#project-structure)
- [Sample Output](#sample-output)

---

## Overview

This project simulates a basic movie ticket booking system where an admin can:
- Add movies with available seats
- Search for movies by ID
- Sort the movie list
- Book tickets (with automatic waitlist management)
- Undo the last booking
- View all movies via BST inorder traversal

It is built entirely in C++ using standard libraries and no external dependencies.

---

## Data Structures Used

| Data Structure | Purpose |
|---|---|
| **Array** | Primary storage for all movies (`Movie movies[MAX]`) |
| **Linked List** | Secondary sequential storage for movies |
| **Stack** (`std::stack`) | Undo last ticket booking |
| **Queue** (`std::queue`) | Waiting list when seats are full |
| **Binary Search Tree (BST)** | Ordered movie storage; supports inorder display |

---

## Algorithms Used

| Algorithm | Purpose | Complexity |
|---|---|---|
| **Linear Search** | Search movie by ID in unsorted array | O(n) |
| **Binary Search** | Search movie by ID after sorting | O(log n) |
| **Quick Sort** | Sort movies by ID | O(n log n) avg |
| **BST Inorder Traversal** | Display movies in sorted order by ID | O(n) |

---

## Features

- Add unlimited movies (up to array limit of 100)
- Display all movies from array storage
- Search movie by ID using linear search
- Sort movie list by ID using QuickSort
- Book a ticket — decrements available seat count
- Auto-adds customer to **waiting queue** when seats are full
- **Undo** last successful booking using a stack
- Display waiting queue
- Display all movies in BST inorder (sorted by ID)

---

## How to Compile and Run

### Prerequisites
- A C++ compiler (g++ recommended)
- Terminal / Command Prompt

### Compile
```bash
g++ -o moviebooker moviebooking.cpp
```

### Run
```bash
./moviebooker
```

On Windows:
```bash
moviebooker.exe
```

---

## Menu Options

```
1. Add Movie       — Add a new movie with ID, name, and seat count
2. Display         — Show all movies from array storage
3. Search          — Linear search for a movie by ID
4. Sort            — QuickSort movies by ID
5. Book            — Book a ticket; adds to waitlist if full
6. Undo            — Undo the last ticket booking
7. Queue           — Display the waiting queue
8. BST Display     — Show movies via BST inorder traversal (sorted)
9. Exit            — Quit the program
```

---

## Project Structure

```
DSAminiproject/
│
├── moviebooking.cpp     # Main source file (all logic)
└── README.md            # Project documentation
```

### Code Organization inside `moviebooking.cpp`

```
- Movie struct              — Holds id, name, seats
- Array Storage             — movies[MAX], movieCount
- Linked List               — Node class, head pointer
- Stack                     — undoStack (std::stack<string>)
- Queue                     — waitingQueue (std::queue<string>)
- BST                       — BSTNode class, insertBST(), inorder()
- addMovie()                — Adds to array, linked list, and BST
- displayMovies()           — Prints array contents
- linearSearch(id)          — O(n) search in array
- partition() / quickSort() — QuickSort implementation
- binarySearch(id)          — O(log n) search (use after sort)
- bookTicket()              — Books or waitlists
- undoBooking()             — Pops from undo stack
- displayQueue()            — Shows waiting list
- main()                    — Menu-driven loop
```

---

## Sample Output

```
1.Add Movie
2.Display
3.Search
4.Sort
5.Book
6.Undo
7.Queue
8.BST Display
9.Exit
Enter Choice: 1
Movie ID: 101
Movie Name: Inception
Seats: 5
Movie Added

Enter Choice: 5
Enter Movie ID: 101
Ticket Booked

Enter Choice: 6
Undo Booking Of Inception
```

---

## Concepts Demonstrated

- Struct-based data modeling
- Pointer manipulation (Linked List, BST)
- Recursive algorithms (QuickSort, BST traversal)
- STL containers (`std::stack`, `std::queue`)
- Menu-driven console application design

---
