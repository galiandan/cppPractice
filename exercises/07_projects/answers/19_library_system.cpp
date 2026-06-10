// 题 19：图书管理系统

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Book {
private:
    std::string title_;
    std::string author_;
    std::string isbn_;
    bool borrowed_ = false;

public:
    Book(std::string title, std::string author, std::string isbn)
        : title_(std::move(title)), author_(std::move(author)), isbn_(std::move(isbn)) {}

    const std::string& title() const {
        return title_;
    }

    const std::string& isbn() const {
        return isbn_;
    }

    bool borrowed() const {
        return borrowed_;
    }

    bool borrow() {
        if (borrowed_) {
            return false;
        }
        borrowed_ = true;
        return true;
    }

    bool giveBack() {
        if (!borrowed_) {
            return false;
        }
        borrowed_ = false;
        return true;
    }

    void print() const {
        std::cout << title_ << " / " << author_
                  << " / " << isbn_
                  << " / " << (borrowed_ ? "borrowed" : "available") << '\n';
    }
};

class Library {
private:
    std::vector<Book> books_;

    Book* findByIsbn(const std::string& isbn) {
        auto it = std::find_if(books_.begin(), books_.end(), [&](const Book& book) {
            return book.isbn() == isbn;
        });
        return it == books_.end() ? nullptr : &*it;
    }

public:
    void addBook(Book book) {
        books_.push_back(std::move(book));
    }

    bool borrowBook(const std::string& isbn) {
        Book* book = findByIsbn(isbn);
        return book != nullptr && book->borrow();
    }

    bool returnBook(const std::string& isbn) {
        Book* book = findByIsbn(isbn);
        return book != nullptr && book->giveBack();
    }

    void searchByTitle(const std::string& keyword) const {
        for (const auto& book : books_) {
            if (book.title().find(keyword) != std::string::npos) {
                book.print();
            }
        }
    }
};

int main() {
    Library lib;
    lib.addBook(Book("Effective C++", "Scott Meyers", "001"));
    lib.addBook(Book("C++ Primer", "Lippman", "002"));

    lib.borrowBook("001");
    lib.searchByTitle("C++");
    lib.returnBook("001");
}
