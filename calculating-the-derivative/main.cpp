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

        //DerivativeCalc();
        //~ DerivativeCalc();

    public:

        double get_a(){
            cout << "Input a: " << '\n';
            cin >> a;
            return a;
        }

        double get_b(){
            cout << "Input b: " << '\n';
            cin >> b;
            return b;
        }

        double get_c(){
            cout << "Input c: " << '\n';
            cin >> c;
            return c;
        }

        double getParabola(double x) {
            return a * pow(x, 2) + b * x + c;
        }

        virtual double calcDeriv(double x0) = 0;
        virtual double getAccuracy() = 0;

        double get_step(){
            cin >> step;
            return step;
        }

    protected:
        double step = get_step();
        double a = get_a(), b = get_b(), c = get_c();
    };

    class RightDerivativeCalc : public DerivativeCalc {

    public:

        double calcDeriv(double x0) override {
            return (getParabola(x0 + step) - getParabola(x0)) / step;
        }

        double getAccuracy() override { return step; }

    };

    class LeftDerivativeCalc : public DerivativeCalc {

    public:

        double calcDeriv(double x0) override {
            return (getParabola(x0) - getParabola(x0 - step)) /step;
        }

        double getAccuracy() override { return 2*step; }

    };

    class MiddleDerivativeCalc : public DerivativeCalc {

    public:

        double calcDeriv(double x0) override {
            return (getParabola(x0 + step) - getParabola(x0 - step)) / 2*step;
        }

        double getAccuracy() override { return pow(step, 2); }

    };
}

int main() {

    setlocale(LC_ALL, "Rus");

    double x0;

    cout << "Input coordinates of the point: ";
    cin >> x0;

    jb::LeftDerivativeCalc LeftDerPolynomial;

    LeftDerPolynomial.calcDeriv(x0);
    LeftDerPolynomial.getAccuracy();

    return 0;
}
