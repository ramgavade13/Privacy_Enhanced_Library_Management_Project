#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <algorithm>
using namespace std;

class UserData {
private:
    string username;
    string password; // stored encrypted
    vector<int> issuedBookIds; // store book IDs user has issued

public:
    UserData(string u, string p) {
        username = u;
        password = p;
    }

    string getUsername() const { return username; }
    string getPassword() const { return password; }

    void addIssuedBook(int id) { issuedBookIds.push_back(id); }
    void removeIssuedBook(int id) {
        issuedBookIds.erase(remove(issuedBookIds.begin(), issuedBookIds.end(), id), issuedBookIds.end());
    }
    vector<int> getIssuedBooks() const { return issuedBookIds; }

    void showIssuedBooks() const {
        if (issuedBookIds.empty()) {
            cout << "\nYou haven’t issued any books yet.\n";
            return;
        }
        cout << "\nYour Issued Books (IDs): ";
        for (int id : issuedBookIds) cout << id << " ";
        cout << endl;
    }
};

class Encryptor {
public:
    string encrypt(string input) {
        for (char &c : input) c = c + 3;  // Caesar cipher (+3)
        return input;
    }
    string decrypt(string input) {
        for (char &c : input) c = c - 3;
        return input;
    }
};

class Book {
public:
    int id;
    string title, author;
    bool isIssued;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        isIssued = false;
    }
};

class Library {
private:
    vector<Book> books;

    string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

public:
    void addBook(Book b) { books.push_back(b); }

    void showBooks() {
        cout << "\n--- Available Books ---\n";
        int availableCount = 0;
        for (auto &b : books) {
            cout << "ID: " << b.id << " | " << b.title << " by " << b.author;
            cout << (b.isIssued ? " [Issued]\n" : " [Available]\n");
            if (!b.isIssued) availableCount++;
        }
        cout << "\nTotal Books: " << books.size()
             << " | Available: " << availableCount
             << " | Issued: " << books.size() - availableCount << "\n";
    }

    void issueBook(int id, UserData &user) {
        for (auto &b : books) {
            if (b.id == id) {
                if (!b.isIssued) {
                    b.isIssued = true;
                    user.addIssuedBook(id);
                    cout << "\nBook issued successfully!\n";
                } else {
                    cout << "\nBook already issued!\n";
                    suggestSimilar(b.title);
                }
                return;
            }
        }
        cout << "\nBook not found!\n";
    }

    void returnBook(int id, UserData &user) {
        for (auto &b : books) {
            if (b.id == id) {
                if (b.isIssued) {
                    b.isIssued = false;
                    user.removeIssuedBook(id);
                    cout << "\nBook returned successfully!\n";
                } else {
                    cout << "\nBook was not issued!\n";
                }
                return;
            }
        }
        cout << "\nBook not found!\n";
    }

    void suggestSimilar(string title) {
        cout << "\nYou can refer similar books:\n";
        string keyword = toLower(title);
        keyword = keyword.substr(0, keyword.find(' ')); // use first word as keyword
        bool found = false;

        for (auto &b : books) {
            if (!b.isIssued && toLower(b.title).find(keyword) != string::npos) {
                cout << "-> " << b.title << " by " << b.author << "\n";
                found = true;
            }
        }

        if (!found) cout << "No similar available books found.\n";
    }

    void showUserIssuedBooks(const UserData &user) {
        auto ids = user.getIssuedBooks();
        if (ids.empty()) {
            cout << "\nYou have not issued any books yet.\n";
            return;
        }
        cout << "\n--- Your Issued Books ---\n";
        for (int id : ids) {
            for (auto &b : books) {
                if (b.id == id) {
                    cout << "ID: " << b.id << " | " << b.title << " by " << b.author << "\n";
                }
            }
        }
    }
};

class Manager {
private:
    vector<UserData> users;
    Encryptor encryptor;
    Library library;

    void loadUsers() {
        ifstream file("users.txt");
        string line;
        while (getline(file, line)) {
            size_t sep = line.find('|');
            if (sep != string::npos) {
                string uname = line.substr(0, sep);
                string pass = line.substr(sep + 1);
                users.push_back(UserData(uname, pass));
            }
        }
    }

