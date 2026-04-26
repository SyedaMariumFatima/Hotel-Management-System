#include <iostream>
using namespace std;

// Hotel management system
// 1.Person, 2.guest, 3. Employee, 4. Manager, 4. Room, 5.Booking,
//   6. Payment, 7.CashPayment, 8.CardPayment, 9.OnlinePayment
//  10. Bill 11. RoomBill, 12.ServiceBill

class AUsers
{
public:
	virtual void displayDetails() const = 0;
	virtual string getRole() const = 0;
	virtual bool login(string Email, string pass) const = 0;
	virtual bool logOut() = 0;
};

class Person : public AUsers
{
protected:
	string name;
	string number;
	string email;
	int id;
	string password;

public:
	Person()
	{
		name = "";
		number = "";
		email = "@gmail.com";
		id = 0;
		password = "";
	}
	Person(string n, string no, string e, int ID, string passKey) : name(n), number(no), email(e), id(ID), password(passKey) {}

	void displayDetails() const override
	{
		cout << "Name: " << name << endl;
		cout << "Number: " << number << endl;
		cout << "Email: " << email << endl;
		cout << "ID: " << id << endl;
	}

	void setContact(string Email, string num)
	{
		number = num;
		email = Email;
	}

	virtual string getRole() const = 0;

	bool login(string Email, string pass) const override
	{
		return (email == Email && pass == password);
	}
	bool logOut() override
	{
		cout << "Log out successfull" << endl;
		return true;
	}
};

class Guest : public Person
{
protected:
	bool isVip;
	int bookingCount;
	string address;
	string nationality;

public:
	Guest() : isVip(false), bookingCount(0), address(""), nationality("") {}
	Guest(string n, string no, string e, int ID, string pass, string add, string nation) : Person(n, no, e, ID, pass), isVip(false), bookingCount(0), address(add), nationality(nation) {}

	string getRole() const override
	{
		return "Guest";
	}

	bool login(string Email, string pass) const override
	{
		return (email == Email && password == pass);
	}
	bool logOut()
	{
		cout << "Logged out" << endl;
		return true;
	}

	void displayDetails() const
	{
		Person::displayDetails();
		cout << "Address: " << address;
		cout << "Total number of bookings: " << bookingCount << endl;
		cout << "Nationality: " << nationality << endl;
		if (isVip)
		{
			cout << "Guest is listed as a VIP" << endl;
		}
		else
		{
			cout << "Guest is not listed as a VIP" << endl;
		}
	}

	void addBooking()
	{
		bookingCount++;
	}

	bool getVIPStatus()
	{
		if (bookingCount > 5)
		{
			cout << "Discount applicable" << endl;
			return true;
		}
		else
		{
			return false;
		}
	}

	void cancelBooking()
	{
		if (bookingCount > 0)
		{
			bookingCount--;
		}
		else
		{
			cout << "You have no prior bookings to cancel" << endl;
		}
	}

	int getBookingCount()
	{
		return bookingCount;
	}
};

class Employee : public Person
{
protected:
	string department;
	double salary;
	string shift;	 // time
	int hoursWorked; // in a week
	double bonus;

public:
	Employee() : department(""), salary(0), shift(""), hoursWorked(0), bonus(0) {}

	Employee(string n, string no, string e, int ID, string p, string d, double s, string sh) : Person(n, no, e, ID, p), department(d), salary(s), shift(sh), hoursWorked(0), bonus(2) {}

	string getRole() const override
	{
		return "Employee";
	}

	void displayDetails() const
	{
		Person::displayDetails();
		cout << "Department: " << department << endl;
		cout << "Salary: " << salary << endl;
		cout << "Shift: " << shift << endl;
		cout << "Hours worked: " << hoursWorked << endl;
		cout << "Bonus: " << bonus << endl;
	}

	double calculatePay()
	{
		return (bonus * hoursWorked) + salary;
	}

	void updatesalary(double NewSalary)
	{
		salary = NewSalary;
	}
};

class Room
{
private:
	int roomNumber;
	string type; // single, double, suite
	double pricePerNight;
	bool isAvailable;

public:
	Room() {}

	Room(int num, string t, double price) : roomNumber(num), type(t), pricePerNight(price), isAvailable(true) {}

