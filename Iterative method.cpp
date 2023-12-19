#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double equation(double x)
{
    return 2 - sin(1 / x);
}

int main()
{
    while (true) {
        setlocale(LC_ALL, "Rus");
        bool flag = true;
        int iter_count = 0;
        double a, b, x1, x2;
        double eps = 0;
        cout << "Для решения уравнения y = x - 2 + sin(1/x) = 0, с корнем x = 1,3077,\
    методом итераций,\nведите пераметры интервала a и b (рекомендуем 1 и 2!): ";
        cin >> a >> b;
        while ((eps == 0) or (eps >= abs(a - b))) {
            cout << "Введите значение эпсилон(0 < eps < " << abs(a - b) << "): ";
            cin >> eps;
        }
        if ((x - 2 + sin(1 / x)) * (a - 2 + sin(1 / a)) < 0)
            x2 = a;
        else if ((x - 2 + sin(1 / x)) * (b - 2 + sin(1 / b)) < 0)
            x2 = b;
        else
            flag = false;
        if (flag) {
            do {
                x1 = x2;
                x2 = equation(x1);
                iter_count++;
            } while (abs(x2 - x1) > eps and flag);
        }
        if (flag)
            cout << "Корень фунции равен: " << setprecision(13) << x2 << "\
        \nОтвет найден за " << iter_count << " итерации";
        else
            cout << "Нет решений на заданном промежутке" << '\n';
    }
}