    void saveUser(const UserData& u) {
        ofstream file("users.txt", ios::app);
        file << u.getUsername() << "|" << u.getPassword() << "\n";
    }

public:
    Manager() {
        library.addBook(Book(1, "C++ Programming", "Bjarne Stroustrup"));
        library.addBook(Book(2, "Advanced C++", "Herbert Schildt"));
        library.addBook(Book(3, "Mastering C++", "Stanley Lippman"));
        library.addBook(Book(4, "Data Structures", "Mark Weiss"));
        library.addBook(Book(5, "Algorithms Unlocked", "Thomas Cormen"));
        library.addBook(Book(6, "Operating Systems", "Abraham Silberschatz"));
        library.addBook(Book(7, "Database System Concepts", "Henry Korth"));
        library.addBook(Book(8, "MySQL Cookbook", "Paul DuBois"));
        library.addBook(Book(9, "Computer Networks", "Andrew Tanenbaum"));
        library.addBook(Book(10, "Networking All-in-One", "Doug Lowe"));
        library.addBook(Book(11, "Python Crash Course", "Eric Matthes"));
        library.addBook(Book(12, "Automate the Boring Stuff with Python", "Al Sweigart"));
        library.addBook(Book(13, "Let Us C", "Yashwant Kanetkar"));
        library.addBook(Book(14, "Programming in ANSI C", "E. Balagurusamy"));
        library.addBook(Book(15, "Artificial Intelligence", "Stuart Russell"));
        library.addBook(Book(16, "Deep Learning", "Ian Goodfellow"));
        library.addBook(Book(17, "Machine Learning", "Tom Mitchell"));
        library.addBook(Book(18, "Introduction to Algorithms", "Cormen"));
        library.addBook(Book(19, "Clean Code", "Robert C. Martin"));
        library.addBook(Book(20, "Design Patterns", "Erich Gamma"));
        library.addBook(Book(21, "Modern Compiler Design", "Dick Grune"));
        library.addBook(Book(22, "Software Engineering", "Ian Sommerville"));
        library.addBook(Book(23, "Computer Organization", "Carl Hamacher"));
        library.addBook(Book(24, "Embedded Systems", "Frank Vahid"));
        library.addBook(Book(25, "Programming Pearls", "Jon Bentley"));
        library.addBook(Book(26, "Java: The Complete Reference", "Herbert Schildt"));
        library.addBook(Book(27, "C Programming Absolute Beginner’s Guide", "Greg Perry"));
        library.addBook(Book(28, "Hands-On Machine Learning", "Aurelien Geron"));
        library.addBook(Book(29, "C++ Primer", "Stanley Lippman"));
        library.addBook(Book(30, "Operating System Concepts Essentials", "Galvin"));

        loadUsers();
    }

    void registerUser(string uname, string pass) {
        string encrypted = encryptor.encrypt(pass);
        UserData u(uname, encrypted);
        users.push_back(u);
        saveUser(u);
        cout << "\nUser registered successfully!\n";
    }

    bool login(string uname, string pass) {
        string encrypted = encryptor.encrypt(pass);
        for (auto &u : users) {
            if (u.getUsername() == uname && u.getPassword() == encrypted) {
                cout << "\nLogin successful! Welcome, " << uname << ".\n";
                libraryMenu(u);
                return true;
            }
        }
        cout << "\nInvalid username or password!\n";
        return false;
    }

    void libraryMenu(UserData &user) {
        int choice, id;
        do {
            cout << "\n--- Library Menu ---\n";
            cout << "1. Show Books\n2. Issue Book\n3. Return Book\n4. View Your Issued Books\n5. Logout\n";
            cout << "Enter choice: ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choice) {
                case 1: library.showBooks(); break;
                case 2:
                    cout << "Enter Book ID to issue: ";
                    cin >> id;
                    library.issueBook(id, user);
                    break;
                case 3:
                    cout << "Enter Book ID to return: ";
                    cin >> id;
                    library.returnBook(id, user);
                    break;
                case 4:
                    library.showUserIssuedBooks(user);
                    break;
                case 5:
                    cout << "Logging out...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 5);
    }
};

int main() {
    Manager manager;
    int choice;
    string uname, pass;

    while (true) {
        cout << "\n Library Management System with Privacy \n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> uname;
                cout << "Enter password: ";
                cin >> pass;
                manager.registerUser(uname, pass);
                break;
            case 2:
                cout << "Enter username: ";
                cin >> uname;
                cout << "Enter password: ";
                cin >> pass;
                manager.login(uname, pass);
                break;
            case 3:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}