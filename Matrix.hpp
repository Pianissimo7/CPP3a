#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

namespace zich {
    class Matrix {
        public:
            
            Matrix(const std::vector<double>& values, int height, int width);
            
            //+++++++++++++++++++++++++++++++++++++++
            // mat + mat
            friend Matrix operator+(Matrix lMat, const Matrix& rMat);
            // mat + int
            friend Matrix operator+(Matrix lMat, const int& num);
            // int + mat
            friend Matrix operator+(int num, const Matrix& lMat);
            // += operator
            Matrix& operator+=(const Matrix& rMat);
            // += operator
            Matrix& operator+=(const int& num);
            // unary + operator
            Matrix& operator+();
            // ++mat
            Matrix& operator++();
            // mat++
            Matrix operator++(int);
            
            //----------------------------------------
            // mat - mat
            friend Matrix operator-(Matrix lMat, const Matrix& rMat);
            // mat - int
            friend Matrix operator-(Matrix lMat, const int& num);
            // int - mat
            friend Matrix operator-(int num, const Matrix& lMat);
            // -= operator
            Matrix& operator-=(const Matrix& rMat);
            // -= operator
            Matrix& operator-=(const int& num);
            // unary - operator
            friend Matrix operator-(Matrix mat);
            // --mat
            Matrix& operator--();
            // mat--
            Matrix operator--(int);
            
            //****************************************
            // mat * mat
            friend Matrix operator*(Matrix lMat, const Matrix& rMat);
            // mat * scalar
            friend Matrix operator*(Matrix lMat, double scalar);
            // mat * int
            friend Matrix operator*(Matrix lMat, const int& num);
            // int * mat
            friend Matrix operator*(int num, const Matrix& lMat);
            // scalar * mat
            friend Matrix operator*(double scalar,Matrix rMat);
            // *=
            Matrix& operator*=(double scalar);
            // *=
            Matrix& operator*=(const Matrix& rMat);
            
            ////////////////////////////////////////////
            // mat / mat
            friend Matrix operator/(Matrix lMat, const Matrix& rMat);
            // mat / scalar
            friend Matrix operator/(Matrix lMat, double scalar);
            // mat / int
            friend Matrix operator/(Matrix lMat, const int& num);
            // int / mat
            friend Matrix operator/(int num, const Matrix& lMat);
            // scalar / mat
            friend Matrix operator/(double scalar,Matrix rMat);
            // /=
            Matrix& operator/=(double scalar);
            // /=
            Matrix& operator/=(const Matrix& rMat);

            //<><><><><><><><><><><><><><><><><><><><>
            // <<
            friend std::ostream& operator<<(std::ostream& output, const Matrix& mat);
            // >>
            friend std::istream& operator>>(std::istream& input, Matrix& mat);
            
            //========================================
            // relations between matrixes
            bool operator<(const Matrix& rMat) const;
            bool operator<=(const Matrix& rMat) const;
            bool operator>(const Matrix& rMat) const;
            bool operator>=(const Matrix& rMat) const;
            bool operator==(const Matrix& rMat) const;
            bool operator!=(const Matrix& rMat) const;           
            
        private:
            
    };
}