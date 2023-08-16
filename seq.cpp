// Student: Thiago Ladeira - 001213566 - tc.ladeira@uleth.ca
// Assignment II - Geometric Sequence

#include<iostream>
#include<cmath>
#include"GeometricSequence.h"

using namespace std;

int main(){

    GeometricSequence A, B, C;
    int aob;
    int rob;
    int nob;
    int size;
    int* sequenceArr;

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
    A.getCharacteristic(aob, rob, nob);
    GeometricSequence D(aob, -rob, nob);
    D.write();

//Adding A + B and priting.
    GeometricSequence result1 = A;
    result1.add(B);
    cout << "A + B = ";
    result1.write();
//Multiplying AxC and Subtracting B:
    GeometricSequence result2 = A;
    result2.mult(C);
    result2.sub(B);
    cout << "A x C - B = ";
    result2.write();

    GeometricSequence result3 = A;
    result3.add(D);
    result3.mult(C);
    cout << "(A+D) x C = ";
    result3.write();

//New things for assignment 3:
    A.initialize();
    A.write();


    cout << "End of Program";

    return 0;
}