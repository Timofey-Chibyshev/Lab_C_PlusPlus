#include <iostream> 
#include <cmath> 

using namespace std;

void Solver(const double a, const double b, const double c)
{
    double d = b * b - 4 * a * c;
    if (d > 0)
    {
        cout << "x1 = " << ((-b) + sqrt(d)) / (2 * a) << "\n";
        cout << "x2 = " << ((-b) - sqrt(d)) / (2 * a) << "\n";
    }
    if (d == 0)
    {
        cout << "x1 = x2 = " << -(b / (2 * a)) << "\n";
    }
    if (d < 0) 
        cout << "D < 0, no reality roots";
    return;
}

int main()
{
    double a = 0, b = 0, c = 0; 
    cout << "Input a, b, c coefficients of quadratic equation ax^2 + bx + c = 0" << endl;
    cout << "Enter a:\n"; 
    cin >> a;
    cout << "Enter b:\n";
    cin >> b;
    cout << "Enter c:\n";
    cin >> c;
    Solver(a, b, c);
    return 0;
}