/*
 * File:   GaussianElimination.h
 * Author: André Savioli
 *
 * Created on 20 de Janeiro de 2014, 22:24
 */

#ifndef GAUSSIAN_ELIMINATION_H
#define	GAUSSIAN_ELIMINATION_H

#include "Matrix.h"

class GaussianElimination {

public:

    GaussianElimination();

    GaussianElimination( Matrix * matrix );

    void setMatrix( Matrix * matrix );

    void perform();

    Matrix * getOriginalMatrix();

    Matrix * getComputationMatrix();

    float * getLinearSystemSolution();

    virtual ~GaussianElimination();

private:

    bool isComputed;

    // Number of Rows of the Computation Matrix

    int m;

    // Number of Columns of the Computation Matrix
    
    int n;

    Matrix * originalMatrix;

    float ** computationMatrix;

    float * linearSystemResult;

    int operationLine;

    int operationColumn;

    void initializeMatrix();

    void performForwardElimination();

    void performBackSubstitution();

    void performPivotation();

    void performSwapRow( int a, int b );

};

#endif	/* GAUSSIAN_ELIMINATION_H */
