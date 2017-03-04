#pragma once
#include "Vector2D.h"
/**
	* Inline function norme <br />
	* @param Vector2D vector
	*/
inline double norme(const Vector2D& A, const Vector2D& B) {
	return sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y),2));
}
