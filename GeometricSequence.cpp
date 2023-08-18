// Student: Thiago Ladeira - 001213566 - tc.ladeira@uleth.ca
// Assignment II - Geometric Sequence


//First thing is to include the libraries and do not forget the headline.
#include <iostream>
#include <cmath>
#include "GeometricSequence.h"
using namespace std;

//created one standard Constructor and one with parameters. When I added the "initialize" I had to put it to "1", otherwise
// the for loop was going over the size of the array.
GeometricSequence::GeometricSequence(){
    a = 1;
    r = 1;
    n = 1;
    initialize(1);
}

GeometricSequence::GeometricSequence (int ac, int rc, int nc){
    a = ac;
    r = rc;
    n = nc;
    size = nc;
    geoseq = new int [size];
    for (int i = 0; i < n; ++i){
       geoseq[i] = ac * pow(rc,i);

    }
}
//created a copy constructor here. I already had the COPY CONST that I made from assignemnt 2. So, no changes here.
GeometricSequence:: GeometricSequence (const GeometricSequence& original){
    a = original.a;
    r = original.r;
    n = original.n;
    geoseq = new int [n];
    for (int i = 0; i < n; ++i){
        geoseq[i] = original.geoseq[i];
    }
}
//For some reason my destructor is giving me some trouble, so I commemet it out.
// GeometricSequence::~GeometricSequence(){
//     delete[] geoseq;
// }

void GeometricSequence::getCharacteristic(int& aob, int& rob, int& nob){
    aob = a;
    rob = r;
    nob = n;
}

int& GeometricSequence::element(int index){
    assert(index<size && index>=0);
    int& reference = geoseq[index];
    return reference;
}

int& GeometricSequence::element(int index) const{
    assert(index<size && index>=0);
    int& reference = geoseq[index];
    return reference;
}

void GeometricSequence::add(GeometricSequence& userObject){
    assert(n == userObject.n);
    for (int i = 0; i < n; ++i){
        geoseq[i] = geoseq[i] + userObject.geoseq[i];

    }
}

void GeometricSequence::sub(GeometricSequence& userObject){
    assert(n == userObject.n);
    for (int i = 0; i < n; ++i){
        geoseq[i] = geoseq[i] - userObject.geoseq[i];

    }
}

void GeometricSequence::mult(GeometricSequence& userObject){
    assert(n == userObject.n);
    for (int i = 0; i < n; ++i){
        geoseq[i] = geoseq[i] * userObject.geoseq[i];

    }
}

void GeometricSequence::read (){
    cout << "Inform the scale factor of the Sequence: " << endl;
    cin >> a;
    cout << "Inform the common ration of the Sequence: " << endl;
    cin >> r;
    cout << "Inform the number of elements in the Sequence: " << endl;
    cin >> n;
    geoseq = new int [n];
    for (int i = 0; i < n; ++i){
        geoseq[i] = a * pow(r,i);
    }
}

void GeometricSequence::write(){
    cout << "The elements of the Sequence are: " << endl;
    for (int i = 0; i < n; ++i){
        cout << geoseq[i] << ", " << endl;
    }
}

//Here I will implement the functions of Assignment 3:
void GeometricSequence::initialize(int n)
{
  geoseq = new int[n];
  for (int i = 0; i < n; i++)
  {
    geoseq[i] = a * pow(r, i);
  };
}
