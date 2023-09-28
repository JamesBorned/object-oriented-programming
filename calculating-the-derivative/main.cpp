#include <iostream>
#include <cmath>
#include <functional>

using std::cin;
using std::cout;

//typedef std::function<double(double)> func;
//double getParabola(double x) {
//    return 6 * pow(x, 2) + 5 * x + 1;
//}
//func f1 = getParabola;

namespace jb {
    typedef std::function<double(double)> func;

    class DerivativeCalc {

    public:

        explicit DerivativeCalc(double Step){
            step = Step;
        }

        virtual ~DerivativeCalc() = default;

        static double getPolynomial(double x, int a, int b, int c) {
            return a* pow(x, 2) + b * x + c;
        }

        virtual double calcDeriv(double x0, int a, int b, int c) = 0;
        virtual double getAccuracy() = 0;

    protected:

        double step;
    };

    class RightDerivativeCalc : public DerivativeCalc {

    public:

        explicit RightDerivativeCalc(double step) : DerivativeCalc(step) {
        }

        double calcDeriv(double x0, int a, int b, int c) override {
            return (getPolynomial(x0 + step, a, b, c) - getPolynomial(x0, a, b, c)) / step;
        }

        double getAccuracy() override { return step; }

    };

    class LeftDerivativeCalc : public DerivativeCalc {

    public:

        explicit LeftDerivativeCalc(double step) : DerivativeCalc(step) {
        }

        double calcDeriv(double x0, int a, int b, int c) override {
            return (getPolynomial(x0, a, b, c) - getPolynomial(x0 - step, a, b, c)) /step;
        }

        double getAccuracy() override { return 2*step; }

    };

    class MiddleDerivativeCalc : public DerivativeCalc {

    public:

        explicit MiddleDerivativeCalc(double step) : DerivativeCalc(step) {
        }

        double calcDeriv(double x0, int a, int b, int c) override {
            return (getPolynomial(x0 + step, a, b, c) - getPolynomial(x0 - step, a, b, c)) / (2*step);
        }

        double getAccuracy() override { return pow(step, 2); }

    };
}

int main() {

    setlocale(LC_ALL, "Rus");

    double x0;
    double step;
    int a, b, c;

    cout << "Input x-coordinate of the point: ";
    cin >> x0;

    cout << "Input step: ";
    cin >> step;

    cout << "Input a: ";
    cin >> a;

    cout << "Input b: ";
    cin >> b;

    cout << "Input c: ";
    cin >> c;

    jb::LeftDerivativeCalc LeftDerPolynomial = jb::LeftDerivativeCalc(step);

    double LeftResult = LeftDerPolynomial.calcDeriv(x0, a, b, c);
    double LeftAccuracy = LeftDerPolynomial.getAccuracy();

    cout << "A left derivative: " << LeftResult << '\n';
    cout << "A left derivative accuracy: " << LeftAccuracy << '\n';

    jb::RightDerivativeCalc RightDerPolynomial = jb::RightDerivativeCalc(step);

    double RightResult = RightDerPolynomial.calcDeriv(x0, a, b, c);
    double RightAccuracy = RightDerPolynomial.getAccuracy();

    cout << "A right derivative: " << RightResult << '\n';
    cout << "A right derivative accuracy: " << RightAccuracy << '\n';

    jb::MiddleDerivativeCalc MiddleDerPolynomial = jb::MiddleDerivativeCalc(step);

    double MiddleResult = MiddleDerPolynomial.calcDeriv(x0, a, b, c);
    double MiddleAccuracy = MiddleDerPolynomial.getAccuracy();

    cout << "A middle derivative: " << MiddleResult << '\n';
    cout << "A middle derivative accuracy: " << MiddleAccuracy << '\n';

    return 0;
}
