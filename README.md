# README

## Overview
This code is a simple demonstration of my familiarity with the **C++ programming language**, including syntax, threading, mutex usage, and basic operations with data structures. It is **not intended for any practical use** such as stock trading, financial modeling, or performance optimization. Instead, it serves solely as an educational example showcasing my ability to:

- Use multithreading to simulate concurrent operations.
- Manage shared resources safely using **mutex locks**.
- Work with C++ STL components like **vectors** and **threads**.
- Implement basic structured programming techniques.

## Description
The program simulates a simplistic stock trading scenario. It uses:
1. A `StockData` struct to store properties of a stock.
2. A vector of `StockData` objects as a small dataset.
3. Threads to concurrently handle the buying and selling of stocks.
4. A mutex (`money_mutex`) to synchronize access to shared financial data (`current_money`).

Each stock is either bought or sold based on its `should_buy` flag, and the program tracks the resulting money balance.

### Key Features:
- **Threading:** Demonstrates the use of the `std::thread` library to perform operations in parallel.
- **Mutex Locking:** Ensures safe access to shared resources using `std::mutex` and `std::lock_guard`.
- **Simple Data Handling:** Uses structs and vectors to organize and process data.

### Example Output:
The program outputs messages about the buying and selling of stocks and displays the final amount of money after all operations.

```cpp
Bought stock for 150 dollars
Sold stock for 120 dollars
Bought stock for 180 dollars
Final money: 100550 dollars
```

## Disclaimer
This code:
- Is not optimized for performance or error handling.
- Does not reflect real-world stock trading logic.
- Was not written for deployment or integration into any systems.

Its sole purpose is **to demonstrate proficiency with core C++ features**.

## How to Run
1. Compile the code using a C++ compiler that supports C++11 or later (e.g., `g++`):

```cpp
g++ -std=c++11 -o stock_trading_simulation stock_trading_simulation.cpp
```

2. Execute the compiled binary:

```cpp
./stock_trading_simulation
```

## Dependencies
- C++11 or later.
- A standard C++ compiler (e.g., GCC, Clang, or MSVC).

## Conclusion
This code reflects my ability to write clean and functional C++ code, focusing on syntax, data structures, and threading mechanics. It is an academic artifact and **should not be interpreted as a real-world application**.
