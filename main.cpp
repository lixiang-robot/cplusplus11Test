#include <QCoreApplication>

#include <iostream>
#include <atomic>

using namespace std;

atomic<int> x = ATOMIC_VAR_INIT(false);
atomic<int> y = ATOMIC_VAR_INIT(false);
atomic<int> z = ATOMIC_VAR_INIT(0);

void write_x()
{
    x.store(true, memory_order_seq_cst);
}

void write_y()
{
    y.store(true, memory_order_seq_cst);
}

void read_x_then_y()
{
    while (!x.load(std::memory_order_seq_cst))
        ;
    if (y.load(std::memory_order_seq_cst)) {
        ++z;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Hello World!" << endl;

    return a.exec();
}

