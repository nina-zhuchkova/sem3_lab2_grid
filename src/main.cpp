#include <Grid.h>
#include <iostream>
#include <memory>

class no_def_int {
    int i;
public:
    no_def_int(int i): i(i) { }

    friend std::ostream& operator<<(std::ostream& os, const no_def_int& obj) {
        os << obj.i;
        return os;
    }
};

struct Luntik {
    Luntik() {
        setlocale(LC_ALL, "Russian");
        std::cout << "Лунтик " << this << ": Я родился!\n";
    }
    ~Luntik() {
        setlocale(LC_ALL, "Russian");
        std::cout << "Лунтик " << this << ": Я умер!\n";
    }
};

int main() {
    std::cout << "construct default a\n";
    Grid<int, 2> a(2, 3);
    std::cout << "a " << &a << ":\n";
    a.print();

    std::cout << "fill a\n";
    for (auto i = 0u; i < 2; ++i) {
        for (auto j = 0u; j < 3; ++j) {
            a[i][j] = i * 3 + j;
        }
    }
    std::cout << "a " << &a << ":\n";
    a.print();

    std::cout << "construct b by copying a\n";
    Grid<int, 2> b(a);
    std::cout << "b " << &b << ":\n";
    b.print();
    std::cout << "a " << &a << ":\n";
    a.print();

    std::cout << "construct c\n";
    Grid<int, 2> c(Grid<int, 2>(2, 3, 1));
    std::cout << "c " << &c << ":\n";
    c.print();

    std::cout << "construct d by moving a\n";
    Grid<int, 2> d(std::move(a));
    std::cout << "d " << &d << ":\n";
    d.print();
    std::cout << "a " << &a << ":\n";
    a.print();

    std::cout << "construct e\n";
    Grid<int, 2> e(2, 4, 2);
    std::cout << "e " << &e << ":\n";
    e.print();

    std::cout << "copy \n[1, 1, 1, 1]\n[1, 1, 1, 1]\nto e\n";
    e = Grid<int, 2>(2, 4, 1);
    std::cout << "e " << &e << ":\n";
    e.print();

    std::cout << "copy b to c\n";
    c = b;
    std::cout << "c " << &c << ":\n";
    c.print();
    std::cout << "b " << &b << ":\n";
    b.print();

    std::cout << "move e to c\n";
    c = std::move(e);
    std::cout << "c " << &c << ":\n";
    c.print();
    std::cout << "e " << &b << ":\n";
    e.print();
    
    std::cout << "construct f from type with no default constructor\n";
    Grid<no_def_int, 2> f(2, 3, 1);
    std::cout << "f " << &f << ":\n";
    f.print();

    std::cout << "construct grid g of shared_pointers to Luntik\n";
    Grid<std::shared_ptr<Luntik>, 3> g(10, 10, 10, std::shared_ptr<Luntik>(new Luntik()));
    return 0;
}