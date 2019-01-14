/*
 * File:   GaussianElimination.cpp
 * Author: André Savioli
 *
 * Created on 20 de Janeiro de 2014, 22:24
 */

#include <cmath>
#include "GaussianElimination.h"

using namespace std;

// Public

GaussianElimination::GaussianElimination() {

}

GaussianElimination::GaussianElimination( Matrix * matrix ) {

    this->originalMatrix = matrix;

    this->m = matrix->getNumberOfRows();

    this->n = matrix->getNumberOfColumns();

    this->linearSystemResult = new float [ this->m ];

    this->isComputed = false;

    this->initializeMatrix();

}

void GaussianElimination::perform() {

    this->performForwardElimination();

    // Solve Ux = b

    this->performBackSubstitution();

    this->isComputed = true;

}

GaussianElimination::~GaussianElimination() {

    for( int i = 0; i < this->m; i++ ) {

        delete [] this->computationMatrix[ i ];
        
    }

    delete [] this->computationMatrix;

}

// Private

void GaussianElimination::initializeMatrix() {

    this->computationMatrix = new float * [ this->m ];

    for( int i = 0; i < this->m; i++ ) {

        this->computationMatrix[ i ] = new float[ this->n ];

    }

    for( int i = 0; i < this->originalMatrix->getNumberOfRows(); i++ ) {
        
        for( int j = 0; j < this->originalMatrix->getNumberOfColumns(); j++ ) {
            
            this->computationMatrix[ i ][ j ] = this->originalMatrix->getCellValue( i, j );

        }

    }

}

void GaussianElimination::setMatrix( Matrix * matrix ) {

    this->originalMatrix = matrix;

    this->m = matrix->getNumberOfRows();

    this->n = matrix->getNumberOfColumns();

    this->isComputed = false;

    this->initializeMatrix();

}

Matrix * GaussianElimination::getOriginalMatrix() {

    return this->originalMatrix;

}

Matrix * GaussianElimination::getComputationMatrix() {

    Matrix * computationMatrix = new Matrix( this->m, this->n );

    for( int i = 0; i < computationMatrix->getNumberOfRows(); i++ ) {

        for( int j = 0; j < computationMatrix->getNumberOfColumns(); j++ ) {

            computationMatrix->setCell( i, j, this->computationMatrix[ i ][ j ] );

        }

    }

    return computationMatrix;

}

float * GaussianElimination::getLinearSystemSolution() {

    float * result = new float [ this->m ];

    for( int i = 0; i < this->m; i++ ) {

        result[ i ] = this->computationMatrix[ i ][ this->n - 1 ];

    }

    return result;

}

void GaussianElimination::performBackSubstitution() {

    float r;

    for( int k = this->m - 1; k >= 0; k-- ) {

        r = this->computationMatrix[ k ][ this->n - 1 ];

        for( int j = this->n - 2; j >= 0; j-- ) {

            if( k == j ) {

                r = r / this->computationMatrix[ k ][ j ];

                this->computationMatrix[ k ][ this->n - 1 ] = r;

                for( int i = k - 1; i >= 0; i-- ) {

                    this->computationMatrix[ i ][ j ] = this->computationMatrix[ i ][ j ] * r;

                }

                this->computationMatrix[ k ][ j ] = 1;

                break;

            } else {

                r = r - this->computationMatrix[ k ][ j ];

                this->computationMatrix[ k ][ j ] = 0;

            }

        }

        this->computationMatrix[ k ][ this->n - 1 ] = r;

    }

}

void GaussianElimination::performForwardElimination() {

    this->operationLine = 0;

    this->operationColumn = 0;

    float m = 0;

    for( int k = this->operationLine + 1; k < this->m; k++ ) {

        this->performPivotation();

        m = 0;

        for( int i = this->operationLine + 1; i < this->m; i++ ) {

            m = this->computationMatrix [ i ] [ this->operationColumn ] / this->computationMatrix[ this->operationLine ] [ this->operationColumn ];

            for( int j = this->operationColumn; j < this->n; j++ )
                this->computationMatrix [ i ] [ j ] = this->computationMatrix [ i ] [ j ] - ( m * this->computationMatrix [ this->operationLine ] [ j ] );

        }

        this->operationLine++;

        this->operationColumn++;


    }

    this->operationLine = 0;

    this->operationColumn = 0;

}

void GaussianElimination::performPivotation() {

    float value = abs( this->computationMatrix[ this->operationLine ][ this->operationColumn ] );

    int swapLine = this->operationLine;

    for( int k = this->operationLine + 1; k < this->m ; k++ ) {

        if( abs( this->computationMatrix[ k ][ this->operationColumn ] ) > value ) {

            swapLine = k;

            value = abs( this->computationMatrix[ k ][ this->operationColumn ] );

        }

    }

    if( this->operationLine != swapLine )
        this->performSwapRow( this->operationLine, swapLine );

}

void GaussianElimination::performSwapRow( int a, int b ) {

    float aux;

    for( int k = this->operationColumn; k < this->n; k++ ) {

        aux = this->computationMatrix[ a ][ k ];

        this->computationMatrix[ a ][ k ] = this->computationMatrix[ b ][ k ];

        this->computationMatrix[ b ][ k ] = aux;

    }

}
