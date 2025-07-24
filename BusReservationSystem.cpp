#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bus {
    string busNumber;
    string driverName;
    string source;
    string destination;
    string departureTime;
    string arrivalTime;
    string seats[8][4];

public:
    Bus(string bNum, string dName, string src, string dest, string dep, string arr) {
        busNumber = bNum;
        driverName = dName;
        source = src;
        destination = dest;
        departureTime = dep;
        arrivalTime = arr;

        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 4; ++j){
                seats[i][j] = "Empty";
    } 
}
}

    string getBusNumber() {
        return busNumber;
    }

    void showDetails() {
        cout << "\nBus Number: " << busNumber
             << "\nDriver: " << driverName
             << "\nFrom: " << source
             << "\nTo: " << destination
             << "\nDeparture: " << departureTime
             << "\nArrival: " << arrivalTime << endl;
    }

    void showSeats() {
        cout << "\nSeat layout for Bus " << busNumber << ":\n";
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout.width(10);
                cout << seats[i][j];
            }
            cout << endl;
        }
    }

    void bookSeat() {
        int row, col;
        cout << "Enter row (0-7): ";
        cin >> row;
        cout << "Enter column (0-3): ";
        cin >> col;

        if (row < 0 || row > 7 || col < 0 || col > 3) {
            cout << "Invalid seat number!" << endl;
            return;
        }

        if (seats[row][col] == "Empty") {
            string name;
            cout << "Enter passenger name: ";
            cin.ignore();
            getline(cin, name);
            seats[row][col] = name;
            cout << "Seat booked successfully!\n";
        } else {
            cout << "Seat already booked by " << seats[row][col] << endl;
        }
    }
};

vector<Bus> buses;
string UserAccount[10];
string AdminAccount[10];
string username;
string password;

void addBus() {
    string num, name, src, dest, dep, arr;
    cout << "Enter Bus Number: ";
    cin >> num;
    cin.ignore();
    cout << "Enter Driver Name: ";
    getline(cin, name);
    cout << "Enter Source: ";
    getline(cin, src);
    cout << "Enter Destination: ";
    getline(cin, dest);
    cout << "Enter Departure Time: ";
    getline(cin, dep);
    cout << "Enter Arrival Time: ";
    getline(cin, arr);

    Bus newBus(num, name, src, dest, dep, arr);
    buses.push_back(newBus);
    cout << "Bus added successfully!\n";
}

void showAllBuses() {
    if (buses.empty()) {
        cout << "No buses available.\n";
        return;
    }
    for (auto &b : buses) {
        b.showDetails();
    }
}

void bookSeatInBus() {
    string num;
    cout << "Enter Bus Number to book: ";
    cin >> num;
    for (auto &b : buses) {
        if (b.getBusNumber() == num) {
            b.showSeats();
            b.bookSeat();
            return;
        }
    }
    cout << "Bus not found.\n";
}

void showSeatsOfBus() {
    string num;
    cout << "Enter Bus Number: ";
    cin >> num;
    for (auto &b : buses) {
        if (b.getBusNumber() == num) {
            b.showSeats();
            return;
        }
    }
    cout << "Bus not found.\n";
}

void AdminSignIn() {
    cout << "ENTER NAME: "; getline(cin, AdminAccount[0]);
    cout << "ENTER AGE: "; getline(cin, AdminAccount[1]);
    cout << "ENTER PHONENUMBER: "; getline(cin, AdminAccount[2]);
    cout << "ENTER AADHAR NUMBER: "; getline(cin, AdminAccount[3]);
    cout << "ENTER VALID USER NAME: "; getline(cin, AdminAccount[4]);
password:
    cout << "ENTER PASSWORD: "; getline(cin, AdminAccount[5]);
    cout << "ENTER PASSWORD AGAIN: "; getline(cin, AdminAccount[6]);
    if (AdminAccount[5] != AdminAccount[6]) {
        cout << "INVALID PASSWORD ENTER AGAIN\n";
        goto password;
    }
}

void UserSignIn() {
    cout << "ENTER NAME: "; getline(cin, UserAccount[0]);
    cout << "ENTER AGE: "; getline(cin, UserAccount[1]);
    cout << "ENTER PHONENUMBER: "; getline(cin, UserAccount[2]);
    cout << "ENTER AADHAR NUMBER: "; getline(cin, UserAccount[3]);
    cout << "ENTER VALID USER NAME: "; getline(cin, UserAccount[4]);
password:
    cout << "ENTER PASSWORD: "; getline(cin, UserAccount[5]);
    cout << "ENTER PASSWORD AGAIN: "; getline(cin, UserAccount[6]);
    if (UserAccount[5] != UserAccount[6]) {
        cout << "INVALID PASSWORD ENTER AGAIN\n";
        goto password;
    }
}

void AdminLogin() {
Login:
    cout << "ENTER ADMIN NAME: "; getline(cin, username);
    cout << "ENTER PASSWORD: "; getline(cin, password);
    if (AdminAccount[4].empty() && AdminAccount[5].empty()) {
        cout << "Account does not exist \n";
        AdminSignIn();
        goto Login;
    } else if (AdminAccount[4] != username || AdminAccount[5] != password) {
        cout << "Invalid Credentials \n";
        goto Login;
    } else {
        cout << "Welcome " << username << " you can proceed further\n";
    }
}

void UserLogin() {
Login:
    cout << "ENTER USER NAME: "; getline(cin, username);
    cout << "ENTER PASSWORD: "; getline(cin, password);
    if (UserAccount[4].empty() && UserAccount[5].empty()) {
        cout << "Account does not exist\n";
        UserSignIn();
        goto Login;
    } else if (UserAccount[4] != username || UserAccount[5] != password) {
        cout << "Invalid Credentials\n";
        goto Login;
    } else {
        cout << "Welcome " << username << " you can proceed further\n";
    }
}

int main() {
    int select;
    int choice;
login:
    cout << "*************USER LOGIN****************\n";
    cout << "1 ADMIN LOGIN\n";
    cout << "2 USER LOGIN\n";
    cout << "Enter a number \n";
    cin >> select;
    cin.ignore();
    switch (select) {
        case 1: AdminLogin(); break;
        case 2: UserLogin(); break;
        default:
            cout << "Invalid Number\n";
            goto login;
    }

    do {
        cout << "\n===== BUS RESERVATION SYSTEM =====\n";
        if (select == 1) {
            cout << "1. Add New Bus\n";
            cout << "2. View All Buses\n";
            cout << "3. Show Seats in a Bus\n";
            cout << "4. Exit\n";
            cout << "Enter your choice\n";
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: addBus(); break;
                case 2: showAllBuses(); break;
                case 3: showSeatsOfBus(); break;
                case 4: cout << "Thank you come again!\n"; goto login;
                default: cout << "Invalid choice!\n"; goto login;
            }
        } else {
            cout << "1. View All Buses\n";
            cout << "2. Book Seat\n";
            cout << "3. Show Seats in a Bus\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: showAllBuses(); goto login;
                case 2: bookSeatInBus(); goto login;
                case 3: showSeatsOfBus(); goto login;
                case 4: cout << "Thank you come again!\n"; goto login;
                default: cout << "Invalid choice!\n"; goto login;
            }
        }
    } while (choice != 5);

    return 0;
}

    
    