	int getRoomNumber()
	{
		return roomNumber;
	}
	double getPrice() const
	{
		return pricePerNight;
	}
	bool getAvailability()
	{
		return isAvailable;
	}
	string getType()
	{
		return type;
	}

	bool bookRoom()
	{
		if (isAvailable)
		{
			cout << "Room can be booked" << endl;
			isAvailable = false;
		}
		else
		{
			cout << "Room is already booked" << endl;
		}
	}

	void displayroom() const
	{
		cout << "---Room Details---" << endl;
		cout << "Room number: " << roomNumber << endl;
		cout << "Type: " << type << endl;
		cout << "Price per night: " << pricePerNight << endl;
		if (isAvailable)
		{
			cout << "The room is available" << endl;
		}
		else
		{
			cout << "Room is already booked" << endl;
		}
	}
};

class Manager : public Employee
{
private:
	int accessLevel;

public:
	Manager() : Employee(), accessLevel(0) {}

	Manager(string n, string no, string e, int ID, string p, string d, double s, string sh, int al) : Employee(n, no, e, ID, p, d, s, sh), accessLevel(al) {}

	string getRole() const override
	{
		return "Manager";
	}

	void displayDetails() const
	{
		Employee::displayDetails();
		cout << "Access level: " << accessLevel << endl;
	}

	void setAccessLevel(int acc)
	{
		accessLevel = acc;
	}
};

class Bill
{ // abstract class
protected:
	double baseAmount;
	double taxRate;
	double discount;
	string status;

public:
	Bill(double a)
	{
		baseAmount = a;
		taxRate = 0.1;
		discount = 0;
		status = "unpaid";
	}

	virtual double calculateTotal() const = 0;
	virtual void displayBill() const = 0;

	void applyDiscount(double d)
	{
		discount = d;
	}

	void statusPaid()
	{
		status = "paid";
	}
	// adding two bills together
	double operator+(const Bill &other) const
	{
		return calculateTotal() + other.calculateTotal();
	}
	virtual ~Bill() {} // virtual destructor
};
class RoomBill : public Bill
{
private:
	int days;
	double costPerNight;

public:
	RoomBill(int d, double price) : Bill(0), days(d), costPerNight(price) {}

	double calculateTotal() const override
	{
		double total = days * costPerNight;
		total += total * taxRate;
		total -= discount;
		return total;
	}

	void displayBill() const override
	{
		cout << "Room charges: " << days * costPerNight << endl;
		cout << "Total(inclusive of tax/discounts): " << calculateTotal() << endl;
	}
};
class ServiceBill : public Bill
{
private:
	double serviceCost;

public:
	ServiceBill(double cost) : Bill(cost), serviceCost(cost) {}

	double calculateTotal() const override
	{
		double total = serviceCost;
		total += total * taxRate;
		total -= discount;
		return total;
	}

	void displayBill() const override
	{
		cout << "Service Charges: " << serviceCost << endl;
		cout << "Total (with tax/discount): " << calculateTotal() << endl;
	}
};
class Booking;
class Payment
{
protected:
	int paymentID;
	double amount;
	string status;

public:
	Payment(int id, double amt) : paymentID(id), amount(amt), status("Pending") {}

	friend void linkPayment(Booking &b, Payment &p);

	bool operator>(const Payment &other) const
	{
		return amount > other.amount;
	}
	bool operator==(const Payment &other) const
	{
		return paymentID == other.paymentID;
	}

	virtual void processPayment() = 0; // polymorphism

	virtual void displayPayment() const = 0;
};

class CashPayment : public Payment
{
public:
	CashPayment(int id, double a) : Payment(id, a) {} // the status isnt initiaalized here, cus it is already initialized in the payment constructor, so here the payment constructor runs first, initializing the status as "Pending"

	void processPayment() override
	{
		status = "Completed (Cash).";
		cout << "Processing the cash payment of amount: " << amount << endl;
	}
	void displayPayment() const override
	{
		cout << "Payment id : " << paymentID << endl;
		cout << "Amount : " << amount << endl;
		cout << "Status : " << status << endl;
	}
};
class OnlinePayment : public Payment
{
public:
	OnlinePayment(int id, int a) : Payment(id, a) {}

