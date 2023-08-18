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
string getString() const;
int operator()(int index);
//all overloaded operations:
  GeometricSequence &operator=(GeometricSequence &other);
  GeometricSequence &operator+=(GeometricSequence &other);
  GeometricSequence &operator-=(GeometricSequence &other);
  GeometricSequence &operator*=(GeometricSequence &other);
  GeometricSequence operator+(const GeometricSequence &other);
  GeometricSequence operator-(const GeometricSequence &other);
  GeometricSequence operator*(const GeometricSequence &other);
//using friend to allow ">>" to be overloaded
  friend istream &operator>>(istream &stream, GeometricSequence &obj);
};

ostream &operator<<(ostream &stream, const GeometricSequence &obj);
istream &operator>>(istream &stream, GeometricSequence &obj);