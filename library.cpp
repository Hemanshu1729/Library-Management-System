// #include <iostream>
// using namespace std;
// int main(){
//     cout<<"Hello world";

// return 0;
// }
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct to represent a book
struct Book {
    int id;
    string title;
    string author;
    string Genre;
};

// Class to manage the library
class Library {
private:
    vector<Book> books; // Collection of books
    int nextId; // ID generator for books

public:
    Library() : nextId(1) {}

    // Function to add a new book to the library
    void addBook() {
        Book book;
        book.id = nextId++;
        

        cout << "Enter the title of the book: ";
        cin.ignore();
        getline(cin, book.title);

        cout << "Enter the author of the book: ";
        getline(cin, book.author);
        
        cout<<"Enter The Genre of the book: ";
        getline(cin,book.Genre);

        books.push_back(book);
        cout << "Book added successfully!" << endl;
        cout<<"Book number is: "<<nextId -1<<endl;
         

    }

    // Function to view all books in the library
    void viewBooks() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }

        cout << "\nBooks in the Library:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Genre: "<<book.Genre<<endl;
        }
    }
    
    void viewBooks_id()const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }

        cout << "\nBooks in the Library:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Genre: "<<book.Genre<<endl;
        }
    }

    // Function to search for a book by title
    void searchBook_title() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }

        cout << "Enter the title of the book to search: ";
        cin.ignore();
        string title;
        getline(cin, title);

        bool found = false;
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Genre: "<<book.Genre <<endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }


    //Function to search book by id
    void searchBook_Id() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }

        cout << "Enter the ID of the book to search: ";
        cin.ignore();
        int id;
        cin>>id;

        bool found = false;
        for (const auto& book : books) {
            if (book.id == id) {
                cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Genre: "<<book.Genre <<endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }



    //Function to search book by Genre
    void searchBook_Genre() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }

        cout << "Enter the genre of the book to search: ";
        cin.ignore();
        string genre;
        getline(cin, genre);

        bool found = false;
        for (const auto& book : books) {
            if (book.Genre == genre) {
                cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Genre: "<<book.Genre <<endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }
    

    //Function to search book by author
    void searchBook_author() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }

        cout << "Enter the title of the book to search: ";
        cin.ignore();
        string author;
        getline(cin, author);

        bool found = false;
        for (const auto& book : books) {
            if (book.author == author) {
                cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Genre: "<<book.Genre <<endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }


    // Function to delete a book by ID
    void deleteBook() {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }

        cout << "Enter the ID of the book to delete: ";
        int id;
        cin >> id;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                cout << "Book deleted successfully!" << endl;
                return;
            }
        }

        cout << "Book not found wrong ID." << endl;
    }
};

// Main function to interact with the library
int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                 library.viewBooks();
                 break;
                 
                 
                 
                
                break;
            case 3:
                 cout<<"1. To search by Title"<<endl;
                 cout<<"2. To search by ID"<<endl;
                 cout<<"3. To search by Author"<<endl;
                 cout<<"4. To search by Genre"<<endl;
                 cin>>choice;
                 if (choice==1)
                 {
                    library.searchBook_title();

                 }
                 else if(choice==2)
                 {
                    library.searchBook_Id();

                 }
                 else if(choice==3)
                 {
                    library.searchBook_author();
                 }
                 else if(choice==4)
                 {
                    library.searchBook_Genre();
                 }

                 break;
            case 4:
                library.deleteBook();
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
