// Student: Thiago Ladeira - 001213566 - tc.ladeira@uleth.ca
// Assignment III - Geometric Sequence

#include<iostream>
#include<cmath>
#include"GeometricSequence2.h"
#include<string>

using namespace std;

int main(){

    GeometricSequence<double> A, B, C;
    int a;
    int r;
    int n;

//Creating the sequences A, B and C.
    cout << "Informe the values for sequence A: " << endl;
    cin >> A;
    cout << A << endl;
    cout << "Informe the values for sequence B: " << endl;
    cin >> B;
    cout << B << endl;
    cout << "Informe the values for sequence C: " << endl;
    cin >> C;
    cout << C << endl;

//Set D to be a sequence equal to A, but with -r.
    A.getCharacteristics(a, r, n);
    GeometricSequence<double> D(a, -r, n);


    cout << "Geometric Sequency D: " << D << endl;

    //New command lines for the Assignment 3. Using overloading operations instead of the regular ones.
    // (c) Computes and displays the following results:
    //  • A+B

  GeometricSequence<double> result1 = A + B;
  cout << "• A+B: " << result1 << endl;

  //  • A×C−B
  GeometricSequence<double> result2 = A * C - B;
  cout << "• AxC-B: " << result2 << endl;

  //  • (A+D)×C
  GeometricSequence<double> result3 = (A + D) * C;
  cout << "• (A+D)xC: " << result3 << endl;



cout << "End of Program";

    return 0;
}