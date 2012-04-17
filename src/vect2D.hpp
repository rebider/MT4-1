#ifndef VECT2D_HPP_INCLUDED
#define VECT2D_HPP_INCLUDED

#include "vector.hpp"

using namespace std;

/*typedef float TValue;

    class Vect2D
    {
        public :
        TValue x,y;

        Vect2D(void); // x = 0, y = 0
        Vect2D(TValue _x, TValue _y); // x = _x,y = _y
        Vect2D(const Vect2D& v); // x = v.x, y = v.y
        Vect2D(TValue theta); //

        Vect2D& operator+=(const Vect2D& v);
        Vect2D& operator-=(const Vect2D& v);
        Vect2D& operator*=(const Vect2D& v);
        Vect2D& operator/=(const Vect2D& v);
        Vect2D& operator*=(TValue s);
        Vect2D& operator/=(TValue s);

        Vect2D operator+(const Vect2D& v) const;
        Vect2D operator-(const Vect2D& v) const;
        Vect2D operator-(void) const;
        Vect2D operator*(const Vect2D& v) const;
        Vect2D operator/(const Vect2D& v) const;
        Vect2D operator*(TValue s) const;
        Vect2D operator/(TValue s) const;
        bool   operator==(const Vect2D& v) const;
        bool   operator!=(const Vect2D& v) const;

        void makeUnitary(void);

        TValue norm(void) const;
        TValue distance(const Vect2D& v) const;
        TValue scalarProd(const Vect2D& v) const;
        TValue angle(const Vect2D& v) const;
        TValue angleX(void) const;
        Vect2D getUnitary(void) const;
    };

    Vect2D operator*(TValue s, const Vect2D& v);
    Vect2D operator/(TValue s, const Vect2D& v);
        ostream &operator<<( ostream &flux, Vect2D const& v);*/

typedef float TValue;

class Vect2D : public Vector<TValue,2>
{
public :
    Vect2D(void);
    Vect2D(TValue _x, TValue _y);
    Vect2D(const Vect2D& v);
    Vect2D(TValue theta);
    Vect2D(const Vector<TValue,2>& v);

    using Vector<TValue,2>::operator+=;
    using Vector<TValue,2>::operator-=;
    using Vector<TValue,2>::operator*=;
    using Vector<TValue,2>::operator/=;
    using Vector<TValue,2>::operator+;
    using Vector<TValue,2>::operator-;
    using Vector<TValue,2>::operator*;
    using Vector<TValue,2>::operator/;
    using Vector<TValue,2>::operator==;
    using Vector<TValue,2>::operator!=;

    TValue& x(void);
    TValue& y(void);
    TValue getX(void) const;
    TValue getY(void) const;

};

#endif // VECT2D_HPP_INCLUDED
