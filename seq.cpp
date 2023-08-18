// Student: Thiago Ladeira - 001213566 - tc.ladeira@uleth.ca
// Assignment II - Geometric Sequence

#include<iostream>
#include<cmath>
#include"GeometricSequence.h"

using namespace std;

int main(){

    GeometricSequence A, B, C;
    int a;
    int r;
    int n;

//Creating the sequences A, B and C.
    cout << "Informe the values for sequence A: " << endl;
    A.read();
    A.write();
    cout << "Informe the values for sequence B: " << endl;
    B.read();
    B.write();
    cout << "Informe the values for sequence C: " << endl;
    C.read();
    C.write();

//Set D to be a sequence equal to A, but with -r.
    A.getCharacteristics(a, r, n);
    GeometricSequence D(a, -r, n);
    D.write();

    cout << "Geometric Sequency D: " << D << endl;

    //New command lines for the Assignment 3. Using overloading operations instead of the regular ones.
    // (c) Computes and displays the following results:
    //  • A+B

  GeometricSequence result1 = A + B;
  cout << "• A+B: " << result1 << endl;

  //  • A×C−B
  GeometricSequence result2 = A * C - B;
  cout << "• AxC-B: " << result2 << endl;

  //  • (A+D)×C
  GeometricSequence result3 = (A + D) * C;
  cout << "• (A+D)xC: " << result3 << endl;



cout << "End of Program";

    return 0;
}