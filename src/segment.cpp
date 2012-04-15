#include <iostream>
#include "segment.hpp"

Segment::Segment(void)
{

}

Segment::Segment(TValue _x1, TValue _y1, TValue _x2, TValue _y2)
 : pt1(_x1,_y1), pt2(_x2,_y2)
{
    updateNormalVector();
}

Segment::Segment(const Vect2D& vect1, const Vect2D& vect2)
 : pt1(vect1), pt2(vect2)
{
    updateNormalVector();

}

TValue Segment::getX1(void) const { return pt1.getX(); }
TValue Segment::getX2(void) const { return pt2.getX(); }
TValue Segment::getY1(void) const { return pt1.getY(); }
TValue Segment::getY2(void) const { return pt2.getY(); }

const Vect2D& Segment::getPt1(void) const {return pt1;}
const Vect2D& Segment::getPt2(void) const {return pt2;}
const Vect2D& Segment::getNormalVector(void) const {return n;}

TValue Segment::length(void) const
{
    return sqrt( (pt2.getX() - pt1.getX())*(pt2.getX() - pt1.getX()) + (pt2.getY() - pt1.getY())*(pt2.getY() - pt1.getY()) );
}


TValue Segment::distSeg(const Vect2D& v) const
{

    if((pt2-pt1).scalarProd(v-pt1) * (pt2-pt1).scalarProd(v-pt2) > 0)
        return min((v-pt1).norm(),(v-pt2).norm());
    else
    {
        Vect2D proj = v - pt1;
        return proj.scalarProd(n);
    }
}


Vect2D Segment::getPtSeg(TValue alp) const
{
    return Vect2D((1-alp)*pt1 + alp*pt2);
}

Vect2D Segment::getCenter(void) const
{
    return getPtSeg(0.5);
}

void Segment::updateNormalVector(void)
{
    TValue d = length();
    n.x() = - (pt2.y() - pt1.y())/d;
    n.y() =   (pt2.x() - pt1.x())/d;
}

Segment Segment::getInterval(const Segment& seg)
{
    return Segment(pt2,seg.pt1);
}

void Segment::setPt1(const Vect2D& pt)
{
    pt1 = pt;
    updateNormalVector();
}

void Segment::setPt2(const Vect2D& pt)
{
    pt2 = pt;
    updateNormalVector();
}

void Segment::setLink1(const Segment& seg)
{
    pt1 = seg.pt2;
    updateNormalVector();
}

void Segment::setLink2(const Segment& seg)
{
    pt2 = seg.pt1;
    updateNormalVector();
}

void Segment::operator<<(const Segment& seg)
{
    pt2 = seg.pt1;
    updateNormalVector();
}

void Segment::operator>>(const Segment& seg)
{
    pt1 = seg.pt2;
    updateNormalVector();
}


Segment& Segment::operator*=(TValue s)
{
    pt2.x() += (pt2.x() - pt1.x())*s;
    pt2.y() += (pt2.y() - pt1.y())*s;
    return *this;
}

Segment& Segment::operator/=(TValue s)
{
    pt2.x() += (pt2.x() - pt1.x())/s;
    pt2.y() += (pt2.y() - pt1.y())/s;
    return *this;
}




bool Segment::intersection( const Segment& s1,double& x, double& y)
{
    float denom  = ((s1.pt2.getX() - s1.pt1.getX())*(pt2.getY() - pt1.getY())) - ((s1.pt2.getY() - s1.pt1.getY())*(pt2.getX() - pt1.getX()));

    if (denom == 0.0) return false;

    float r = ((s1.pt1.getY() - pt1.getY())*(pt2.getX() - pt1.getX())) - ((s1.pt1.getX() - pt1.getX())*(pt2.getY() - pt1.getY())) / denom;
    float s = ((s1.pt1.getY() - pt1.getY())*(s1.pt2.getX() - s1.pt1.getX())) - ((s1.pt1.getX() - pt1.getX())*(s1.pt2.getY() - s1.pt1.getY())) / denom;

    if (r < 0.0 | r > 1.0 | s < 0.0 | s > 1.0) return false;
    else
    {
        x = pt1.getX() + s * (pt2.getX() - pt1.getX());
        y = pt1.getY() + s * (pt2.getY() - pt1.getY());
        return true;
    }
}

bool Segment::intersection( const Segment& s1)
{
    float denom  = ((s1.pt2.getX() - s1.pt1.getX())*(pt2.getY() - pt1.getY())) - ((s1.pt2.getY() - s1.pt1.getY())*(pt2.getX() - pt1.getX()));

    if (denom == 0.0) return false;

    float r = ((s1.pt1.getY() - pt1.getY())*(pt2.getX() - pt1.getX())) - ((s1.pt1.getX() - pt1.getX())*(pt2.getY() - pt1.getY())) / denom;
    float s = ((s1.pt1.getY() - pt1.getY())*(s1.pt2.getX() - s1.pt1.getX())) - ((s1.pt1.getX() - pt1.getX())*(s1.pt2.getY() - s1.pt1.getY())) / denom;

    if (r < 0.0 | r > 1.0 | s < 0.0 | s > 1.0) return false;
    else return true;
}
