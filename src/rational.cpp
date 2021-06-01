#include "Rational.h"

int getGreatestCommonDivisor(int numerator, int denominator) {
    while (denominator != 0) {
        int t = denominator;
        denominator = numerator % denominator;
        numerator = t;
    }
    return numerator;
}

Rational::Rational(int numerator, int denominator) {
    if (denominator == 0) {
        throw "The object could not be created because of the denominator of zero!";
    } else {
        if (numerator < 0 && denominator < 0) {
            numer = -numerator;
            denom = -denominator;
        } else {
            numer = numerator;
            denom = denominator;
        }
    }
}

Rational::Rational(const Rational &copy) {
    numer = copy.numer;
    denom = copy.denom;
}

Rational &Rational::operator=(const Rational &other) {
    numer = other.numer;
    denom = other.denom;

    return *this;
}

Rational &Rational::operator=(int i) {
    numer = i;
    denom = 1;

    return *this;
}

Rational Rational::normalize(const Rational &other) {
    int gcm = getGreatestCommonDivisor(other.numer, other.denom);

    return Rational(other.numer / gcm, other.denom / gcm);
}

Rational Rational::normalized(int numerator, int denominator) {
    int gcm = getGreatestCommonDivisor(numerator, denominator);

    return Rational(numerator / gcm, denominator / gcm);
}

Rational Rational::operator+(const Rational &other) const {
    int newNumer;
    int newDenom;

    if (denom != other.denom) {
        newDenom = denom * other.denom;
        newNumer = numer * other.denom + other.numer * denom;
    } else {
        newDenom = denom;
        newNumer = numer + other.numer;
    }
    return normalize(Rational(newNumer, newDenom));
}

Rational Rational::operator-(const Rational &other) const {
    int newNumer;
    int newDenom;

    if (denom != other.denom) {
        newDenom = denom * other.denom;
        newNumer = numer * other.denom - other.numer * denom;
    } else {
        newDenom = denom;
        newNumer = numer - other.numer;
    }
    return normalize(Rational(newNumer, newDenom));
}

Rational Rational::operator*(const Rational &other) const {
    int newNumer = numer * other.numer;
    int newDenom = denom * other.denom;

    return normalize(Rational(newNumer, newDenom));
}

Rational Rational::operator/(const Rational &other) const {
    int newNumer = numer * other.denom;
    int newDenom = denom * other.numer;

    return normalize(Rational(newNumer, newDenom));
}

void Rational::initialize(int numerator, int denominator) {
    numer = numerator;
    denom = denominator;
}

Rational Rational::operator+() const {
    return normalize(Rational(numer, denom));
}

Rational Rational::operator-() const {
    return normalize(Rational(-numer, denom));
}

bool Rational::operator==(const Rational &other) const {
    if (numer * other.denom == other.numer * denom) {
        return true;
    } else {
        return false;
    }
}

bool Rational::operator>=(const Rational &other) const {
    if (denom * other.denom > 0) {
        return numer * other.denom >= other.numer * denom;
    } else {
        return numer * other.denom <= other.numer * denom;
    }
}

bool Rational::operator<=(const Rational &other) const {
    if (denom * other.denom > 0) {
        return numer * other.denom <= other.numer * denom;
    } else {
        return numer * other.denom >= other.numer * denom;
    }
}

bool Rational::operator>(const Rational &other) const {
    if (denom * other.denom > 0) {
        return numer * other.denom > other.numer * denom;
    } else {
        return numer * other.denom < other.numer * denom;
    }
}

bool Rational::operator<(const Rational &other) const {
    if (denom * other.denom > 0) {
        return numer * other.denom < other.numer * denom;
    } else {
        return numer * other.denom > other.numer * denom;
    }
}

std::ostream &operator<<(std::ostream &os, const Rational &r) {
    if (r.numer < 0 || r.denom < 0) {
        return (os << "(" << r.numer << "/" << r.denom << ")");
    } else {
        return (os << r.numer << "/" << r.denom);
    }
}

std::istream &operator>>(std::istream &is, const Rational &r) {
    return (is >> r.numer >> r.denom);
}

Rational operator+(const Rational &r, int i) {
    return Rational(i * r.denominator() + r.numerator(), r.denominator());
}

Rational operator+(int i, const Rational &r) {
    return (r + i);
}

Rational operator-(const Rational &r, int i) {
    return Rational(r.numerator() - r.denominator() * i, r.denominator());
}

Rational operator-(int i, const Rational &r) {
    return Rational(r.denominator() * i - r.numerator(), r.denominator());
}

Rational operator*(const Rational &r, int i) {
    return Rational(r.numerator() * i, r.denominator());
}

Rational operator*(int i, const Rational &r) {
    return (r * i);
}

Rational operator/(const Rational &r, int i) {
    return Rational(r.numerator(), r.denominator() * i);
}

Rational operator/(int i, const Rational &r) {
    return Rational(i * r.denominator(), r.numerator());
}