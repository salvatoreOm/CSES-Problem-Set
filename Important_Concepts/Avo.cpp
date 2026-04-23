// Library M System
#include <bits/stdc++.h>
using namespace std;

class Book {
public:
    int id;
    string title, author, category;
    bool present; // availability flag

    // Constructor
    Book(int id, string t, string a, string c) {
        this->id = id;
        title = t;
        author = a;
        category = c;
        present = true;
    }
};

class Library {
private:
    unordered_map<int, Book*> books;
    unordered_set<int> available;
    unordered_map<int, int> borrower;              // bookId -> userId
    unordered_map<int, queue<int>> reserve_q;      // bookId -> queue of users

public:
    // Add Book
    void addBook(int id, string t, string a, string c) {
        if (books.count(id)) {
            cout << "Found Duplicate Book" << endl;
            return;
        }
        books[id] = new Book(id, t, a, c);
        available.insert(id);
    }

    // Remove Book
    void removeBook(int id) {
        if (!books.count(id)) return;

        if (borrower.count(id)) {
            cout << "Book is Borrowed by someone, It should not be removed" << endl;
            return;
        }

        books.erase(id);
        available.erase(id);
        reserve_q.erase(id);
    }

    // Borrow Book
    void borrowBook(int userId, int bookId) {
        if (!books.count(bookId)) return;

        if (!available.count(bookId)) {
            reserve_q[bookId].push(userId);
            cout << "Added to the reserve queue for Borrow" << endl;
            return;
        }

        available.erase(bookId);
        borrower[bookId] = userId;
        books[bookId]->present = false;
    }

    // Return Book
    void returnBook(int bookId) {
        if (!borrower.count(bookId)) {
            cout << "Invalid Operation" << endl;
            return;
        }

        borrower.erase(bookId);

        // Assign to next user in queue if exists
        if (!reserve_q[bookId].empty()) {
            int front_u = reserve_q[bookId].front();
            reserve_q[bookId].pop();
            borrower[bookId] = front_u;
            cout << "Assigned" << endl;
        } else {
            available.insert(bookId);
            books[bookId]->present = true;
        }
    }

    // List Available Books
    void list_all() {
        for (int book : available) {
            cout << books[book]->title << endl;
        }
    }

    // Filter by Author
    void filter(string author) {
        for (auto &b : books) {
            if (b.second->author == author) {
                cout << b.second->title << endl;
            }
        }
    }
};

int main() {
    Library lib;

    // Add Books
    lib.addBook(1, "Subtle Art", "Mark Manson", "Life");
    lib.addBook(2, "Maths", "Om", "Mathematics");
    lib.addBook(3, "Chemistry", "Yuvraj", "Science");

    // List Available Books
    cout << "Current books are" << endl;
    lib.list_all();

    // Borrow Book
    cout << "This user took the book 1" << endl;
    lib.borrowBook(66, 1);

    // List After Borrow
    cout << "Current Available" << endl;
    lib.list_all();

    // Return Book
    cout << "Return 1st book" << endl;
    lib.returnBook(1);

    // Final List
    cout << "New available" << endl;
    lib.list_all();

    return 0;
}