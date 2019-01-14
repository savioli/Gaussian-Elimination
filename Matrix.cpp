/*
 * File:   Matrix.cpp
 * Author: André Savioli
 *
 * Created on 20 de Janeiro de 2014, 22:24
 */

#include "Matrix.h"

// Public

Matrix::Matrix() {

}

Matrix::Matrix( int numberOfRows, int numberOfColumns ) {

    this->numberOfRows = numberOfRows;

    this->numberOfColumns = numberOfColumns;

    this->initializeMatrix();

}

void Matrix::setNumberOfRows( int numberOfRows ) {

    this->numberOfRows = numberOfRows;

}

int Matrix::getNumberOfRows() {

    return this->numberOfRows;

}

void Matrix::setNumberOfColumns( int numberOfColumns ) {

    this->numberOfColumns = numberOfColumns;

}

int Matrix::getNumberOfColumns() {

    return this->numberOfColumns;

}

void Matrix::setCell( int row, int column, float value ) {

    this->matrix[ row ][ column ] = value;

}

float Matrix::getCellValue( int row, int column ) {

    return this->matrix[ row ][ column ];

}

Matrix::~Matrix() {

    for( int i = 0; i < this->numberOfRows; i++ ) {

        delete [] this->matrix[ i ];
        
    }

    delete [] this->matrix;

}

// Private

void Matrix::initializeMatrix() {

    this->matrix = new float * [ this->numberOfRows ];

    for( int i = 0; i < this->numberOfRows; i++ ) {

        this->matrix[ i ] = new float[ this->numberOfColumns ];

    }

}
