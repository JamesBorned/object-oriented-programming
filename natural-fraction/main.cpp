/*Laboratory work №2
 * Создать класс - натуральная дробь. Переопределить (добавить) методы для сложения,
 * вычитания, умножения, деления, а также
 * преобразования в десятичную дробь, нахождения обратной дроби.
 * Сделать класс с консольным интерфейсом для возможности
 * демонстрации вычислений с дробями.
 * Натуральная дробь - это число, которое может быть
 * выражено в виде дроби, где числитель и знаменатель - натуральные числа.
 * */

#include <iostream>

using std::cout;
using std::cin;

namespace jb {

    class NaturalFraction {

    public:

        NaturalFraction() = default;

        NaturalFraction(int num, int denom) {
            num = getNumerator();
            denom = getDenominator();
        }

        ~NaturalFraction() = default;

        int getNumerator () {
            inputNumerator:
                cout << "Input a numerator: ";
                cin >> numerator;
                if (numerator <= 0) {
                    goto inputNumerator;
                }
                else {
                    return numerator;
                }
        }

        int getDenominator () {
            inputDenominator:
                cout << "Input a denominator: ";
                cin >> denominator;
                if (denominator <= 0) {
                    goto inputDenominator;
                }
                else {
                    return denominator;
                }
        }

        int findCommonDenom (NaturalFraction firstF, NaturalFraction secondF){
            return firstF.denominator * secondF.denominator;
        }

        int addNumers (NaturalFraction firstF, NaturalFraction secondF){
            return firstF.numerator * secondF.denominator + secondF.numerator * firstF.denominator;
        }

        int findGreatCommonDiv (int num, int denom){
            int tmpNum = num;
            int tmpDenom = denom;

            while(tmpNum > 0 && tmpDenom > 0){
                if (tmpNum > tmpDenom){
                    tmpNum %= tmpDenom;
                }
                else {
                    tmpDenom %= tmpNum;
                }
            }

            divisior = tmpNum + tmpDenom;

            return divisior;
        }

        NaturalFraction operator +(NaturalFraction& fraction){

            NaturalFraction tmp;
//            numerator = getNumerator();
//            denominator = getDenominator();

            cout << fraction.numerator << "/" << fraction.denominator << "+" <<
            this -> numerator << "/" << this -> denominator << "= ";

            this -> numerator = addNumers(tmp, fraction);;
            this -> denominator = findCommonDenom(tmp, fraction);;

            divisior = findGreatCommonDiv(this -> numerator, this -> denominator);

            this -> numerator = tmp.numerator / divisior;
            this -> denominator = tmp.denominator / divisior;

            cout << this -> numerator << "/" << this -> denominator;

            return tmp;
        }

    private:

        int numerator = 0;
        int denominator = 0;
        int divisior = 1;
    };
}

int main() {

    jb::NaturalFraction a;
    jb::NaturalFraction n = jb::NaturalFraction(0, 0);

    jb::NaturalFraction b = jb::NaturalFraction(0, 0);

    a = n + b;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