	void processPayment() override
	{
		status = "Completed (online).";
		cout << "Processing the online payment of amount: " << amount << endl;
	}
	void displayPayment() const override
	{
		cout << "Payment id : " << paymentID << endl;
		cout << "Amount : " << amount << endl;
		cout << "Status : " << status << endl;
	}
};
class CardPayment : public Payment
{
public:
	CardPayment(int id, int a) : Payment(id, a) {}

	void processPayment() override
	{
		status = "Completed (card).";
		cout << "Processing the card payment of amount: " << amount << endl;
	}
	void displayPayment() const override
	{
		cout << "Payment id : " << paymentID << endl;
		cout << "Amount : " << amount << endl;
		cout << "Status : " << status << endl;
	}
};
class Booking
{
private:
	int bookingID;
	Guest *guest;
	Room room;
	int days;
	RoomBill *bill;
	ServiceBill *serviceBills[10];
	int serviceCount;
	Payment *payment;

public:
	Booking() : bookingID(0), guest(NULL), days(0), bill(NULL), serviceCount(0), payment(NULL)
	{
		for (int i = 0; i < 10; i++)
			serviceBills[i] = NULL;
	}

	Booking(int id, Guest *g, Room r, int d) : bookingID(id), guest(g), room(r), days(d), serviceCount(0), payment(NULL)
	{
		bill = new RoomBill(d, r.getPrice());

		if (guest->getVIPStatus())
		{
			bill->applyDiscount(d * r.getPrice() * 0.2);
		}
		guest->addBooking();
		for (int i = 0; i < 10; i++)
		{
			serviceBills[i] = NULL;
		}
	}
	friend void linkPayment(Booking &b, Payment &p);
	void addService(double serviceCost)
	{
		if (serviceCount < 10)
		{
			serviceBills[serviceCount] = new ServiceBill(serviceCost);
			serviceCount++;
		}
		else
		{
			cout << "Maximum services reached" << endl;
		}
	}

	double calculateTotal() const
	{
		double total = bill->calculateTotal();
		for (int i = 0; i < serviceCount; i++)
		{
			total += serviceBills[i]->calculateTotal();
		}
		return total;
	}

	void displayBooking() const
	{
		cout << "Booking ID: " << bookingID << endl;
		cout << "Guest details: " << endl;
		guest->displayDetails();

		cout << "Room Details: " << endl;
		room.displayroom();

		cout << "Room bill" << endl;
		bill->displayBill();

		if (serviceCount > 0)
		{
			cout << "Service bills: " << endl;
			for (int i = 0; i < serviceCount; i++)
			{
				serviceBills[i]->displayBill();
			}
		}
		cout << "Grand total: " << calculateTotal() << endl;
	}
	// comparing bookings byy total costs
	bool operator>(const Booking &other) const
	{
		return calculateTotal() > other.calculateTotal();
	}
	bool operator==(const Booking &other) const
	{
		return bookingID == other.bookingID;
	}

	Guest *getGuest()
	{
		return guest;
	}
	Room getRoom() const
	{
		return room;
	}

	~Booking()
	{
		delete bill;
		for (int i = 0; i < serviceCount; i++)
		{
			delete serviceBills[i];
		}
	}
};

void linkPayment(Booking &b, Payment &p)
{
	b.payment = &p;
	p.status = "linked";
	cout << "Payment is successfully linked to Booking." << b.bookingID << endl;
}
class Payable
{
public:
	virtual double calculateTotal() const = 0;
	virtual void displayPaymentDetails() const = 0;
	virtual ~Payable() {}
};

// Authentication system
class Authentication
{
public:
	static bool verifyLogin(AUsers *user, string email, string pass)
	{
		return user->login(email, pass);
	}
	static bool logout(AUsers *user)
	{
		return user->logOut();
	}
};

// Feature class for hotel/cafe services
class Feature
{
private:
	string description;
	double cost;

public:
	Feature(string desc = "", double c = 0) : description(desc), cost(c) {}
	void displayFeature() const
	{
		cout << "Feature: " << description << " | Cost: " << cost << endl;
	}
	double getCost() const { return cost; }
};

