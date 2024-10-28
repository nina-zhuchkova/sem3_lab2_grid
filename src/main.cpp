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
/*
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
    //std::cout << a[0][0] << '\n';

    c = b;
    c.print();

    c = std::move(b);
    c.print();
    

    return 0;
}
*/

/*
-создание сетки от объектов, которые не содержат конструктора по умолчанию
-тестирование копирования
-тестирование перемещения
-тестирование работы оператора индексирования
-создание сетки от нетривиального типа (типа, который сам управляет ресурсом)
-для многомерных сеток покажите как работает принцип понижения размерности - 
оператор индексирования возвращает сетку меньшей размерности.
*/
#include <cassert>
int main() {
    Grid<float,3> const g3(2, 3, 4, 1.0f);
    assert(1.0f == g3(1, 1, 1));

    Grid<float,2> g2(2, 5, 2.0f);
    assert(2.0f == g2(1, 1));

    g2 = g3[1];
    assert(1.0f == g2(1, 1));

}