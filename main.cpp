#include <iostream>
#include <memory>
#include <vector>
#include "Books.h"

using namespace std;

int main() {
    cout << "Welcome to the library!" << endl;
    int d = 0;
    while (d != 7) {
        cout << "1 - Books" << endl << "2 - Sales" << endl << "3 - Library" << endl << "4 - Publish" << endl
             << "5 - Copies" << endl << "6 - Sold" << endl << "7 - Exit" << endl;
        cin >> d;
        switch (d) {
            case 1: {
                int x=0, i=0;
                Books a[101];
                while (x != 3) {
                    cout << "1 - Show" << endl << "2 - Insert" << endl << "3 - Number of total books" << endl << "4 - Exit" << endl;
                    cin >> x;
                    switch (x) {
                        case 1: {
                            for(int j=0; j<i; j++) {
                                a[j].write(cout);
                            }
                            break;
                        }
                        case 2:{
                            auto b = make_shared<Books>();
                            b->read();
                            try {
                                b->check();
                            } catch (const InvalidPageNumberException& e) {
                                cout << "Error: " << e.what() << endl;
                            }
                            a[i] = *b;
                            i++;
                            break;
                        }
                        case 3:{
                            int totalBooks = Books::getTotalBooks();
                            cout << totalBooks << endl;
                            break;
                        }
                        case 4:{
                            return 0;
                        }
                        default: {
                            cout << endl << "Invalid command. Please try again." << endl;
                            break;
                        }
                    }
                    }

            }
            case 2: {
                int x = 0, i = 0;
                Sales a[101];
                while (x != 3) {
                    cout << "1 - Show" << endl << "2 - Insert" << endl << "3 - Exit" << endl;
                    cin >> x;
                    switch (x) {
                        case 1: {
                            for (int j = 0; j < i; j++)
                                a[j].write(cout);
                            break;
                        }
                        case 2: {
                            Books *b = new Sales();
                            auto *s = dynamic_cast<Sales *>(dynamic_cast<Books *>(b));
                            s->read();
                            a[i] = *s;
                            i++;
                            break;
                        }
                        case 3: {
                            return 0;
                        }
                        default: {
                            cout << endl << "Invalid command. Please try again." << endl;
                            break;
                        }
                    }
                }

            }
            case 3: {int x = 0, i = 0;
                Library a[101];
                while (x != 3) {
                    cout << "1 - Show" << endl << "2 - Insert" << endl << "3 - Exit" << endl;
                    cin >> x;
                    switch (x) {
                        case 1: {
                            for (int j = 0; j < i; j++)
                                a[j].write(cout);
                            break;
                        }
                        case 2: {
                            Books *b = new Library();
                            auto *l = dynamic_cast<Library *>(dynamic_cast<Books *>(b));
                            l->read();
                            a[i] = *l;
                            i++;
                            break;
                        }
                        case 3: {
                            return 0;
                        }
                        default: {
                            cout << endl << "Invalid command. Please try again." << endl;
                            break;
                        }
                    }
                }

            }
            case 4: {int x = 0, i = 0;
                Publish a[101];
                while (x != 3) {
                    cout << "1 - Show" << endl << "2 - Insert" << endl << "3 - Exit" << endl;
                    cin >> x;
                    switch (x) {
                        case 1: {
                            for (int j = 0; j < i; j++)
                                a[j].write(cout);
                            break;
                        }
                        case 2: {
                            Books *b = new Publish();
                            auto *p = dynamic_cast<Publish *>(dynamic_cast<Books *>(b));
                            p->read();
                            try {
                                p->check();
                            } catch (const InvalidPublicationYearException& e) {
                                std::cerr << "Error: " << e.what() << std::endl;
                            }
                            a[i] = *p;
                            i++;
                            break;
                        }
                        case 3: {
                            return 0;
                        }
                        default: {
                            cout << endl << "Invalid command. Please try again." << endl;
                            break;
                        }
                    }
                }

            }
            case 5: {int x = 0, i = 0;
                Copies a[101];
                while (x != 3) {
                    cout << "1 - Show" << endl << "2 - Insert" << endl << "3 - Exit" << endl;
                    cin >> x;
                    switch (x) {
                        case 1: {
                            for (int j = 0; j < i; j++)
                                a[j].write(cout);
                            break;
                        }
                        case 2: {
                            Books *b = new Copies();
                            auto *c = dynamic_cast<Copies *>(dynamic_cast<Books *>(b));
                            c->read();
                            a[i] = *c;
                            i++;
                            break;
                        }
                        case 3: {
                            return 0;
                        }
                        default: {
                            cout << endl << "Invalid command. Please try again." << endl;
                            break;
                        }
                    }
                }

            }
            case 6: {int x = 0, i = 0;
                Sold a[101];
                while (x != 3) {
                    cout << "1 - Show" << endl << "2 - Insert" << endl << "3 - Exit" << endl;
                    cin >> x;
                    switch (x) {
                        case 1: {
                            for (int j = 0; j < i; j++)
                                a[j].write(cout);
                            break;
                        }
                        case 2: {
                            Books *b = new Sold();
                            auto *o = dynamic_cast<Sold *>(dynamic_cast<Books *>(b));
                            o->read();
                            a[i] = *o;
                            i++;
                            break;
                        }
                        case 3: {
                            return 0;
                        }
                        default: {
                            cout << endl << "Invalid command. Please try again." << endl;
                            break;
                        }
                    }
                }

            }
            case 7: {
                cout << "Goodbye" << endl;
                return 0;
            }
            default: {
                cout << endl << "Invalid command. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}

