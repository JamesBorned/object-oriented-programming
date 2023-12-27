#include <iostream>
#include <cmath>
#include <functional>
#include <memory>

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

        void setFunction(func F){
            f = F;
        }

        func getFunction(){
            return f;
        }

        virtual double calcDeriv(double x0, func f) = 0;
        virtual double getAccuracy() = 0;

    protected:
        func f;
        double step;
    };

    class RightDerivativeCalc : public DerivativeCalc {

    public:

        explicit RightDerivativeCalc(double step) : DerivativeCalc(step) {
        }

        double calcDeriv(double x0, func F) override {
            return (F(x0 + step) - F(x0)) / step;
        }

        double getAccuracy() override { return step; }

    };

    class LeftDerivativeCalc : public DerivativeCalc {

    public:

        explicit LeftDerivativeCalc(double step) : DerivativeCalc(step) {
        }

        double calcDeriv(double x0, func F) override {
            return (F(x0) - F(x0 - step)) /step;
        }

        double getAccuracy() override { return 2*step; }

    };

    class MiddleDerivativeCalc : public DerivativeCalc {

    public:

        explicit MiddleDerivativeCalc(double step) : DerivativeCalc(step) {
        }

        double calcDeriv(double x0, func F) override {
            return (F(x0 + step) - F(x0 - step)) / (2*step);
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

    int flag = 0;
    while(flag == 0){
        cout << "Input step: ";
        cin >> step;
        if (step != 0){
            flag = 1;
        }
    }

    jb::func f = [](double x) {
        int a, b, c;

        cout << "Input a: ";
        cin >> a;

        cout << "Input b: ";
        cin >> b;

        cout << "Input c: ";
        cin >> c;

        return a * pow(x, 2) + b * x + c;
    };

    //std::unique_ptr<jb::DerivativeCalc> LeftDerivativeCalc = std::make_unique<jb::LeftDerivativeCalc> (jb::LeftDerivativeCalc(step));
    //std::unique_ptr<jb::DerivativeCalc> RightDerivativeCalc = std::make_unique<jb::RightDerivativeCalc> (jb::RightDerivativeCalc(step));
    //std::unique_ptr<jb::DerivativeCalc> MiddleDerivativeCalc = std::make_unique<jb::MiddleDerivativeCalc> (jb::MiddleDerivativeCalc(step));
    jb::LeftDerivativeCalc LeftDer (step);
    jb::RightDerivativeCalc RightDer (step);
    jb::MiddleDerivativeCalc MiddleDer (step);

    double LeftResult = LeftDer.calcDeriv(x0, f);
    double LeftAccuracy = LeftDer.getAccuracy();

    cout << "A left derivative: " << LeftResult << '\n';
    cout << "A left derivative accuracy: " << LeftAccuracy << '\n';

    //jb::RightDerivativeCalc RightDerPolynomial = jb::RightDerivativeCalc(step);

    double RightResult = RightDer.calcDeriv(x0, f) ;
    double RightAccuracy = RightDer.getAccuracy() ;

    cout << "A right derivative: " << RightResult  << '\n';
    cout << "A right derivative accuracy: " << RightAccuracy << '\n';

    //jb::MiddleDerivativeCalc MiddleDerPolynomial = jb::MiddleDerivativeCalc(step);

    double MiddleResult = MiddleDer.calcDeriv(x0, f);
    double MiddleAccuracy =  MiddleDer.getAccuracy();

    cout << "A middle derivative: " << MiddleResult << '\n';
    cout << "A middle derivative accuracy: " << MiddleAccuracy << '\n';

    return 0;
}
