#include "HotelSystem.h"

void guestMenu(Guest &g, Hotel &h, Booking &b)
{
    int choice = 0;
    while (choice != 7)
    {
        cout << "\n--- Guest Menu ---\n";
        cout << "1. View your details\n";
        cout << "2. View booking count\n";
        cout << "3. Order food\n";
        cout << "4. View bill\n";
        cout << "5. Hotel Reviews\n";
        cout << "6. Pay bill\n";
        cout << "7. Logout\n";
        cin >> choice;

        if (choice == 1)
        {
            g.displayDetails();
        }
        else if (choice == 2)
        {
            cout << "Bookings: " << g.getBookingCount() << endl;
        }
        else if (choice == 3)
        {
            cout << "--- Cafe Menu ---" << endl;
            if (h.getMenuCount() == 0)
            {
                cout << "No items available." << endl;
            }
            else
            {
                for (int i = 0; i < h.getMenuCount(); i++)
                {
                    cout << i + 1 << ". ";
                    h.getMenuAt(i).displayItem();
                }
                cout << "Select item number: ";
                int itemChoice;
                cin >> itemChoice;

                if (itemChoice >= 1 && itemChoice <= h.getMenuCount())
                {
                    b.orderFood(h.getMenuAt(itemChoice - 1).getPrice());
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }
            }
        }
        else if (choice == 4)
        {
            b.displayBooking();
        }
        else if (choice == 5)
        {
            int reviewChoice;
            cout << "\n--- Review Menu ---\n";
            cout << "1. Add Review\n";
            cout << "2. View Reviews\n";
            cin >> reviewChoice;

            if (reviewChoice == 1)
            {
                string comment;
                int rating;

                cout << "Enter rating (1-5): ";
                cin >> rating;

                cin.ignore();

                cout << "Enter your comments: ";
                getline(cin, comment);

                Review r(g.getName(), comment, rating);
                h.addReview(r);

                cout << "Review added successfully!\n";
            }
            else if (reviewChoice == 2)
            {
                if (h.getReviewCount() == 0)
                {
                    cout << "No reviews yet.\n";
                }
                else
                {
                    cout << "\n--- Hotel Reviews ---\n";
                    for (int i = 0; i < h.getReviewCount(); i++)
                    {
                        h.getReviewAt(i).displayReview();
                        cout << "-------------------\n";
                    }
                }
            }
            else
            {
                cout << "Invalid choice.\n";
            }
        }
        else if (choice == 6)
        {
            double total = b.calculateTotal();
            cout << "Total amount to pay: " << total << endl;
            CashPayment *p = new CashPayment(1, total);
            h.addPayment(p);
            linkPayment(b, *p);
            p->processPayment();
            cout << "Payment processed successfully!" << endl;
        }
        else if (choice == 7)
        {
            cout << "Logging out...\n";
        }
        else
        {
            cout << "Invalid choice, try again.\n";
        }
    }
}

void employeeMenu(Employee &e, Hotel &h)
{
    int choice = 0;
    while (choice != 4)
    {
        cout << "\n--- Employee Menu ---\n";
        cout << "1. View your details\n";
        cout << "2. Calculate pay\n";
        cout << "3. Add cafe item\n";
        cout << "4. Logout\n";
        cin >> choice;
        if (choice == 1)
            e.displayDetails();
        else if (choice == 2)
            cout << "Pay: " << e.calculatePay() << endl;
        else if (choice == 3)
        {
            string itemName;
            double price;
            cout << "Enter item name: ";
            cin >> itemName;
            cout << "Enter price: ";
            cin >> price;
            h.addMenuItem(Cafe(itemName, price));
            cout << "Item added!" << endl;
        }
        else if (choice == 4)
            cout << "Logging out...\n";
        else
            cout << "Invalid choice.\n";
    }
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

int main()
{
    Hotel h("Grand Palace");

    // Prepopulate rooms
    h.addRoom(Room(101, "Single", 5000));
    h.addRoom(Room(102, "Double", 8000));
    h.addRoom(Room(103, "Suite", 15000));

    // Prepopulate cafe menu
    h.addMenuItem(Cafe("Burger", 500));
    h.addMenuItem(Cafe("Pizza", 800));
    h.addMenuItem(Cafe("Coffee", 200));

    // Prepopulate features
    h.addFeature(Feature("Swimming Pool", 1000));
    h.addFeature(Feature("Gym Access", 500));

    // Prepopulate manager
    Manager manager("Marium", "55555", "marium@gmail.com", 3, "manPass", "Admin", 60000, "Evening", 5);
    h.addEmployee(manager);

    // Prepopulate guest
    h.addGuest(Guest("Roshni", "12345", "ros@gmail.com", 1, "guestPass", "Karachi", "Pakistani"));

    // Prepopulate employee
    h.addEmployee(Employee("Amna", "67890", "amna@gmail.com", 2, "empPass", "Reception", 30000, "Morning"));

    cout << "=== Welcome to Grand Palace ===" << endl;
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
                    cout << "Guest login successful!" << endl;

                    // Show available rooms
                    cout << "\n--- Available Rooms ---" << endl;
                    int availableCount = 0;
                    for (int j = 0; j < h.getRoomCount(); j++)
                    {
                        if (h.getRoomAt(j).getAvailability())
                        {
                            cout << j + 1 << ". ";
                            h.getRoomAt(j).displayroom();
                            availableCount++;
                        }
                    }

                    if (availableCount == 0)
                    {
                        cout << "No rooms available at the moment." << endl;
                        loggedIn = true;
                        found = true;
                        break;
                    }

                    cout << "Select room (1-" << h.getRoomCount() << "): ";
                    int roomChoice;
                    cin >> roomChoice;

                    cout << "Enter number of days: ";
                    int days;
                    cin >> days;

                    if (roomChoice >= 1 && roomChoice <= h.getRoomCount())
                    {
                        Room &selectedRoom = h.getRoomAt(roomChoice - 1);
                        selectedRoom.bookRoom();

                        Booking guestBooking(h.getBookingCount() + 1, &guest, selectedRoom, days);
                        h.addBooking(guestBooking);
                        Booking &b = h.getBookingAt(h.getBookingCount() - 1);
                        guestMenu(guest, h, b);
                    }
                    else
                    {
                        cout << "Invalid room choice." << endl;
                    }

                    loggedIn = true;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Invalid Guest credentials. Please try again." << endl;
        }
        else if (role == 'e')
        {
            bool found = false;
            for (int i = 0; i < h.getEmployeeCount(); i++)
            {
                Employee &emp = h.getEmployeeAt(i);
                if (emp.getRole() == "Employee" && emp.login(email, pass))
                {
                    cout << "Employee login successful!" << endl;
                    employeeMenu(emp, h);
                    loggedIn = true;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Invalid Employee credentials. Please try again." << endl;
        }
        else if (role == 'm')
        {
            if (manager.login(email, pass))
            {
                cout << "Manager login successful!" << endl;
                managerMenu(manager, h);
                loggedIn = true;
            }
            else
            {
                cout << "Invalid Manager credentials. Please try again." << endl;
            }
        }
        else
        {
            cout << "Invalid role! Enter again (g/e/m): ";
            cin >> role;
        }
    }

    return 0;
}
