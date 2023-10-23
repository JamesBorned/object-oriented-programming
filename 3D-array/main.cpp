/*The laboratory work №3
 * Создать шаблонный класс Array3D, который внутри хранит одномерный массив, но
 * несмотря на это является трёхмерным.
 * Array3D(int dim0, int dim1, int dim2)
 * Методы:
 * 1) Индексатор [][][];
 * 2) Метод GetValues0(int i): (.., .., ..) => (i, .., ..)
 *     GetValues1(int j): (.., .., ..) => (.., j, ..)
 *     GetValues2(int k): (.., .., ..) => (.., .., k)
 * 3) GetValues01(int i, int j): (.., .., ..) => (i, j, ..)
 *     GetValues02, GetValues12
 * 4) SetValues0(int i, [][]), SetValues1, SetValues2,
 * SetValues01, SetValues02, SetValues12
 * 5) методы создания массива с одинаковыми элементами
 * np.ones, np.zeros, np.fill*/
#include <iostream>
#include <tuple>

using std::cin;
using std::cout;

typedef std::tuple<int, int, int> Tuple_t;

namespace jb {

    template<typename T>
    class Array3D {

    public:
        int N = this->dim0 * this->dim1 * this->dim2;

        Array3D<T> (int dim0, int dim1, int dim2) {
            this->dim0 = dim0;
            this->dim1 = dim1;
            this->dim2 = dim2;
            Array = new int[dim0*dim1*dim2];
        }
        ~Array3D () {
            delete[] Array;
        }

        int getDim0(){
            return this->dim0;
        }

        int getDim1(){
            return this->dim1;
        }

        int getDim2(){
            return this->dim2;
        }

        int* getArray() {
            return Array;
        }

// Indexer
        T & operator[] (Tuple_t item) {
            return  Array[std::get<0>(item)*(this->dim1) + std::get<1>(item)
                    + std::get<2>(item)*(this->dim0)*(this->dim1)];
        }

        T & operator[] (int i) {
            return  Array[i];
        }
// GetValues
        void GetValues (int num, char axe, Tuple_t item) {
            if (axe == 'x') {
                std::get<1>(item) = num;
                for (int i = 0; i < dim0; ++i) {
                    std::get<0>(item) = i;
                    for (int k = 0; k < dim2; ++k) {
                        std::get<2>(item) = k;
                        //cout << Array[item];
                    }
                }
            }
        }

    private:
        int dim0 = 0, dim1 = 0, dim2 = 0;
        int* Array;
    };
}

int main() {
    jb::Array3D<int> arr(7, 3,5);
    Tuple_t i(2, 2, 4);
    arr[i] = 12;
    std::cout << "Element of 3D-array 7x3x5, located in place (2, 2, 4), is " << arr[i] << "." << std::endl;

    int dim0, dim1, dim2;
    std::cout << "Input dimensions of 3D-array (the largest values of i, j, k): " << '\n';
    cin >> dim0;
    cin >> dim1;
    cin >> dim2;

    jb::Array3D<int> array3D(dim0, dim1, dim2);

    Tuple_t index(0, 0, 0);
    int element = 1;
    int height = 0;
    int length = 0;
    int depth = 0;
//Fill an array
    for (;std::get<2>(index) < dim0; ++std::get<2>(index)) {
        for (; std::get<0>(index) < dim1; ++std::get<0>(index)) {
            for (; std::get<1>(index) < dim2; ++std::get<1>(index)) {
                array3D[index] = element;
                element++;
            }
            std::get<1>(index) = 0;
       }
        std::get<0>(index) = 0;
    }

    for (int i = 0; i < dim0*dim1*dim2; ++i) {
        cout << array3D[i] << "  ";
    }

    return 0;
}