// Status class for tracking booking/payment states
class Status
{
private:
	string currentStatus;

public:
	Status(string s = "Pending") : currentStatus(s) {}
	void updateStatus(string s) { currentStatus = s; }
	string getStatus() const { return currentStatus; }
	void displayStatus() const { cout << "Status: " << currentStatus << endl; }
};

// Review class for guest feedback
class Review
{
private:
	string reviewerName;
	string comments;
	int rating; // 1–5
public:
	Review(string name = "", string c = "", int r = 0) : reviewerName(name), comments(c), rating(r) {}
	void displayReview() const
	{
		cout << reviewerName << " rated " << rating << "/5" << endl;
		cout << "Comments: " << comments << endl;
	}
};

// Cafe class for menu items
class Cafe
{
private:
	string itemName;
	double price;

public:
	Cafe(string item = "", double p = 0) : itemName(item), price(p) {}
	void displayItem() const
	{
		cout << "Item: " << itemName << " | Price: " << price << endl;
	}
	double getPrice() const { return price; }
};
class Hotel
{
private:
	string hotelName;
	Room rooms[20];
	int roomCount;
	Booking bookings[20];
	int bookingCount;
	Employee employees[20];
	int employeeCount;
	Guest guests[20];
	int guestCount;
	Cafe menu[20];
	int menuCount;
	Review reviews[20];
	int reviewCount;
	Feature features[20];
	int featureCount;

public:
	Hotel(string name) : hotelName(name), roomCount(0), bookingCount(0), employeeCount(0), guestCount(0), menuCount(0), reviewCount(0), featureCount(0) {}

	// Add methods
	void addRoom(Room r)
	{
		if (roomCount < 20)
			rooms[roomCount++] = r;
	}
	void addBooking(Booking b)
	{
		if (bookingCount < 20)
			bookings[bookingCount++] = b;
	}
	void addEmployee(Employee e)
	{
		if (employeeCount < 20)
			employees[employeeCount++] = e;
	}
	void addGuest(Guest g)
	{
		if (guestCount < 20)
			guests[guestCount++] = g;
	}
	void addMenuItem(Cafe c)
	{
		if (menuCount < 20)
			menu[menuCount++] = c;
	}
	void addReview(Review r)
	{
		if (reviewCount < 20)
			reviews[reviewCount++] = r;
	}
	void addFeature(Feature f)
	{
		if (featureCount < 20)
			features[featureCount++] = f;
	}

	// --- NEW helper methods ---
	int getGuestCount() const { return guestCount; }
	Guest &getGuestAt(int index) { return guests[index]; }

	int getEmployeeCount() const { return employeeCount; }
	Employee &getEmployeeAt(int index) { return employees[index]; }

	int getRoomCount() const { return roomCount; }
	Room &getRoomAt(int index) { return rooms[index]; }

	int getBookingCount() const { return bookingCount; }
	Booking &getBookingAt(int index) { return bookings[index]; }

	int getMenuCount() const { return menuCount; }
	Cafe &getMenuAt(int index) { return menu[index]; }

	int getReviewCount() const { return reviewCount; }
	Review &getReviewAt(int index) { return reviews[index]; }

	int getFeatureCount() const { return featureCount; }
	Feature &getFeatureAt(int index) { return features[index]; }

	void displayHotelDetails() const
	{
		cout << "Hotel: " << hotelName << endl;
		cout << "---Rooms---" << endl;
		for (int i = 0; i < roomCount; i++)
			rooms[i].displayroom();
		cout << "---Menu---" << endl;
		for (int i = 0; i < menuCount; i++)
			menu[i].displayItem();
		cout << "---Features---" << endl;
		for (int i = 0; i < featureCount; i++)
			features[i].displayFeature();
		cout << "---Reviews---" << endl;
		for (int i = 0; i < reviewCount; i++)
			reviews[i].displayReview();
	}
};

// --- Menu functions ---
void guestMenu(Guest &g)
{
	cout << "\n--- Guest Menu ---\n";
	cout << "1. View your details\n";
	cout << "2. View booking count\n";
	cout << "3. Logout\n";
	int choice;
	cin >> choice;
	if (choice == 1)
		g.displayDetails();
	else if (choice == 2)
		cout << "Bookings: " << g.getBookingCount() << endl;
	else
		cout << "Logging out...\n";
}

