#pragma once
class Vector3D
{
public:
	double x, y, z;
	Vector3D() : x(0), y(0), z(0) {};
	Vector3D(double X, double Y, double Z) : x(X), y(Y), z(Z) {};

	void Normalize();
	double module() const;

	double dotProduct(Vector3D const& vec) const;
	Vector3D scalarProduct(double scalar) const;

	void operator=(Vector3D const& other);
	static Vector3D operator+(Vector3D const& v1, Vector3D const& v2);
	static Vector3D operator-(Vector3D const& v1, Vector3D const& v2);
	static double operator*(Vector3D const& v1, Vector3D const& v2);

private:
};

