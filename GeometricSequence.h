// Student: Thiago Ladeira - 001213566 - tc.ladeira@uleth.ca
// Assignment II - Geometric Sequence 

#pragma once

class GeometricSequence{
private:
    int a;
    int r;
    int n;
    int size;
    int* geoseq;

public:
GeometricSequence();
GeometricSequence (int ac, int rc, int nc);
GeometricSequence (const GeometricSequence& original);
// ~GeometricSequence();
void getCharacteristics(int &a, int &r, int &n) const;

//deleted the former "element" functions.
void add(GeometricSequence& userObject);
void sub(GeometricSequence& userObject);
void mult(GeometricSequence& userObject);
void read();
void write();

//here are the headlines of all functions for Assignment 3:
void initialize(int sizeOfSequenceInt);

//the revised "element" functions:
const int &element(int index) const;
int &element(int index);
  std::string getString() const;
  int operator()(int index);
  GeometricSequence &operator=(GeometricSequence &other);
  GeometricSequence &operator+=(GeometricSequence &other);
  GeometricSequence &operator-=(GeometricSequence &other);
  GeometricSequence &operator*=(GeometricSequence &other);
  GeometricSequence operator+(const GeometricSequence &other);
  GeometricSequence operator-(const GeometricSequence &other);
  GeometricSequence operator*(const GeometricSequence &other);

  friend std::istream &operator>>(std::istream &stream, GeometricSequence &obj);
};

std::ostream &operator<<(std::ostream &stream, const GeometricSequence &obj);
std::istream &operator>>(std::istream &stream, GeometricSequence &obj);