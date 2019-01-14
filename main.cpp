/*
 * File:   main.cpp
 * Author: André Savioli
 *
 * Created on 20 de Janeiro de 2014, 22:24
 */

#include <cstdlib>
#include <iostream>

#include "GaussianElimination.h"

using namespace std;

int main( int argc, char** argv ) {

    // Gaussian Elimination
    // Forward Elimitation - Back Substitution

    cout << endl << "Gaussian Elimination With Forward Elimination and Back Substitution" << endl << endl;

    /**
    *   Example System 1:
    *
    *    1,0 x1 + 2,0 x2 - 1,0 x3 + 0,0 x4 = -4
    *    0,0 x1 - 1,0 x2 + 1,0 x3 - 1,0 x4 =  0
    *   -2,0 x1 - 1,0 x2 + 4,0 x3 + 2,0 x4 =  7
    *    4,0 x1 + 3,0 x2 + 0,0 x3 + 1,0 x4 = -10
    *
    *   Solution:
    *
    *   x1 = -2
    *   x2 = -1
    *   x3 =  0
    *   x4 =  1
    *
    */

    Matrix * matrixA = new Matrix( 4, 5 );

    matrixA->setCell( 0, 0,  1 );
    matrixA->setCell( 0, 1,  2 );
    matrixA->setCell( 0, 2, -1 );
    matrixA->setCell( 0, 3,  0 );
    matrixA->setCell( 0, 4, -4 );

    matrixA->setCell( 1, 0,  0 );
    matrixA->setCell( 1, 1, -1 );
    matrixA->setCell( 1, 2,  1 );
    matrixA->setCell( 1, 3, -1 );
    matrixA->setCell( 1, 4,  0 );

    matrixA->setCell( 2, 0, -2 );
    matrixA->setCell( 2, 1, -1 );
    matrixA->setCell( 2, 2,  4 );
    matrixA->setCell( 2, 3,  2 );
    matrixA->setCell( 2, 4,  7 );

    matrixA->setCell( 3, 0,  4 );
    matrixA->setCell( 3, 1,  3 );
    matrixA->setCell( 3, 2,  0 );
    matrixA->setCell( 3, 3,  1 );
    matrixA->setCell( 3, 4, -10 );

    /**
    *   Example System 2:
    *
    *     1,0 x1 - 1,0 x2 + 2,0 x3 = 2
    *     2,0 x1 + 2,0 x2 - 1,0 x3 = 0
    *   - 2,0 x1 - 5,0 x2 + 3,0 x3 = 3
    *
    *   Solution:
    *
    *   x1 =  1
    *   x2 = -1
    *   x3 =  0
    *
    */

    // Matrix * matrixA = new Matrix( 3, 4 );

    // matrixA->setCell( 0, 0,  1 );
    // matrixA->setCell( 0, 1, -1 );
    // matrixA->setCell( 0, 2,  2 );
    // matrixA->setCell( 0, 3,  2 );

    // matrixA->setCell( 1, 0,  2 );
    // matrixA->setCell( 1, 1,  2 );
    // matrixA->setCell( 1, 2, -1 );
    // matrixA->setCell( 1, 3,  0 );

    // matrixA->setCell( 2, 0, -2 );
    // matrixA->setCell( 2, 1, -5 );
    // matrixA->setCell( 2, 2,  3 );
    // matrixA->setCell( 2, 3,  3 );

    /**
    *   Example System 3:
    *
    *   5,0 x1 + 1,0 x2 - 2,0 x3 = 10
    *   3,0 x1 - 9,4 x2 + 1,8 x3 = 22
    *   1,0 x1 + 2,2 x2 + 4,6 x3 = 10
    *
    *   Solution:
    *
    *   x1 =  3
    *   x2 = -1
    *   x3 =  2
    *
    */

    // Matrix * matrixA = new Matrix( 3, 4 );

    // matrixA->setCell( 0, 0,  5 );
    // matrixA->setCell( 0, 1,  1 );
    // matrixA->setCell( 0, 2, -2 );
    // matrixA->setCell( 0, 3,  10 );

    // matrixA->setCell( 1, 0,  3 );
    // matrixA->setCell( 1, 1, -9.4 );
    // matrixA->setCell( 1, 2,  1.8 );
    // matrixA->setCell( 1, 3,  22 );

    // matrixA->setCell( 2, 0, 1 );
    // matrixA->setCell( 2, 1, 2.2 );
    // matrixA->setCell( 2, 2, 4.6 );
    // matrixA->setCell( 2, 3, 10 );

    GaussianElimination * ge = new GaussianElimination( matrixA );

    cout << "System Matrix" << endl << endl;
    
    for( int i = 0; i < matrixA->getNumberOfRows(); i++ ) {

        for( int j = 0; j < matrixA->getNumberOfColumns(); j++ ){

            cout << matrixA->getCellValue( i, j ) << " ";

        }

        cout << endl;

    }

    // Perform the gaussian elimination over matrixA

    ge->perform();

    cout << endl << "Solution of Ux = b" << endl << endl;

    // Get the result of linear system

    float * solution = ge->getLinearSystemSolution();

    for( int i = 0; i < matrixA->getNumberOfRows(); i++ ) {
    
        cout << "x" << i << " = " << solution[ i ] << endl;

    }

    cout << endl << "Computation Matrix" << endl << endl;

    // Get the matrix used to perform the Gaussian Elimination

    Matrix * computationMatrix = ge->getComputationMatrix();

    for( int i = 0; i < computationMatrix->getNumberOfRows(); i++ ) {

        for( int j = 0; j < computationMatrix->getNumberOfColumns(); j++ ) {

            cout << computationMatrix->getCellValue( i, j ) << " ";

        }

        cout << endl;

    }

    cout << endl << endl;

    delete ge;

    delete matrixA;

    delete computationMatrix;

    delete solution;

    return 0;

}
