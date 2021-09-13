#include <iostream>
#include <ctime>
#include <cstdlib>
#include<unistd.h>
using namespace std;

class Matrix {
    public:
    unsigned int row;
    unsigned int column;
    int **matrix;
    
    Matrix() {}
    Matrix(unsigned int r, unsigned int c): row(r), column(c){
        //srand(time(NULL));
        matrix = new int*[r];
        for(unsigned int i=0; i<r; i++) {
            matrix[i] = new int[c];
            for(unsigned int j=0; j<c; j++) {
                this->matrix[i][j] = (rand()%10)+1;
            }
        }
    }
    
  Matrix& operator +(const Matrix& a){
       if(a.row == this->row && a.column == this->column) {
         for(unsigned int i=0; i<a.row; i++) {
            for(unsigned int j=0; j<a.column; j++) {
               this->matrix[i][j] += a.matrix[i][j];
            }
             
         }
         return *this;
       }
       else {
         printf("Niezgodne wymiary Matrixy\n");
         return *this;
       }
  }
    
    Matrix operator -(const Matrix& a){
         if(a.row == this->row && a.column == this->column) {
                for(unsigned int i=0; i<a.row; i++) {
                   for(unsigned int j=0; j<a.column; j++) {
                     this->matrix[i][j] -= a.matrix[i][j];
                   }
                }
                return *this;
         }
         else {
            printf("Niezgodne wymiary macierzy\n");
            return *this;
         }
    }
friend std::ostream& operator<<(std::ostream& out,const Matrix& m);
};

Matrix operator +(const Matrix& a, const Matrix& b){
   if(a.row == b.row && a.column == b.column) {
         Matrix c(a.row,a.column);
         for(unsigned int i=0; i<a.row; i++) {
            for(unsigned int j=0; j<a.column; j++) {
               c.matrix[i][j] = (a.matrix[i][j] + b.matrix[i][j]);
            }
         }
        return c;
   }
   else {
         printf("Niezgodne wymiary macierzy\n");
         return a;
       }
}

Matrix operator -(const Matrix& a, const Matrix& b){
   if(a.row == b.row && a.column == b.column) {
     Matrix c(a.row,a.column);
     for(unsigned int i=0; i<a.row; i++) {
        for(unsigned int j=0; j<a.column; j++) {
           c.matrix[i][j] = (a.matrix[i][j] - b.matrix[i][j])%3;
        }
     }
       return c;
   }
   else {
     printf("Niezgodne wymiary macierzy\n");
     return a;
   }
}

Matrix operator *(const Matrix& a, const int& b) {
  Matrix c(a.row,a.column);
  for(unsigned int i=0; i<a.row; i++) {
    for(unsigned int j=0; j<a.column; j++) {
     c.matrix[i][j] = a.matrix[i][j] * b;
    }
  }
    return c;
}

Matrix operator *(const int& b, const Matrix& a) {
  Matrix c(a.row,a.column);
  for(unsigned int i=0; i<a.row; i++) {
    for(unsigned int j=0; j<a.column; j++) {
     c.matrix[i][j] = a.matrix[i][j] * b;
        }
    }
    return c;
}
std::ostream& operator<<(std::ostream& out,const Matrix& m){
    out <<"{";
    for(unsigned int i=0; i<m.row-1; i++) {
     out << "{";
     for(unsigned int j=0; j<m.column-1; j++) {
       out << m.matrix[i][j] << ",";
     }
     out << m.matrix[i][m.column-1] << "},"<<endl;
    }
    out <<"{";
    for(unsigned int i=0; i<m.column-1; i++) {
out << m.matrix[m.row-1][i] << ","; }
    out << m.matrix[m.row-1][m.column-1] << "}";
    out << "}";
return out;
    
}
int main() {
  srand(time(NULL));
  Matrix a=Matrix(2,3);
  Matrix b=Matrix(2,3);
  int c = 4;
  cout << "Matrix A:" << endl;
  cout << a << endl<< endl;
  cout << "Matrix B:" << endl;

    cout << b << endl<< endl;
    cout << "Result of A + B:" << endl;
    cout << a+b << endl<< endl;

    cout << "Result of A - B:" << endl;
    cout << a-b << endl<< endl;
    cout << "Result of C * A:" << endl;
    cout << c*a << endl<< endl;
    cout << "Result of B * C:" << endl;
    cout << b*c << endl<< endl;
    
}

