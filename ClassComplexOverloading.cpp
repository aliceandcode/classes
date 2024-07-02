#include <iostream>

class Complex {
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    friend std::istream& operator>>(std::istream& in, Complex& c);
public:
    double re;
    double im;
public:

    Complex(double re, double im): re(re), im(im) {}

    Complex& operator+=(const Complex& n)
    {
        re += n.re;
        im += n.im;

        return *this;
    }

    Complex operator+(const Complex& n) const
    {
        Complex sum = *this;
        sum += n;

        return sum;
    }

    Complex& operator-=(const Complex& n)
    {
        re -= n.re;
        im -= n.im;
        
        return *this;
    }

    Complex operator-(const Complex& n) const
    {
        Complex residual = *this;
        residual -= n;

        return residual;
    }

    Complex& operator*=(const Complex& n)
    {
        re *= n.re;
        im *= n.im;

        return *this;
    }

    Complex operator*(const Complex& n) const
    {
        Complex multiply = *this;
        multiply *= n;

        return multiply;
    }

    Complex& operator/=(const Complex& n)
    {
        re /= n.re;
        im /= n.im;

        return *this;
    }

    Complex operator/(const Complex& n) const
    {
        Complex division = *this;

        division /= n;

        return division;
    }

    Complex& operator++()
    {
      re += 1.0;
      im += 1.0;

      return *this;
    }

    Complex operator++(int)
    {
        Complex copy = *this;
        ++*this;
        
        return copy;
    }
    
    Complex& operator--()
    {
        re -= 1.0;
        im -= 1.0;
        
        return *this;
    }

    Complex operator--(int)
    {
        Complex copy = *this;
        --*this;
        
        return copy;
    }

    Complex(const Complex& o){
        re = o.re;
        im = o.im;
    }

    ~Complex(){}

};

std::ostream& operator<<(std::ostream& out, const Complex& c){
    out << c.re;
    out << c.im;

    return out;
}

std::istream& operator>>(std::istream& in, Complex& c){
    std::cout << "Enter two fractional numbers: ";
    in >> c.re >> c.im;
    return in;
}


int main()
{
    Complex c(2.0, 2.0);
    Complex cc(3.0, 3.0);
    
    c += cc;
    std::cout << "Operator +=:" << c.re << " " << c.im << std::endl;
    c = c + cc;
    std::cout << "Operator +: " << c.re << " " << c.im << std::endl;
    c -= cc;
    std::cout << "Operator -=: " << c.re << " " << c.im << std::endl;
    c = c - cc;
    std::cout << "Operator -: " << c.re << " " << c.im << std::endl;
    c *= cc;
    std::cout << "Operator *=: " << c.re << " " << c.im << std::endl;
    c = c * cc;
    std::cout << "Operator *: " << c.re << " " << c.im << std::endl;
    c /= cc;
    std::cout << "Operator /=: " << c.re << " " << c.im << std::endl;
    c = c / cc;
    std::cout << "Operator /: " << c.re << " " << c.im << std::endl;
    ++c;
    std::cout << "Prefix increment: " << c.re << " " << c.im << std::endl;
    c++;
    std::cout << "Postfix increment: " << c.re << " " << c.im << std::endl;
    --c;
    std::cout << "Prefix decrement: " << c.re << " " << c.im << std::endl;
    c--;
    std::cout << "Postfix decrement: " << c.re << " " << c.im << std::endl;

    return 0;
}
