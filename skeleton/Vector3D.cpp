#include "Vector3D.h"
#include <cmath>

double
Vector3D::module() const {
	return sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

void
Vector3D::Normalize() {
	x = x / module();
	y = y / module();
	z = z / module();
}

double
Vector3D::dotProduct(Vector3D const& vec) const {
	double suma = vec.x * x;
	suma += vec.y * y;
	suma += vec.z * z;
	return suma;
}

Vector3D
Vector3D::scalarProduct(double scalar) const {
	Vector3D aux(x * scalar, y * scalar, z * scalar);
	return aux;
}

void 
Vector3D::operator=(Vector3D const& other) {
	x = other.x;
	y = other.y;
	z = other.z;
}

Vector3D 
Vector3D::operator+(Vector3D const& v1, Vector3D const& v2) {
	return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3D
Vector3D::operator-(Vector3D const& v1, Vector3D const& v2) {
	return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

double
Vector3D::operator*(Vector3D const& v1, Vector3D const& v2) {
	return v1.dotProduct(v2);
}