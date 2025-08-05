
---


# C++ Custom Library with Crow API Support

### Author: Muhammad Ali Sajjad  
### Internship: Intern Intelligence – Summer Internship Program  
### Project Title: Custom C++ Library for Data Structures, Algorithms, Math Utilities, and File Handling  

---

##  Overview

This project is a modular and reusable **C++ library** built from scratch, covering a wide range of:
- Mathematical utilities
- Classic sorting and searching algorithms
- Data structures (VectorArray, Linked Lists, Stack, Queue)
- Tree structures (BST, AVL)
- Graph algorithms (BFS, DFS)
- File handling for persistent leaderboard management

The project also includes an **API layer** built using the **Crow C++ micro web framework**, allowing RESTful access to selected library functions via browser or API testing tools (e.g., Postman).

---

##  Folder Structure

```

📁 Math.h  
📁 Sorting.h  
📁 Searching.h  
📁 VectorArray.h  
📁 FileHandling.h  
📁 SinglyLL.h / DoublyLL.h  
📁 Stack.h / Queue.h  
📁 BST.h / AVL.h  
📁 Graph.h  
📁 API.h  
📁 Testing.h  
📁 main.cpp  


```

---

##  Setup Instructions

###  C++ Setup (Visual Studio)

1. **Download** the Crow header (`crow_all.h`) and **Asio Standalone** (e.g., asio-1.28.1.zip).
2. Extract Asio (e.g., `C:\libraries\asio-1.28.1`).
3. In your project properties:
   - **C/C++ ? Language ? C++ Standard** ? set to **C++17 or later**
   - **C/C++ ? General ? Additional Include Directories**:
     - `$(ProjectDir)`
     - `C:\libraries\asio-1.28.1\include` *(adjust to your path)*

4. Make sure `crow_all.h` is in your project directory.

---

##  Running the Project

### Option 1: CLI Testing Mode

```bash
# Choose option 1 in console prompt
# Tests all data structures and functions via console output
```

### Option 2: API Server Mode

```bash
# Choose option 2 in console prompt
# Launches the Crow server
```

Then visit the API endpoints in your browser.

---

##  API Endpoints (Crow)

###  Math API

| Feature       | URL                    | Example Output |
| ------------- | ---------------------- | -------------- |
| Abs           | `/math/abs/-5`         | `5`            |
| Factorial     | `/math/fact/5`         | `120`          |
| GCD           | `/math/gcd/18/24`      | `6`            |
| LCM           | `/math/lcm/4/6`        | `12`           |
| Palindrome    | `/math/palindrome/121` | `true`         |
| Reverse       | `/math/reverse/432`    | `234`          |
| isEven        | `/math/even/10`        | `true`         |
| Sum of Digits | `/math/sumdigits/1234` | `10`           |

###  VectorArray API

| Feature | URL               |
| ------- | ----------------- |
| Push    | `/vector/push/10` |
| Show    | `/vector/show`    |
| Pop     | `/vector/pop`     |
| Size    | `/vector/size`    |
| Find    | `/vector/find/10` |

###  Stack API

| Feature | URL              |
| ------- | ---------------- |
| Push    | `/stack/push/12` |
| Pop     | `/stack/pop`     |
| Peek    | `/stack/peek`    |
| isEmpty | `/stack/empty`   |

###  Search API

| Feature       | URL                 |
| ------------- | ------------------- |
| Linear Search | `/search/linear/25` |

###  Logging and Greeting

| Feature           | URL               | Output         |
| ----------------- | ----------------- | -------------- |
| Console Log       | `/log/99`         | Console prints |
| Greet (with name) | `/greet?name=Ali` | Hello, Ali     |
| Greet (no name)   | `/greet`          | Hello, Guest   |

---

##  Example Usage in C++

```cpp
#include "Math.h"
#include "VectorArray.h"

int main() {
    Math m;
    std::cout << m.factorial(5); // Outputs 120

    VectorArray<int> v;
    v.push_back(10);
    v.insert(5, 1);
    v.show();
}
```

---

##  What I Learned

* Template-based OOP in C++
* Manual memory management (dynamic arrays, linked lists)
* STL-style design patterns without using STL
* Crow API server design & modular integration
* Functional separation using header files
* File persistence using plain text leaderboard

---

##  License

This project is open for educational and demonstration purposes.
You can freely use and extend it under a permissive license (MIT or others – choose when publishing).

---

```
