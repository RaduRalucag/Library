#include <iostream>
#include <utility>
#include <string>
#include "Books.h"


IDGen::IDGen() : nextid(1) {}

template <typename T>
int IDGen::generateID(const T* obj) {
    const void* address = static_cast<const void*>(obj);
    auto it = ids.find(address);
    if (it != ids.end()) {
        return it->second; // ID already exists for the object
    }

    int id = nextid++;
    ids.insert({address, id});
    return id;
}

IDGen Books::idGen;

const char *InvalidPageNumberException::what() const noexcept {
    return "Page number must be greater than or equal to 1";
}


int Books::numBooks = 0;

void Books::check() {
    Books book;
    if (book.getPageNumber() < 1) {
        throw InvalidPageNumberException();
    }
}

int Books::getTotalBooks() { return numBooks; }

Books::Books() : title_(new char[1]), author_(new char[1]), page_number_(0) {
    title_[0] = '\0';
    author_[0] = '\0';
    id = idGen.generateID(this);
}

Books::Books(const Books &other)
{
    title_ = other.title_;
    author_ = other.author_;
    page_number_ = other.page_number_;
}

const std::string& Books::getTitle() const {
    return title_;
}

void Books::setTitle(const std::string& title) {
    title_ = title;
}

const std::string& Books::getAuthor() const {
    return author_;
}

void Books::setAuthor(const std::string& author) {
    author_ = author;
}

int Books::getPageNumber() const {
    return page_number_;
}

void Books::setPageNumber(int page_number) {
    page_number_ = page_number;
}

bool Books::operator==(const Books& other) const {
    return title_ == other.title_ && author_ == other.author_ && page_number_ == other.page_number_;
}

bool Books::operator!=(const Books& other) const {
    return !(*this == other);
}

class Books& Books::operator=(const Books& rhs) {
    if (this != &rhs) {
        setTitle(rhs.title_);
        setAuthor(rhs.author_);
        page_number_ = rhs.page_number_;
    }
    return *this;
}

void Books::read() {
    std::cout << "Enter the title: ";
    std::cin >> title_;
    std::cout << "Enter the author: ";
    std::cin >> author_;
    std::cout << "Enter the number of pages: ";
    std::cin >> page_number_;
    numBooks++;
}

void Books::write(std::ostream& os) const {
    os << "ID: " << id << "\n"
       << "Title: " << title_ << "\n"
       << "Author: " << author_ << "\n"
       << "Page Number: " << page_number_ << "\n";
}

Books* Books::clone() const {
    return new Books(*this);
}

Books::~Books() {
}

Books::Books(std::string title, string author, int page_number) {

}

Library::Library(std::string location)
        : Books(), location(std::move(location))
{
}

Library::Library(std::string location, const std::string& title, const std::string& author, int page_number)
        : Books(title, author, page_number), location(std::move(location))
{
}

[[nodiscard]] const std::string& Library::getLocation() const {
    return location;
}

void Library::setLocation(const std::string& location_) {
    location = location_;
}

bool Library::operator==(const Library& rhs) const {
    return location == rhs.location && static_cast<const Books&>(*this) == static_cast<const Books&>(rhs);
}

bool Library::operator!=(const Library& rhs) const {
    return !(*this == rhs);
}

Library& Library::operator=(const Library& rhs) {
    if (this != &rhs) {
        static_cast<Books&>(*this) = static_cast<const Books&>(rhs);
        location = rhs.location;
    }
    return *this;
}

Library::Library(const Library &l)  : Books(l) {

}

void Library::read() {
    Books::read();
    std::cout << "Enter the location: ";
    std::cin >> location;
}

void Library::write(std::ostream& os) const {
    Books::write(os);
    os << "Location: " << location << "\n\n";
}

Library::~Library() {

}

Library::Library() {

}

Library *Library::clone() const {
    return new Library(*this);
}

Sales::Sales() : Books(), price(0) {}
Sales::Sales(int price, const std::string& title, const std::string& author, int page_number)
        : Books(title, author, page_number), price(price) {}

int Sales::getPrice() const { return price; }
void Sales::setPrice(int newPrice) { price = newPrice; }

bool Sales::operator==(const Sales& rhs) const { return price == rhs.price && Books::operator==(rhs); }
bool Sales::operator!=(const Sales& rhs) const { return !(*this == rhs); }

Sales& Sales::operator=(const Sales& rhs) {
    if (this != &rhs) {
        Books::operator=(rhs);
        price = rhs.price;
    }
    return *this;
}

Sales::Sales(const Sales &book) {

}

Sales::Sales(int price) {

}
void Sales::read() {
    Books::read();
    std::cout << "Enter the price: ";
    std::cin >> price;
}

