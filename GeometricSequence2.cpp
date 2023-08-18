#include <iostream>
#include <cmath>
#include <string>
#include "GeometricSequence2.h"
using namespace std;

template <typename T>
GeometricSequence<T>::GeometricSequence()
{
  a = 1;
  r = 1;
  n = 1;
  initialize(1);
}

template <typename T>
GeometricSequence<T>::~GeometricSequence()
{
  delete[] geoseq;
}

template <typename T>
GeometricSequence<T>::GeometricSequence(const GeometricSequence &obj)
    : a(obj.a), r(obj.r), n(obj.n)
{
  geoseq = new T[n];
  for (int i = 0; i < n; i++)
  {
    geoseq[i] = obj.geoseq[i];
  };
}

template <typename T>
GeometricSequence<T> &GeometricSequence<T>::operator=(GeometricSequence<T> &obj)
{
  a = obj.a;
  r = obj.r;
  n = obj.n;
  delete[] geoseq;
  geoseq = new T[n];
  for (int i = 0; i < n; i++)
  {
    geoseq[i] = obj.geoseq[i];
  };
  return *this;
}

template <typename T>
GeometricSequence<T>::GeometricSequence(int a, int r, int n)
    : a(a), r(r), n(n)
{
  initialize(n);
}

template <typename T>
void GeometricSequence<T>::initialize(int n)
{
  geoseq = new T[n];
  for (int i = 0; i < n; i++)
  {
    geoseq[i] = a * pow(r, i);
  };
}

template <typename T>
T GeometricSequence<T>::operator()(int index)
{
  assert(index < n && index >= 0);
  return geoseq[index];
}

template <typename T>
void GeometricSequence<T>::getCharacteristics(int &a, int &r, int &n) const
{
  a = this->a;
  r = this->r;
  n = this->n;
}

template <typename T>
const T &GeometricSequence<T>::element(int index) const
{
  assert(index < n && index >= 0);
  return geoseq[index];
}

template <typename T>
T &GeometricSequence<T>::element(int index)
{
  assert(index < n && index >= 0);
  return geoseq[index];
}

template <typename T>
string GeometricSequence<T>::getString() const
{
  string objText = "[";
  for (int i = 0; i < n; i++)
  {
    objText += to_string(geoseq[i]);
    objText += (i == (n - 1) ? "" : ", ");
  }
  objText += "]";
  return objText;
}

template <typename T>
ostream &operator<<(ostream &stream, const GeometricSequence<T> &obj)
{
  stream << obj.getString();
  return stream;
}

template <typename T>
istream &operator>>(istream &stream, GeometricSequence<T> &obj)
{
  int a, r, n;
  cout << "a: ";
  stream >> a;
  cout << "r: ";
  stream >> r;
  cout << "n: ";
  stream >> n;

  obj.a = a;
  obj.r = r;
  obj.n = n;
  delete[] obj.geoseq;
  obj.geoseq = new T[n];
  for (int i = 0; i < n; i++)
  {
    obj.geoseq[i] = a * pow(r, i);
  };
  return stream;
}

template <typename T>
GeometricSequence<T> &GeometricSequence<T>::operator+=(GeometricSequence<T> &other)
{
  assert(n == other.n);
  for (int i = 0; i < n; i++)
  {
    geoseq[i] += other.geoseq[i];
  };
  return *this;
}

template <typename T>
GeometricSequence<T> &GeometricSequence<T>::operator-=(GeometricSequence<T> &other)
{
  assert(n == other.n);
  for (int i = 0; i < n; i++)
  {
    geoseq[i] -= other.geoseq[i];
  };
  return *this;
}

template <typename T>
GeometricSequence<T> &GeometricSequence<T>::operator*=(GeometricSequence<T> &other)
{
  assert(n == other.n);
  for (int i = 0; i < n; i++)
  {
    geoseq[i] *= other.geoseq[i];
  };
  return *this;
}

template <typename T>
GeometricSequence<T> GeometricSequence<T>::operator+(const GeometricSequence<T> &other)
{
  assert(n == other.n);
  GeometricSequence<T> result(other);
  for (int i = 0; i < n; i++)
  {
    result.geoseq[i] = geoseq[i] + other.geoseq[i];
  };
  return result;
}

template <typename T>
GeometricSequence<T> GeometricSequence<T>::operator-(const GeometricSequence<T> &other)
{
  assert(n == other.n);
  GeometricSequence<T> result(other);
  for (int i = 0; i < n; i++)
  {
    result.geoseq[i] = geoseq[i] - other.geoseq[i];
  };
  return result;
}

template <typename T>
GeometricSequence<T> GeometricSequence<T>::operator*(const GeometricSequence<T> &other)
{
  assert(n == other.n);
  GeometricSequence<T> result(other);
  for (int i = 0; i < n; i++)
  {
    result.geoseq[i] = geoseq[i] * other.geoseq[i];
  };
  return result;
}

// Declaration for int. I tried to reuse the file Geometric Sequence, but there were so many errors and I was so lost, that
//I made a new file called GeometricSequence2.cpp
template class GeometricSequence<int>;
template ostream &operator<<(ostream &stream, const GeometricSequence<int> &geoseq);
template istream &operator>>(istream &stream, GeometricSequence<int> &geoseq);

// Declaration for double
template class GeometricSequence<double>;
template ostream &operator<<(ostream &stream, const GeometricSequence<double> &geoseq);
template istream &operator>>(istream &stream, GeometricSequence<double> &geoseq);