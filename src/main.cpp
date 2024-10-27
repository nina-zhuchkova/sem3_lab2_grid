#include <Grid.h>
#include <iostream>

/*
class int_with_default {
    int i;
public:
    int_with_default() {
        i = 0;
    }
    friend std::ostream& operator<<(std::ostream& os, const int_with_default& obj) {
        os << obj.i;
        return os;
    }
};
*/

int main() {
    Grid<int, 2> a(2, 3, 0);
    a.print();
    std::cout << a.get_dim_size(1) << '\n';

    Grid<int, 2> b(a);
    b.print();

    Grid<int, 2> c(Grid<int, 2>(2, 3, 1));
    c.print();

    Grid<int, 2> d(std::move(a));
    d.print();
    a.print();
    std::cout << a.get_dim_size(0) << '\n';
    std::cout << a[0][0] << '\n';
}