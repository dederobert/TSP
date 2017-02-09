#pragma once
#include <string>
using namespace std;

template <classT>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}

class Vector2D
{
public:
	double x, y;

	inline explicit Vector2D(const double & x = 0, const double & y = 0);

	/**
	* DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	*
	* */
	inline Vector2D(const char * s);
	inline const Vector2D operator + (const Vector2D & u) const;
	inline const Vector2D operator * (const double & a) const;
	/**
	* - unaire (c'est-à- dire opposé d'un vecteur)
	* */
	inline const Vector2D operator - () const;
	inline operator string() const;
};

ostream& operator<<(ostream& f, const Vector2D& vector);