void Sales::write(std::ostream& os) const {
    Books::write(os);
    os << "Price: " << price << "\n\n";
}

Sales *Sales::clone() const {
    return new Sales(*this);
}

const char* InvalidPublicationYearException::what() const noexcept {
    return "Invalid publication year (must be greater than or equal to 1)";
}
Publish& Publish::operator=(const Publish& other) {
    if (this != &other) {
        Books::operator=(other);
        pub_house_ = other.pub_house_;
        pub_year_ = other.pub_year_;
    }
    return *this;
}

void Publish::check() {
    Publish pub;
    if (pub.getPubYear() < 1) {
        throw InvalidPublicationYearException();
    }
}

const string& Publish::getPubHouse() const { return pub_house_; }
void Publish::setPubHouse(const string& pub_house) { pub_house_ = pub_house; }
int Publish::getPubYear() const { return pub_year_; }
void Publish::setPubYear(int pub_year) {
    pub_year_ = pub_year;
}

bool Publish::operator==(const Publish& other) const { return pub_house_ == other.pub_house_ && pub_year_ == other.pub_year_; }
bool Publish::operator!=(const Publish& other) const { return !(*this == other); }

Publish::Publish() {

}

Publish::Publish(const Publish &book) {

}

Publish::Publish(string pub_house, int pub_year) {

}

void Publish::read() {
    Books::read();
    std::cout << "Enter the publisher: ";
    std::cin >> pub_house_;
    std::cout << "Enter the publication year: ";
    std::cin >> pub_year_;
}

void Publish::write(std::ostream& os) const {
    Books::write(os);
    os << "Publisher: " << pub_house_ << "\n"
       << "Publication Year: " << pub_year_ << "\n\n";
}

Publish *Publish::clone() const {
    return new Publish(*this);
}

Publish::~Publish() {

}

Publish::Publish(const string& pub_house_, int pub_year_, const string &title_, const string &author_, int page_number_) : Books(title_,author_,page_number_) {

}


Copies::Copies(int copies_, const std::string& title_, const std::string& author_, int page_number_)
        : Books(), copies(copies_)
{
}

[[nodiscard]]int Copies::getCopies() const { return copies; }

void Copies::setCopies(int newCopies) { copies = newCopies; }

bool Copies::operator==(const Copies& rhs) const { return copies == rhs.copies; }

Copies::Copies() : Books(), copies(0)
{
}

Copies::Copies(int copies) : Books(), copies(copies)
{
}

bool Copies::operator!=(const Copies& rhs) const { return !(*this == rhs); }

Copies& Copies::operator=(const Copies& rhs)  {
    if (this != &rhs) {
        Books::operator=(rhs);
        copies = rhs.copies;
    }
    return *this;
}
void Copies::read() {
    Books::read();
    std::cout << "Enter the number of copies: ";
    std::cin >> copies;
}

void Copies::write(std::ostream& os) const {
    Books::write(os);
    os << "Copies: " << copies << "\n\n";
}

Copies *Copies::clone() const {
    return new Copies(*this);
}

Copies::Copies(const Copies& other)
        : Books(other) {   copies = other.copies;

    setTitle(other.getTitle());
    setAuthor(other.getAuthor());
    setPageNumber(other.getPageNumber());
}

Sold::Sold(int nr_sold_, const std::string& title_, const std::string& author_, int page_number_)
        : Books(), nr_sold(nr_sold_)
{
}

[[nodiscard]]int Sold::getNr_sold() const { return nr_sold; }

void Sold::setNr_sold(int newNr_sold) { nr_sold = newNr_sold; }

bool Sold::operator==(const Sold& rhs) const { return nr_sold == rhs.nr_sold; }

Sold::Sold() : Books(), nr_sold(0)
{
}

Sold::Sold(int nr_sold) : Books(), nr_sold(nr_sold)
{
}

bool Sold::operator!=(const Sold& rhs) const { return !(*this == rhs); }

Sold& Sold::operator=(const Sold& rhs)  {
    if (this != &rhs) {
        Books::operator=(rhs);
        nr_sold = rhs.nr_sold;
    }
    return *this;
}

void Sold::read() {
    Books::read();
    std::cout << "Enter the number of books sold: ";
    std::cin >> nr_sold;
}

void Sold::write(std::ostream& os) const {
    Books::write(os);
    os << "Number Sold: " << nr_sold << "\n\n";
}

Sold *Sold::clone() const {
    return new Sold(*this);
}

Sold::Sold(const Sold& other)
        : Books(other) {
    nr_sold = other.nr_sold;

    setTitle(other.getTitle());
    setAuthor(other.getAuthor());
    setPageNumber(other.getPageNumber());
}