#ifndef FRACTION_H
#define FRACTION_H
#include <numeric>
#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    // Construtor default
    Fraction() 
        : Fraction(1,1) 
    {
    }

    // Construtor que recebe numerador e denominador e cria a fracao
    Fraction(int numerator, int denominator) 
        : m_numerator{numerator}, m_denominator{denominator}
    {
        if(m_denominator == 0)
            throw std::runtime_error("denominador nulo");
        reduce();
    }

    // Metodo que simplifica a fracao
    void reduce() {
        int gcd = std::gcd(m_numerator, m_denominator);
        m_numerator = m_numerator / gcd;
        m_denominator = m_denominator / gcd;
    }

    // getters
    int getNumerator() const {
        return m_numerator;
    }
    int getDenominator() const {
        return m_denominator;
    }
    // setters
    void setNumerator(int newNumerator) {
        m_numerator = newNumerator;
        reduce();
    }
    void setDenominator(int newDenominator) {
        m_denominator = newDenominator;
        if(m_denominator == 0)
            throw std::runtime_error("denominador nulo");
        reduce();
    }

    // Sobrecarga do operador+ como funcao-membro da classe Fraction
    Fraction operator+(const Fraction& f2) {
        int denominator = m_denominator * f2.m_denominator;
        int numerator = m_numerator * f2.m_denominator + f2.m_numerator * m_denominator;
        return Fraction(numerator, denominator);
    }

    // Sobrecarga do operador- como funcao-membro da classe Fraction
    Fraction operator-(const Fraction& f2) {
        int denominator = m_denominator * f2.m_denominator;
        int numerator = m_numerator * f2.m_denominator - f2.m_numerator * m_denominator;
        return Fraction(numerator, denominator);
    }

    // Sobrecarga do operator+= como funcao membro
    Fraction& operator+=(const Fraction& f2) {
        *this = *this + f2;
        return *this;
    }

    // Sobrecarga do operator-= como funcao membro
    Fraction& operator-=(const Fraction& f2) {
        *this = *this - f2;
        return *this;
    }

    // Sobrecarga dos operadores relacionais e de igualdade
    friend bool operator==(const Fraction& f1, const Fraction& f2) {
        return f1.m_numerator == f2.m_numerator && f1.m_denominator == f2.m_denominator;
    }

    friend bool operator!=(const Fraction& f1, const Fraction& f2) {
        return !(f1 == f2);
    }

    friend bool operator<(const Fraction& f1, const Fraction& f2) {
        return f1.m_numerator*f2.m_denominator < f2.m_numerator*f1.m_denominator;
    }

    friend bool operator>(const Fraction& f1, const Fraction& f2) {
        return f1.m_numerator*f2.m_denominator > f2.m_numerator*f1.m_denominator;
    }

    friend bool operator<=(const Fraction& f1, const Fraction& f2) {
        return (f1 < f2) || (f1 == f2);
    }

    friend bool operator>=(const Fraction& f1, const Fraction& f2) {
        return (f1 > f2) || (f1 == f2);
    }

    // Funções globais amigas
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
        out << f.m_numerator << "/" << f.m_denominator;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Fraction& f) {
        in >> f.m_numerator;
        in.ignore();
        in >> f.m_denominator;
        f.reduce();
        return in;
    }

};
// End of class Fraction ---------------------------------------------------


#endif