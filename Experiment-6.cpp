#include <iostream>
using namespace std;
class Matrix
{
public:
    int a, b;
    Matrix(int x = 0, int y = 0)
    {
        a = x;
        b = y;
    }
    // Function Overloading
    void display()
    {
        cout << a << " " << b << endl;
    }
    void display(string msg)
    {
        cout << msg << ": " << a << " " << b << endl;
    }
    // Operator Overloading
    Matrix operator+(Matrix m)
    {
        Matrix temp;
        temp.a = a + m.a;
        temp.b = b + m.b;
        return temp;
    }
};
int main()
{
    Matrix m1(2, 3);
    Matrix m2(4, 5);
    cout << "First Matrix: ";
    m1.display();
    m2.display("Second Matrix");
    Matrix m3 = m1 + m2;
    cout << "Addition: ";
    m3.display();
    return 0;
}
