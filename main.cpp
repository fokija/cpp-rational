#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    Rational test_r(1,2);
    cout << test_r; 

    cout << test_r.numerator();

    Rational t_r_2(50,100);

    t_r_2 = Rational::normalize(t_r_2);

    Rational tr3 = Rational::normalized(123,4);

    cout << "\n" << t_r_2 << "\n" << tr3 << "\n";

    Rational r1(1,2);
    Rational r2(-1,4);

    cout << "test dodawania";
    cout << "\n" << r1 + r2 << "\n";
    cout << "\n" << Rational::normalize(r1 + r2) << "\n";
    cout << "test odejmoania";
    cout << "\n" << r1 - r2 << "\n";
    cout << "\n" << Rational::normalize(r1 - r2) << "\n";

    cout << "test mnozenia" << endl;
    cout << r1 * r2 << endl;
    cout << "test dzielenia" <<endl;
    cout << r1 / r2 << endl;
    
    // Rational r2(2, 11), r3(1, -3), r5(18, 6);
    // Rational res1 = 3 + r2 * r3;
    // Rational res2 = (3 + r2) * r3;
    // Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);

    // cout << 3 << " + " << r2 << " * " << r3 << " = " << res1 <<endl;
    // //out << "(" << 3 << " + " << r2 << 



}

