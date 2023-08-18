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
void getCharacteristic(int& aob, int& rob, int& nob);
int& element(int index);
int& element(int index) const;
void add(GeometricSequence& userObject);
void sub(GeometricSequence& userObject);
void mult(GeometricSequence& userObject);
void read();
void write();
//here are the headlines of all functions for Assignment 3:
void initialize(int sizeOfSequenceInt);
};