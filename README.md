# 🚗 Automated Vehicle Toll Management System

## 📌 Project Overview

The **Automated Vehicle Toll Management System** is a console-based application developed using the C programming language. It is designed to manage vehicle entries, calculate toll charges, maintain transaction records, and generate daily toll collection reports.

The system automatically records the vehicle number, vehicle type, entry date, entry time, and toll amount. It also provides a 20% discount during off-peak hours.

The project uses **Structures, Dynamic Memory Allocation, File Handling, Functions, and Date-Time Handling** to manage toll transactions efficiently.

## ✨ Features

- **Vehicle Registration:** Register vehicles using their vehicle number and type.
- **Automatic Toll Calculation:** Calculate toll charges according to vehicle category.
- **Off-Peak Discount:** Automatically apply a 20% discount during off-peak hours.
- **Vehicle Search:** Search transaction records using a vehicle number.
- **Date-Based Search:** Find all transactions recorded on a particular date.
- **Daily Toll Report:** Generate daily reports with vehicle counts and total collection.
- **Display Transactions:** View all previously recorded transactions.
- **File Storage:** Save transaction records permanently in `toll_data.txt`.
- **Dynamic Memory Allocation:** Automatically expand memory when additional transactions are added.

## 🚙 Vehicle Categories and Toll Rates

| Vehicle Type | Toll Amount |
|---|---:|
| Car | ₹100 |
| Truck | ₹200 |
| Bus | ₹150 |
| Bike | ₹50 |

### Off-Peak Discount

The system provides a **20% discount** during the following hours:

- Before 6:00 AM
- From 10:00 PM onward

**Example:**

If a car enters the toll plaza during off-peak hours:

- Original Toll = ₹100
- Discount = 20%
- Final Toll = ₹80

## 🛠️ Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Libraries:**
  - `stdio.h` – Input and output operations
  - `stdlib.h` – Dynamic memory allocation
  - `string.h` – String handling
  - `time.h` – Date and time management

## 📋 Menu Options

The application provides the following menu:

| Option | Function |
|---|---|
| 1 | Register Vehicle / Collect Toll |
| 2 | Search by Vehicle Number |
| 3 | Search by Date |
| 4 | Generate Daily Report |
| 5 | Display All Transactions |
| 0 | Exit the Application |

## ⚙️ Installation and Execution

### Step 1: Install a C Compiler

Install GCC through MinGW on Windows or your system's package manager on Linux.

### Step 2: Download or Clone the Repository

```bash
git clone <your-repository-link>
```

### Step 3: Open the Project Folder

Navigate to the folder containing the C source file.

### Step 4: Compile the Program

```bash
gcc main.c -o toll_system
```

### Step 5: Run the Program

**Windows:**
```bash
toll_system.exe
```

**Linux / macOS:**
```bash
./toll_system
```

## 💻 Sample Output

```text
===== AUTOMATED VEHICLE TOLL SYSTEM =====
1. Register Vehicle / Collect Toll
2. Search by Vehicle Number
3. Search by Date
4. Generate Daily Report
5. Display All Transactions
0. Exit

Enter your choice: 1

Enter vehicle number (no spaces): UP32AB1234

Vehicle types: car, truck, bus, bike
Enter vehicle type: car

Vehicle registered successfully!

Vehicle Number : UP32AB1234
Vehicle Type   : car
Entry Date     : 2026-11-18
Entry Time     : 14:00
Toll Amount    : Rs. 100.00
```

*Note: The date and time shown above are illustrative. Actual values are generated automatically by the system.*

## 📂 Project Structure

```text
Automated-Vehicle-Toll-System/
│
├── main.c
│   └── Main C source code
│
├── toll_data.txt
│   └── Stores vehicle transaction records
│
└── README.md
    └── Project documentation
```

**Note:** `toll_data.txt` is automatically created when the first transaction is saved. Existing records are loaded when the application starts.

## 🧠 C Programming Concepts Used

1. **Structures:** Used to store vehicle details and transaction information.
2. **Pointers:** Used to access dynamically allocated memory.
3. **Dynamic Memory Allocation:** `malloc()`, `realloc()`, and `free()` manage memory.
4. **File Handling:** `fopen()`, `fprintf()`, `fscanf()`, and `fclose()` store and retrieve records.
5. **Functions:** Different functions perform registration, searching, reporting, and displaying operations.
6. **String Handling:** `strcmp()` compares vehicle types and vehicle numbers.
7. **Date and Time:** `time()`, `localtime()`, and `strftime()` automatically obtain entry date and time.
8. **Conditional Statements:** Used for toll calculation and vehicle validation.
9. **Loops:** Used to search and display transaction records.

## 🎯 Project Objectives

- Automate vehicle registration and toll collection.
- Reduce manual toll calculation.
- Maintain organized transaction records.
- Provide accurate daily collection reports.
- Demonstrate practical applications of C programming concepts.

## ⚠️ Limitations

- This is a console-based application.
- Vehicle registration numbers must not contain spaces.
- The system uses fixed toll rates.
- Transaction records are stored in a local text file.
- The application does not include a graphical user interface, online payment integration, or automatic vehicle number recognition.
- The program does not currently provide transaction editing or deletion.

## 🔮 Future Enhancements

- Add a graphical user interface (GUI).
- Integrate online payment facilities.
- Add automatic number plate recognition.
- Introduce administrator login and authentication.
- Generate downloadable daily and monthly reports.
- Integrate a database such as MySQL.

## 👨‍💻 Conclusion

The Automated Vehicle Toll Management System demonstrates how C programming can be applied to solve real-world problems. It automates vehicle registration, toll calculation, transaction management, and daily reporting.

This project provides practical experience with important programming concepts, including structures, pointers, dynamic memory allocation, file handling, and functions.

---

**Project Name:** Automated Vehicle Toll Management System  
**Language:** C  
**Project Type:** Console-Based Application  
**Domain:** Smart Transportation / Toll Management
