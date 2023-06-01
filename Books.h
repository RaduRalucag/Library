#ifndef _BOOKS_H_
#define _BOOKS_H_

#include <unordered_map>
#include <string>

using namespace std;

class IDGen {
private:
    unordered_map<const void*, int> ids;
    int nextid;
public:
    IDGen();
    template <typename T>
    int generateID(const T *obj);
};

class InvalidPageNumberException : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class Books {
protected:
    Books(string title, string author, int page_number);
    int id;
    string title_;
    string author_;
    int page_number_;
    static IDGen idGen;

public:

    static int numBooks;

    static int getTotalBooks();

    static void check();

    Books();

    Books(const Books &other);


    [[nodiscard]]const string &getTitle() const;

    void setTitle(const string &title);

    [[nodiscard]]const string &getAuthor() const;

    void setAuthor(const string &author);


    [[nodiscard]]int getPageNumber() const;

    void setPageNumber(int page_number);

    Books &operator=(const Books &rhs);

    bool operator==(const Books &other) const;

    bool operator!=(const Books &other) const;

    virtual void read();

    virtual void write(std::ostream& os) const;

    [[nodiscard]] virtual Books* clone() const;

    virtual ~Books();
};

class Library : public Books {
private:
    std::string location;

public:
    Library(std::string location_, const std::string &title_, const std::string &author_, int page_number_);

    [[nodiscard]]const std::string &getLocation() const;

    void setLocation(const std::string &location_);

    virtual bool operator==(const Library &rhs) const;

    Library(const Library &l);

    explicit Library(std::string location);

    virtual bool operator!=(const Library &rhs) const;

    Library &operator=(const Library &rhs);

    void read() override;

    void write(std::ostream& os) const override;

    [[nodiscard]] Library* clone() const override;

    ~Library() override;

    Library();
};

class Sales : public Books {
private:
    int price;

public:
    Sales(int price_, const std::string& title_, const std::string& author_, int page_number_);

    [[nodiscard]]int getPrice() const;

    void setPrice(int newPrice);

    virtual bool operator==(const Sales& rhs) const;

    Sales();

    Sales(const Sales& book);

    explicit Sales(int price);

    virtual bool operator!=(const Sales& rhs) const;

    Sales& operator=(const Sales& rhs);

    void read() override;

    void write(std::ostream& os) const override;

    [[nodiscard]] Sales* clone() const override;
};

class InvalidPublicationYearException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class Publish : public Books{
private:
    string pub_house_;
    int pub_year_;
public:
    Publish(const string& pub_house_, int pub_year_, const string &title_, const string &author_, int page_number_);

    static void check();

    [[nodiscard]]const string &getPubHouse() const;

    void setPubHouse(const string &pub_house);

    [[nodiscard]]int getPubYear() const;

    void setPubYear(int pub_year);

    virtual bool operator!=(const Publish &rhs) const;

    bool operator==(const Publish& rhs) const;

    Publish &operator=(const Publish &rhs);

    Publish();

    Publish(const Publish& book);

    Publish(string pub_house, int pub_year);

    ~Publish();

    void read() override;

    void write(std::ostream& os) const override;

    [[nodiscard]] Publish* clone() const override;
};

class Copies : public Books {
private:
    int copies;

public:
    Copies(int copies_, const std::string& title_, const std::string& author_, int page_number_);

    [[nodiscard]]int getCopies() const;

    void setCopies(int newCopies);

    virtual bool operator==(const Copies& rhs) const;

    Copies();

    explicit Copies(int copies);

    virtual bool operator!=(const Copies& rhs) const;

    Copies& operator=(const Copies& rhs);

    void read() override;

    void write(std::ostream& os) const override;

    [[nodiscard]] Copies* clone() const override;

    Copies(const Copies& other);
};

class Sold : public Books {
private:
    int nr_sold;

public:
    Sold(int nr_sold_, const std::string& title_, const std::string& author_, int page_number_);

    [[nodiscard]]int getNr_sold() const;

    void setNr_sold(int newNr_sold);

    virtual bool operator==(const Sold& rhs) const;

    Sold();

    explicit Sold(int nr_sold);

    virtual bool operator!=(const Sold& rhs) const;

    Sold& operator=(const Sold& rhs);

    void read() override;

    void write(std::ostream& os) const override;

    [[nodiscard]] Sold* clone() const override;

    Sold(const Sold& other);
};

#endif