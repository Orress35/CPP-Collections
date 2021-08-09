#include "Ratio.h"

int gcd(int n, int n2)
{
    if (n  < 0) n  = -n;
    if (n2 < 0) n2 = -n2;
    int gcd = 0;
    for (int i = 1; i <= n && i <= n2; i++)
        if (n % i == 0 && n2 % i == 0)
            gcd = i;
    return gcd;
}

int lcm(int n, int n2)
{
    if (n  < 0) n  = -n;
    if (n2 < 0) n2 = -n2;
    int highest = n > n2 ? n : n2;
    for (int i = highest; i < 1000; i++) {
        if (i % n == 0 && i % n2 == 0) {
            return i;
        }
    }
    return 0;
}

double Ratio::doubleValue()
{
    return (double)dividend / (double)divisor;
}

float Ratio::floatValue()
{
    return (float)dividend / (float)divisor;
}

int Ratio::intValue() {
    return (int)dividend / (int)divisor;
}

Ratio Ratio::add(Ratio y)
{
    Ratio x = simplify();
    y.simplify();

    int i = lcm(x.divisor, y.divisor);

    x.dividend *= i / x.divisor;
    x.divisor  =  i;
    x.dividend += y.dividend * i / y.divisor;
    return x.simplify();
}

Ratio Ratio::subtract(Ratio y)
{
    Ratio x = simplify();
    y.simplify();

    int i = lcm(x.divisor, y.divisor);

    x.dividend *= i / x.divisor;
    x.divisor  =  i;
    x.dividend -= y.dividend * i / y.divisor;
    return x.simplify();
}

Ratio Ratio::multiply(Ratio y)
{
    Ratio x = simplify();
    y.simplify();

    x.divisor *= y.divisor;
    x.dividend *= y.dividend;
    return x.simplify();
}

Ratio Ratio::divide(Ratio y)
{
    Ratio x = simplify();
    y.simplify();

    x.divisor *= y.dividend;
    x.dividend *= y.divisor;
    return x.simplify();
}

Ratio Ratio::simplify()
{
    int i = gcd(dividend, divisor);
    Ratio result(dividend/i, divisor/i);
    return result;
}
