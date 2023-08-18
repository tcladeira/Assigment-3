#pragma once
using namespace std;

template <typename T>
class GeometricSequence
{
private:
  int a;
  int r;
  int n;
  T *geoseq;
  void initialize(int n);

public:
  GeometricSequence();
  GeometricSequence(int a, int r, int n);
  GeometricSequence(const GeometricSequence &obj);
  ~GeometricSequence();
  void getCharacteristics(int &a, int &r, int &n) const;
  T &element(int index);
  const T &element(int index) const;
  string getString() const;
  T operator()(int index);
  GeometricSequence &operator=(GeometricSequence &obj);
  GeometricSequence &operator+=(GeometricSequence &other);
  GeometricSequence &operator-=(GeometricSequence &other);
  GeometricSequence &operator*=(GeometricSequence &other);
  GeometricSequence operator+(const GeometricSequence &other);
  GeometricSequence operator-(const GeometricSequence &other);
  GeometricSequence operator*(const GeometricSequence &other);

//for some reason I had to use U instead of T here. I have not a clue of why, but that was the only thing that helped.
  template <typename U>
  friend istream &operator>>(istream &stream, GeometricSequence<U> &obj);
};

template <typename T>
ostream &operator<<(ostream &stream, const GeometricSequence<T> &obj);

template <typename T>
istream &operator>>(istream &stream, GeometricSequence<T> &obj);