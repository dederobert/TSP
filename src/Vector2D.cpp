#pragma once
#include "Vector2D.h"
#include <sstream>
inline const Vector2D operator *(const double & a, const Vector2D & u) { return u*a; }

//------------ implémentation des fonctions inline ----------------------


inline const Vector2D Vector2D::operator + (const Vector2D & u) const
{
	return Vector2D(x + u.x, y + u.y);
}

inline const Vector2D Vector2D::operator * (const double & a) const
{
	return Vector2D(x*a, y*a);
}

inline const Vector2D Vector2D::operator - () const
{
	return Vector2D(-x, -y);
}

Vector2D::operator string() const {
	ostringstream os;
	os << "( " << x << ", " << y << ")";
	return os.str();
}

ostream & operator << (ostream & os, const Vector2D & u)
{
	os << (string)u;
	return os;
}