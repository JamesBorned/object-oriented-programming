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
            this -> numerator  = num;
            this -> denominator = denom;
        }

        ~NaturalFraction() = default;

        int getNumerator () {
            return this -> numerator;
        }

        int getDenominator () {
            return this -> denominator;
        }

        int findCommonDenom (NaturalFraction firstF, NaturalFraction secondF){
            return firstF.denominator * secondF.denominator;
        }

        int addNumers (NaturalFraction firstF, NaturalFraction secondF){
            return firstF.numerator * secondF.denominator + secondF.numerator * firstF.denominator;
        }

        int subtractNumers (NaturalFraction firstF, NaturalFraction secondF){
            return firstF.numerator * secondF.denominator - secondF.numerator * firstF.denominator;
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
//                tmp.numerator = getNumerator();
//                tmp.denominator = getDenominator();

            //cout << fraction.numerator << "/" << fraction.denominator << "+" <<
            //this -> numerator << "/" << this -> denominator << "= ";

            tmp.numerator = addNumers(*this, fraction);;
            tmp.denominator = findCommonDenom(*this, fraction);;

            divisior = findGreatCommonDiv(tmp.numerator, tmp.denominator);

            tmp.numerator = tmp.numerator / divisior;
            tmp.denominator = tmp.denominator / divisior;

            //cout << this -> numerator << "/" << this -> denominator;

            return tmp;
        }

        NaturalFraction operator -(NaturalFraction& fraction){

            NaturalFraction tmp;

            tmp.numerator = subtractNumers(*this, fraction);
            tmp.denominator = findCommonDenom(*this, fraction);

            divisior = findGreatCommonDiv(tmp.numerator, tmp.denominator);

            tmp.numerator = tmp.numerator / divisior;
            tmp.denominator = tmp.denominator / divisior;

            return tmp;
        }

        NaturalFraction operator *(NaturalFraction& fraction){

            NaturalFraction tmp;

            tmp.numerator = this -> numerator * fraction.numerator;
            tmp.denominator = this -> denominator * fraction.denominator;

            divisior = findGreatCommonDiv(tmp.numerator, tmp.denominator);

            tmp.numerator = tmp.numerator / divisior;
            tmp.denominator = tmp.denominator / divisior;

            return tmp;
        }

        NaturalFraction operator /(NaturalFraction& fraction){

            NaturalFraction tmp;

            tmp.numerator = this -> numerator * fraction.denominator;
            tmp.denominator = this -> denominator * fraction.numerator;

            divisior = findGreatCommonDiv(tmp.numerator, tmp.denominator);

            tmp.numerator = tmp.numerator / divisior;
            tmp.denominator = tmp.denominator / divisior;

            return tmp;
        }

        double getDecimal (){
            double DecimalFraction = (double)this -> numerator / this -> denominator;
            return DecimalFraction;
        }

        NaturalFraction getInverse (){
            NaturalFraction tmp;
            tmp.numerator = this -> denominator;
            tmp.denominator = this -> numerator;

            return tmp;
        }

    private:

        int numerator = 0;
        int denominator = 1;
        int divisior = 1;
    };
}

int main() {
    int m1, n1, m2, n2;

    inputNumerator1:
    cout << "Input a numerator of the first natural fraction: " << '\n';
    cin >> m1;
    if (m1 <= 0) {
        goto inputNumerator1;
    }

    inputDenominator1:
    cout << "Input a denominator of the first natural fraction: " << '\n';
    cin >> n1;
    if (n1 <= 0) {
        goto inputDenominator1;
    }

    inputNumerator2:
    cout << "Input a numerator of the second natural fraction: " << '\n';
    cin >> m2;
    if (m2 <= 0) {
        goto inputNumerator2;
    }

    inputDenominator2:
    cout << "Input a denominator of the second natural fraction: " << '\n';
    cin >> n2;
    if (n1 <= 0) {
        goto inputDenominator2;
    }

    jb::NaturalFraction result;
    jb::NaturalFraction first = jb::NaturalFraction(m1, n1);;
    jb::NaturalFraction second = jb::NaturalFraction(m2, n2);

    result = first + second;
    cout << first.getNumerator() << "/" << first.getDenominator() <<
    " + " << second.getNumerator() << "/" << second.getDenominator();

    cout << " = " << result.getNumerator() <<
    " / " << result.getDenominator() << '\n';

    result = first - second;
    cout << first.getNumerator() << "/" << first.getDenominator() <<
         " - " << second.getNumerator() << "/" << second.getDenominator();

    cout << " = " <<
    result.getNumerator() << " / " << result.getDenominator() << '\n';

    result = first * second;
    cout << first.getNumerator() << "/" << first.getDenominator() <<
         " * " << second.getNumerator() << "/" << second.getDenominator();

    cout << " = " << result.getNumerator() << " / " << result.getDenominator() << '\n';

    result = first / second;
    cout << first.getNumerator() << "/" << first.getDenominator() <<
         " / " << second.getNumerator() << "/" << second.getDenominator();

    cout <<" = " << result.getNumerator() << " / " << result.getDenominator() << '\n';

    cout << "Inverse fraction: " << result.getInverse().getNumerator() << "/" << result.getInverse().getDenominator() <<'\n';
    cout << "Decimal fraction: " << result.getInverse().getDecimal();

    return 0;
}