void employeeMenu(Employee &e)
{
	cout << "\n--- Employee Menu ---\n";
	cout << "1. View your details\n";
	cout << "2. Calculate pay\n";
	cout << "3. Logout\n";
	int choice;
	cin >> choice;
	if (choice == 1)
		e.displayDetails();
	else if (choice == 2)
		cout << "Pay: " << e.calculatePay() << endl;
	else
		cout << "Logging out...\n";
}

void managerMenu(Manager &m, Hotel &h)
{
	cout << "\n--- Manager Menu ---\n";
	cout << "1. View your details\n";
	cout << "2. Add new Employee\n";
	cout << "3. Add new Guest\n";
	cout << "4. View Hotel details\n";
	cout << "5. Logout\n";
	int choice;
	cin >> choice;
	if (choice == 1)
		m.displayDetails();
	else if (choice == 2)
	{
		string n, no, e, p, d, sh;
		int id;
		double s;
		cout << "Enter Employee details (name, number, email, id, pass, dept, salary, shift):\n";
		cin >> n >> no >> e >> id >> p >> d >> s >> sh;
		Employee newEmp(n, no, e, id, p, d, s, sh);
		h.addEmployee(newEmp);
		cout << "Employee added!\n";
	}
	else if (choice == 3)
	{
		string n, no, e, p, add, nation;
		int id;
		cout << "Enter Guest details (name, number, email, id, pass, address, nationality):\n";
		cin >> n >> no >> e >> id >> p >> add >> nation;
		Guest newGuest(n, no, e, id, p, add, nation);
		h.addGuest(newGuest);
		cout << "Guest added!\n";
	}
	else if (choice == 4)
		h.displayHotelDetails();
	else
		cout << "Logging out...\n";
}

// --- Main login system ---
int main()
{
	Hotel h("Grand Palace");

	// Prepopulate with one manager
	Manager manager("Marium", "55555", "marium@gmail.com", 3, "manPass", "Admin", 60000, "Evening", 5);
	h.addEmployee(manager); // manager stored as employee too

	// Prepopulate with one guest
	Guest g1("Roshni", "12345", "ros@gmail.com", 1, "guestPass", "Karachi", "Pakistani");
	h.addGuest(g1);

	// Prepopulate with one employee
	Employee e1("Amna", "67890", "amna@gmail.com", 2, "empPass", "Reception", 30000, "Morning");
	h.addEmployee(e1);

	cout << "Login as (g=Guest, e=Employee, m=Manager): ";
	char role;
	cin >> role;

	string email, pass;

	bool loggedIn = false;
	while (!loggedIn)
	{
		cout << "Enter email: ";
		cin >> email;
		cout << "Enter password: ";
		cin >> pass;

		if (role == 'g')
		{
			bool found = false;
			for (int i = 0; i < h.getGuestCount(); i++)
			{
				Guest &guest = h.getGuestAt(i);
				if (guest.login(email, pass))
				{
					cout << "Guest login successful!\n";
					guestMenu(guest);
					loggedIn = true;
					found = true;
					break;
				}
			}
			if (!found)
			{
				cout << "Invalid Guest credentials. Please try again.\n";
			}
		}
		else if (role == 'e')
		{
			bool found = false;
			for (int i = 0; i < h.getEmployeeCount(); i++)
			{
				Employee &emp = h.getEmployeeAt(i);
				if (emp.getRole() == "Employee" && emp.login(email, pass))
				{
					cout << "Employee login successful!\n";
					employeeMenu(emp);
					loggedIn = true;
					found = true;
					break;
				}
			}
			if (!found)
			{
				cout << "Invalid Employee credentials. Please try again.\n";
			}
		}
		else if (role == 'm')
		{
			if (manager.login(email, pass))
			{
				cout << "Manager login successful!\n";
				managerMenu(manager, h);
				loggedIn = true;
			}
			else
			{
				cout << "Invalid Manager credentials. Please try again.\n";
			}
		}
		else
		{
			cout << "Invalid role selected! Enter role again (g/e/m): ";
			cin >> role;
		}
	}
	return 0;
}
