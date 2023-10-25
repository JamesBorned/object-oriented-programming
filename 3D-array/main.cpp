/*The laboratory work №3
 * Создать шаблонный класс Array3D, который внутри хранит одномерный массив, но
 * несмотря на это является трёхмерным.
 * Array3D(int dim0, int dim1, int dim2)
 * Методы:
 * 1) Индексатор [][][]; +
 * 2) Метод GetValues0(int i): (.., .., ..) => (i, .., ..)
 *     GetValues1(int j): (.., .., ..) => (.., j, ..)
 *     GetValues2(int k): (.., .., ..) => (.., .., k) +
 * 3) GetValues01(int i, int j): (.., .., ..) => (i, j, ..)
 *     GetValues02, GetValues12 +
 * 4) SetValues0(int i, [][]), SetValues1, SetValues2,
 * SetValues01, SetValues02, SetValues12 +
 * 5) методы создания массива с одинаковыми элементами +
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

        Array3D<T>(int dim0, int dim1, int dim2) {
            this->dim0 = dim0;
            this->dim1 = dim1;
            this->dim2 = dim2;
            Array = new int[dim0 * dim1 * dim2];
        }

        ~Array3D() {
            delete[] Array;
        }

        int getDim0() {
            return this->dim0;
        }

        int getDim1() {
            return this->dim1;
        }

        int getDim2() {
            return this->dim2;
        }

// Indexer
        T &operator[](Tuple_t item) {
            return Array[std::get<0>(item) * (this->dim1) + std::get<1>(item)
                         + std::get<2>(item) * (this->dim0) * (this->dim1)];
        }

        T &operator[](int i) {
            return Array[i];
        }

// Get values from a two-dimensional matrix located in a certain place in array3D
        void GetValues(int num, char axe) {
            Tuple_t item(0, 0, 0);
            if (axe == 'x') {
                if (num < 0 || num >= dim1){
                    cout << "Number of an axe should be less than or equal to dimension.";
                }
                std::get<1>(item) = num;
                for (int k = 0; k < dim0; ++k) {
                    std::get<2>(item) = k;
                    for (int i = 0; i < dim0; ++i) {
                        std::get<0>(item) = i;
                        cout << Array[std::get<0>(item) * (this->dim1) + num
                                      + std::get<2>(item) * (this->dim0) * (this->dim1)] << " ";
                        if (i == dim0 - 1) {
                            cout << '\n';
                        }
                    }
                }
            }
            else if (axe == 'y') {
                if (num < 0 || num >= dim0){
                    cout << "Number of an axe should be less than or equal to dimension.";
                }
                std::get<0>(item) = num;
                for (int j = 0; j < dim1; ++j) {
                    std::get<1>(item) = j;
                    for (int k = 0; k < dim2; ++k) {
                        std::get<2>(item) = k;
                        cout << Array[num * (this->dim1) + std::get<1>(item)
                                      + std::get<2>(item) * (this->dim0) * (this->dim1)] << " ";
                        if (k == dim2 - 1) {
                            cout << '\n';
                        }
                    }
                }
            } else if (axe == 'z') {
                if (num < 0 || num >= dim2){
                    cout << "Number of an axe should be less than or equal to dimension.";
                }
                std::get<2>(item) = num;
                for (int i = 0; i < dim0; ++i) {
                    std::get<0>(item) = i;
                    for (int j = 0; j < dim1; ++j) {
                        std::get<1>(item) = j;
                        cout << Array[std::get<0>(item) * (this->dim1) + std::get<1>(item)
                                      + num * (this->dim0) * (this->dim1)] << " ";
                        if (j == dim1 - 1) {
                            cout << '\n';
                        }
                    }
                }
            } else {
                cout << "Wrong axe!";
            }
        }

//Get values from a one-dimensional array located in a specific place in array3D.
//Its position is determined by two coordinates.
        void GetValuesOfOneRow(int coor1, int coor2, char axe) {
            Tuple_t item(0, 0, 0);
            if (axe == 'x') {
                if ((coor1 < 0 || coor1 >= dim0) || (coor2 < 0 || coor2 >= dim2)){
                    cout << "Coordinates should be less than or equal to dimension.";
                }
                std::get<0>(item) = coor1;
                std::get<2>(item) = coor2;
                for (int j = 0; j < dim1; ++j) {
                    std::get<1>(item) = j;
                    cout << Array[std::get<0>(item) * (this->dim1) + std::get<1>(item)
                                  + std::get<2>(item) * (this->dim0) * (this->dim1)] << " ";
                }
            } else if (axe == 'y') {
                if ((coor1 < 0 || coor1 >= dim1) || (coor2 < 0 || coor2 >= dim2)){
                    cout << "Coordinates should be less than or equal to dimension.";
                }
                std::get<1>(item) = coor1;
                std::get<2>(item) = coor2;
                for (int i = 0; i < dim0; ++i) {
                    std::get<0>(item) = i;
                    cout << Array[std::get<0>(item) * (this->dim1) + std::get<1>(item)
                                  + std::get<2>(item) * (this->dim0) * (this->dim1)] << " ";
                }
            }
            else if (axe == 'z') {
                if ((coor1 < 0 || coor1 >= dim0) || (coor2 < 0 || coor2 >= dim1)){
                    cout << "Coordinates should be less than or equal to dimension.";
                }
                std::get<0>(item) = coor1;
                std::get<1>(item) = coor2;
                for (int k = 0; k < dim2; ++k) {
                    std::get<2>(item) = k;
                    cout << Array[std::get<0>(item) * (this->dim1) + std::get<1>(item)
                                  + std::get<2>(item) * (this->dim0) * (this->dim1)] << " ";
                }
            }
            else {
                cout << "Wrong axe!";
            }
        }

// Set values of a two-dimensional matrix located in a certain place in array3D
// in a new matrix.
        int** SetValues(int num, char axe, int** rect){
            Tuple_t item(0, 0, 0);
            if (axe == 'x') {
                if (num < 0 || num >= dim1){
                    cout << "Number of an axe should be less than or equal to dimension.";
                }
                std::get<1>(item) = num;
                for (int k = 0; k < dim0; ++k) {
                    std::get<2>(item) = k;
                    for (int i = 0; i < dim0; ++i) {
                        std::get<0>(item) = i;
                        rect[k][i] = Array[std::get<0>(item) * (this->dim1) + num
                                           + std::get<2>(item) * (this->dim0) * (this->dim1)];
                    }
                }
            }
            else if (axe == 'y') {
                if (num < 0 || num >= dim0){
                    cout << "Number of an axe should be less than or equal to dimension.";
                }
                std::get<0>(item) = num;
                for (int j = 0; j < dim1; ++j) {
                    std::get<1>(item) = j;
                    for (int k = 0; k < dim2; ++k) {
                        std::get<2>(item) = k;
                        rect[j][k] = Array[num * (this->dim1) + std::get<1>(item)
                                      + std::get<2>(item) * (this->dim0) * (this->dim1)];
                    }
                }
            }
            else if (axe == 'z') {
                if (num < 0 || num >= dim2){
                    cout << "Number of an axe should be less than or equal to dimension.";
                }
                std::get<2>(item) = num;
                for (int i = 0; i < dim0; ++i) {
                    std::get<0>(item) = i;
                    for (int j = 0; j < dim1; ++j) {
                        std::get<1>(item) = j;
                        rect[i][j] = Array[std::get<0>(item) * (this->dim1) + std::get<1>(item)
                                      + num * (this->dim0) * (this->dim1)];
                    }
                }
            }
            else {
                cout << "Wrong axe!";
            }
            return rect;
        }

//Set values of a one-dimensional array located in a specific place in array3D
//in a new one-dimensional array.
//Its position is determined by two coordinates.
        int* SetValuesOfOneRow(int coor1, int coor2, char axe, int* row) {
            Tuple_t item(0, 0, 0);
            if (axe == 'x') {
                if ((coor1 < 0 || coor1 >= dim0) || (coor2 < 0 || coor2 >= dim2)){
                    cout << "Coordinates should be less than or equal to dimension.";
                }
                std::get<0>(item) = coor1;
                std::get<2>(item) = coor2;
                for (int j = 0; j < dim1; ++j) {
                    std::get<1>(item) = j;
                    row[j] = Array[std::get<0>(item) * (this->dim1) + std::get<1>(item)
                                  + std::get<2>(item) * (this->dim0) * (this->dim1)];
                }
            }
            else if (axe == 'y') {
                if ((coor1 < 0 || coor1 >= dim1) || (coor2 < 0 || coor2 >= dim2)){
                    cout << "Coordinates should be less than or equal to dimension.";
                }
                std::get<1>(item) = coor1;
                std::get<2>(item) = coor2;
                for (int i = 0; i < dim0; ++i) {
                    std::get<0>(item) = i;
                    row[i] = Array[std::get<0>(item) * (this->dim1) + std::get<1>(item)
                                  + std::get<2>(item) * (this->dim0) * (this->dim1)];
                }
            }
            else if (axe == 'z') {
                if ((coor1 < 0 || coor1 >= dim0) || (coor2 < 0 || coor2 >= dim1)){
                    cout << "Coordinates should be less than or equal to dimension.";
                }
                std::get<0>(item) = coor1;
                std::get<1>(item) = coor2;
                for (int k = 0; k < dim2; ++k) {
                    std::get<2>(item) = k;
                    row[k] = Array[std::get<0>(item) * (this->dim1) + std::get<1>(item)
                                  + std::get<2>(item) * (this->dim0) * (this->dim1)];
                }
            }
            else {
                cout << "Wrong axe!";
            }
            return row;
        }

        void FillArray3D () {
            Tuple_t index(0, 0, 0);
            int element;
            for (;std::get<2>(index) < dim2; ++std::get<2>(index)) {
                cout << "Input a rectangle of elements: ";
                for (; std::get<0>(index) < dim0; ++std::get<0>(index)) {
                    for (; std::get<1>(index) < dim1; ++std::get<1>(index)) {
                        cin >> element;
                        Array[std::get<0>(index) * (this->dim1) + std::get<1>(index)
                                  + std::get<2>(index) * (this->dim0) * (this->dim1)] = element;
                    }
                    std::get<1>(index) = 0;
                }
                std::get<0>(index) = 0;
            }
        }

        void FillArray3DZeros () {
            Tuple_t index(0, 0, 0);
            for (;std::get<2>(index) < dim2; ++std::get<2>(index)) {
                for (; std::get<0>(index) < dim1; ++std::get<0>(index)) {
                    for (; std::get<1>(index) < dim0; ++std::get<1>(index)) {
                        Array[std::get<0>(index) * (this->dim1) + std::get<1>(index)
                              + std::get<2>(index) * (this->dim0) * (this->dim1)] = 0;
                    }
                    std::get<1>(index) = 0;
                }
                std::get<0>(index) = 0;
            }
        }

        void FillArray3DOnes () {
            Tuple_t index(0, 0, 0);
            for (;std::get<2>(index) < dim2; ++std::get<2>(index)) {
                for (; std::get<0>(index) < dim1; ++std::get<0>(index)) {
                    for (; std::get<1>(index) < dim0; ++std::get<1>(index)) {
                        Array[std::get<0>(index) * (this->dim1) + std::get<1>(index)
                              + std::get<2>(index) * (this->dim0) * (this->dim1)] = 1;
                    }
                    std::get<1>(index) = 0;
                }
                std::get<0>(index) = 0;
            }
        }

        void FillArray3DIdenticalElements (T element) {
            Tuple_t index(0, 0, 0);
            for (;std::get<2>(index) < dim2; ++std::get<2>(index)) {
                for (; std::get<0>(index) < dim1; ++std::get<0>(index)) {
                    for (; std::get<1>(index) < dim0; ++std::get<1>(index)) {
                        Array[std::get<0>(index) * (this->dim1) + std::get<1>(index)
                              + std::get<2>(index) * (this->dim0) * (this->dim1)] = element;
                    }
                    std::get<1>(index) = 0;
                }
                std::get<0>(index) = 0;
            }
        }

    private:
        int dim0 = 0, dim1 = 0, dim2 = 0;
        int* Array;
    };
}

int main() {
    jb::Array3D<int> arr(7, 3,5);
    arr[(2, 2, 4)] = 12;
    std::cout << "Element of 3D-array 7x3x5, located in place (2, 2, 4), is " << arr[(2, 2, 4)] << "." << std::endl;

    int dim0, dim1, dim2;
    std::cout << "Input dimensions of 3D-array (the largest values of i, j, k): " << '\n';
    cin >> dim0;
    cin >> dim1;
    cin >> dim2;

    jb::Array3D<int> array3D(dim0, dim1, dim2);

    Tuple_t start(0, 0, 0);
    Tuple_t index(0, 0, 0);
    int element = 1;
//Fill an array
    for (;std::get<2>(index) < dim2; ++std::get<2>(index)) {
        for (; std::get<0>(index) < dim0; ++std::get<0>(index)) {
            for (; std::get<1>(index) < dim1; ++std::get<1>(index)) {
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

    cout << '\n';
    cout << '\n';

    char axe;
    cout << "Input a name of an axe (x, y or z): ";
    cin >> axe;

    int NumOfAxe;
    cout << "Input a number of the axe: ";
    cin >> NumOfAxe;

    cout << '\n';

    array3D.GetValues(NumOfAxe, axe);

    cout << '\n';
    cout << "Input a name of an axe (x, y or z): ";
    cin >> axe;

    cout << "Input two coordinates of required row in order from left to right\n"
            "i, j, k, for example, i and k for axe 'y'.\n";
    cout << "Input the first coordinate: ";
    int coor1;
    cin >> coor1;

    cout << "Input the second coordinate: ";
    int coor2;
    cin >> coor2;

    cout << '\n';

    array3D.GetValuesOfOneRow(coor1, coor2, axe);

    cout << '\n';

    cout << "Input a name of an axe (x, y or z): ";
    cin >> axe;

    cout << "Input a number of the axe: ";
    cin >> NumOfAxe;

    cout << '\n';

    int columns = 0;
    int rows = 0;
    if (axe == 'x') {
        columns = array3D.getDim2();
        rows = array3D.getDim0();
    }
    else if (axe == 'y') {
        columns = array3D.getDim1();
        rows = array3D.getDim2();
    }
    else if (axe == 'z') {
        columns = array3D.getDim1();
        rows = array3D.getDim0();
    }

    //array of pointers
    int** rect = new int*[columns];

    for (int i = 0; i < columns; ++i){
        rect[i] = new int[rows];
    }

    rect = array3D.SetValues(NumOfAxe, axe, rect);

    for (int i = 0; i < columns; ++i){
        for (int j = 0; j < rows; ++j){
            cout << rect[i][j] << " ";
        }
        cout << '\n';
    }

    for (int i = 0; i < columns; ++i) {
        delete[] rect[i];
    }

    delete[] rect;

    cout << '\n';
    cout << "Input a name of an axe (x, y or z): ";
    cin >> axe;

    cout << "Input two coordinates of required row in order from left to right\n"
            "i, j, k, for example, i and k for axe 'y'.\n";
    cout << "Input the first coordinate: ";
    cin >> coor1;

    cout << "Input the second coordinate: ";
    cin >> coor2;

    cout << '\n';

    int size = 0;
    if (axe == 'x') {
        size = array3D.getDim1();
    }
    else if (axe == 'y') {
        size = array3D.getDim0();
    }
    else if (axe == 'z') {
        size = array3D.getDim2();
    }

    int* row = new int[size];

    row = array3D.SetValuesOfOneRow(coor1, coor2, axe, row);

    for (int i = 0; i < size; ++i){
        cout << row[i] << " ";
    }

    delete[] row;

    cout << "\n";

    array3D.FillArray3D();

    for (int i = 0; i < dim0*dim1*dim2; ++i) {
        cout << array3D[i] << "  ";
    }
    cout << '\n';

    array3D.FillArray3DZeros();

    for (int i = 0; i < dim0*dim1*dim2; ++i) {
        cout << array3D[i] << "  ";
    }
    cout << '\n';

    array3D.FillArray3DOnes();

    for (int i = 0; i < dim0*dim1*dim2; ++i) {
        cout << array3D[i] << "  ";
    }
    cout << '\n';

    cout << "Input a number: ";
    cin >> element;
    array3D.FillArray3DIdenticalElements(element);

    for (int i = 0; i < dim0*dim1*dim2; ++i) {
        cout << array3D[i] << "  ";
    }
    cout << '\n';

    return 0;
}
