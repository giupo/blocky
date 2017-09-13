#ifndef __FIELD__
#define __FIELD__

#define NUM_ROWS 22
#define NUM_COLS 10

class Matrix {
public:

  Matrix(): xdim_(0), ydim_(0) {}
  
  Matrix(const unsigned int xdim, const unsigned int ydim): xdim_(xdim), ydim_(ydim) {
    this->arr = new int[xdim * ydim];
    for(int i=0; i< xdim * ydim; i++) {
      this->arr[i] = 0;
    }
  }
  
  int& row_at(const int row_num) const {
    return this->arr[row_num * xdim_];
  }
  
  int* at(int x, int y) {
    return &this->arr[y * xdim_ + x];
  }
  
  ~Matrix() {
    delete[] arr;
  }
  
private:
  int* arr;
  unsigned int xdim_;
  unsigned int ydim_;
};

class Field {
public:
  Field() {
    matrix = new Matrix(NUM_ROWS, NUM_COLS);
  }

  Field(int x, int y) {
    matrix = new Matrix(x, y);
  }
  
  virtual ~Field() {
    delete matrix;
  }
  
  Matrix* matrix;
};

#endif
