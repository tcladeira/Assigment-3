// Student: Thiago Ladeira - 001213566 - tc.ladeira@uleth.ca
// Assignment III - Geometric Sequence


//First thing is to include the libraries and do not forget the headline.
#include <iostream>
#include <cmath>
#include <string>
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
//Comments on Assignment 3: this is still breaking my code. No idea what might be. Just going to leave it as a comment so the code can run.


// GeometricSequence::~GeometricSequence(){
//     delete[] geoseq;
// }


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

//All new fucntions that I just added. Have to fix them all!:


int GeometricSequence::operator()(int index){
  assert(index < n && index >= 0);
  return geoseq[index];
}

//had to change the "getCharacteristics" function to use "this" element. Without it, I was geting lost with the names
//of the different objects elements (aob, rob, nob) everywhere.
void GeometricSequence::getCharacteristics(int &a, int &r, int &n) const{
  a = this->a;
  r = this->r;
  n = this->n;
}

const int &GeometricSequence::element(int index) const{
  assert(index < n && index >= 0);
  return geoseq[index];
}


int &GeometricSequence::element(int index)
{
  assert(index < n && index >= 0);
  return geoseq[index];
}

std::string GeometricSequence::getString() const
{
  std::string objText = "[";
  for (int i = 0; i < n; i++)
  {
    objText += std::to_string(geoseq[i]);
    objText += (i == (n - 1) ? "" : ", ");
  }
  objText += "]";
  return objText;
}

std::ostream &operator<<(std::ostream &stream, const GeometricSequence &obj)
{
  stream << obj.getString();
  return stream;
}

std::istream &operator>>(std::istream &stream, GeometricSequence &obj)
{
  int a, r, n;
  std::cout << "a: ";
  stream >> a;
  std::cout << "r: ";
  stream >> r;
  std::cout << "n: ";
  stream >> n;

  obj.a = a;
  obj.r = r;
  obj.n = n;
  delete[] obj.geoseq;
  obj.geoseq = new int[n];
  for (int i = 0; i < n; i++)
  {
    obj.geoseq[i] = a * pow(r, i);
  };
  return stream;
}

GeometricSequence &GeometricSequence::operator+=(GeometricSequence &other)
{
  assert(n == other.n);
  for (int i = 0; i < n; i++)
  {
    geoseq[i] += other.geoseq[i];
  };
  return *this;
}

GeometricSequence &GeometricSequence::operator-=(GeometricSequence &other)
{
  assert(n == other.n);
  for (int i = 0; i < n; i++)
  {
    geoseq[i] -= other.geoseq[i];
  };
  return *this;
}

GeometricSequence &GeometricSequence::operator*=(GeometricSequence &other)
{
  assert(n == other.n);
  for (int i = 0; i < n; i++)
  {
    geoseq[i] *= other.geoseq[i];
  };
  return *this;
}

GeometricSequence GeometricSequence::operator+(const GeometricSequence &other)
{
  assert(n == other.n);
  GeometricSequence result(other);
  for (int i = 0; i < n; i++)
  {
    result.geoseq[i] = geoseq[i] + other.geoseq[i];
  };
  return result;
}

GeometricSequence GeometricSequence::operator-(const GeometricSequence &other)
{
  assert(n == other.n);
  GeometricSequence result(other);
  for (int i = 0; i < n; i++)
  {
    result.geoseq[i] = geoseq[i] - other.geoseq[i];
  };
  return result;
}

GeometricSequence GeometricSequence::operator*(const GeometricSequence &other)
{
  assert(n == other.n);
  GeometricSequence result(other);
  for (int i = 0; i < n; i++)
  {
    result.geoseq[i] = geoseq[i] * other.geoseq[i];
  };
  return result;
}
