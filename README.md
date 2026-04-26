# Hotel-Management-System

Roshni Vikram, Syeda Marium Fatima , Amna Saad
25K-0907, 25K-0970, 25K-0615

This project is a console-based Hotel Management System developed using Object-Oriented Programming (OOP) principles in C++. It simulates real-world hotel operations by managing guests, employees, managers, rooms, bookings, payments, bills, and additional hotel services such as café orders and reviews.

The system is designed using advanced OOP concepts including:

Inheritance (Person → Guest/Employee/Manager)
Polymorphism (virtual functions, overriding)
Abstraction (AUsers, Bill, Payment)
Encapsulation (private/protected data members)
Operator Overloading (Booking & Payment comparison, bill addition)
Friend Functions (linkPayment)

##Key Features:
Role-based login system (Guest / Employee / Manager)
Room booking and availability tracking
Automated billing system (RoomBill + ServiceBill)
VIP discount system for frequent guests
Café ordering system linked to bookings
Payment system (Cash, Card, Online)
Hotel reviews system
Employee salary calculation system
Manager control panel (add employees, guests, view hotel data)


## Use Cases:
1. Guest Room Booking
A guest logs into the system, views available rooms, selects a room, and enters the number of stay days. The system then creates a booking, marks the room as unavailable, and generates a room bill automatically.

2. Food Ordering (Café Service)
After booking a room, a guest can order food items from the hotel café menu. Each ordered item is added as a service bill and included in the final invoice during checkout.

3. Payment Processing
Once a booking is completed, the system supports cash payment. The payment is linked to the booking and its status is updated accordingly.

4.  Employee Salary Management
Employees can log in to view their details and calculate their salary. The system calculates total pay using base salary, bonus, and hours worked in a week.

5. Manager Administration Control
The manager can log in to manage the entire system. They can add new employees, register new guests, and view complete hotel data including rooms, bookings, reviews, and café items.

6. Guest Review System
After using hotel services, guests can submit ratings and written reviews. These reviews are stored in the system and can be viewed by the hotel for feedback and improvement.


## How to use the system:

### 1. Role Selection (Login Screen)
You will be prompted:
Login as (g=Guest, e=Employee, m=Manager):
Enter one of the following:
g → Guest access
e → Employee access
m → Manager access
After selecting a role, you will be asked to enter:
Email
Password
If credentials are correct, you will be logged into that role’s system.

### 2. Guest Usage (Customer Side)
Once logged in as a Guest, the system first shows available rooms and allows booking.
After booking, the guest can access a menu system with options such as:
Guest Menu Options:
View personal details (name, contact, nationality, etc.)
View total number of bookings made
Order food from the hotel café menu
View full booking bill (room charges + services + tax)
Add a hotel review (rating + comments)
View all previous hotel reviews
Logout from system
Booking System:
Guests select a room from available rooms
Enter number of stay days
System automatically generates a booking
A bill is created based on room price × days
VIP discount is automatically applied if applicable (after multiple bookings)

### 3. Employee Usage (Staff Side)
After logging in as an Employee, the system allows staff operations:
Employee Menu Options:
View personal details (department, shift, salary, etc.)
Calculate total salary (base salary + bonus × hours worked)
Add new items to hotel café menu
Logout
Employees help manage hotel services and expand café offerings.

### 4. Manager Usage (Admin Control)
After logging in as a Manager, full administrative access is granted.
Manager Menu Options:
View manager profile and access level
Add new employees to the system
Add new guests to the system
View complete hotel information:
Rooms
Bookings
Employees
Guests
Café menu
Reviews
Features
Logout
Managers act as system administrators with full control over hotel operations.

### 5. Booking, Billing & Payment Flow
Every booking automatically generates a RoomBill
Extra services like food generate ServiceBills
Final bill is calculated as:
Total = Room Charges + Service Charges + Tax - Discount
Payment types supported:
Cash Payment
Payments can be linked directly to a booking using system functions.

### 6. Hotel Features System
The hotel also includes additional features:
Swimming pool
Gym access
Café ordering system
Customer review system
These enhance the simulation of a real hotel environment.


## Assumptions & Limitations:
### Assumptions:
Maximum limits are fixed:
20 rooms
20 bookings
20 employees
20 guests
20 menu items
10 service items per booking
Login credentials are pre-stored in program
Each guest has one active booking session at a time

### Limitations:
No real security (passwords stored in plain text)
Fixed array sizes (no dynamic memory / STL vectors)
No concurrency support (single-user simulation only)
UI is console-based only (no GUI)
No card and online payment 

## Instructions on How to Compile the Project:

This project is written in C++ and can be compiled using any standard C++ compiler such as g++, CodeBlocks, Dev-C++, or Visual Studio.
First, save the source code file with a .cpp extension, for example:
hotel_management.cpp
Next, open Command Prompt (Windows) or Terminal (Linux/Mac) and navigate to the folder where your file is saved.
To compile the program using g++, enter the following command:
g++ hotel_management.cpp -o hotel_system
If the code has no errors, this command will generate an executable file named:
hotel_system.exe (on Windows)
hotel_system (on Linux/Mac)
Make sure that g++ is properly installed and added to your system path before compiling.

## Instructions on How to Run the Project:

After compiling the program successfully, you can run the executable file.
On Windows, type:
hotel_system.exe
On Linux or Mac, type:
./hotel_system
Once executed, the program will start in the console and display the hotel management system interface.
Follow the on-screen instructions to log in as a Guest, Employee, or Manager, and interact with the system accordingly.
