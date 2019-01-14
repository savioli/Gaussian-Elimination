/*
 * File:   Matrix.h
 * Author: André Savioli
 *
 * Created on 20 de Janeiro de 2014, 22:24
 */

#ifndef MATRIX_H
#define	MATRIX_H

class Matrix {

public:

    Matrix();

    Matrix( int numberOfRows, int numberOfColumns );

    void setNumberOfRows( int numberOfRows );

    void setNumberOfColumns( int numberOfColumns );

    void setCell( int row, int column, float value );

    float getCellValue( int row, int column );

    int getNumberOfRows();

    int getNumberOfColumns();

    float ** getMatrix();

    virtual ~Matrix();

private:

    int numberOfRows;

    int numberOfColumns;

    float ** matrix;

    void initializeMatrix();

};

#endif	/* MATRIX_H */
