#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double equation(double x)
{
    return x - 2 + sin(1 / x);
}

double derivative(double x)
{
    return 1 - (cos(1 / x) / (x*x));
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
    методом Ньютона,\nведите пераметры интервала a и b (рекомендуем 1 и 2!): ";
        cin >> a >> b;
        while ((eps == 0) or (eps >= abs(a - b))) {
            cout << "Введите значение эпсилон(0 < eps < " << abs(a - b) << "): ";
            cin >> eps;
        }
        if (equation(a) > 0)
            x2 = a;
        else if (equation(b) > 0)
            x2 = b;
        else
            flag = false;
        if (flag) {
            do {
                x1 = x2;
                x2 = x1 - equation(x1) / derivative(x1);
                iter_count++;
            } while ((abs(x2 - x1) > eps) and flag);
        }
        if (flag)
            cout << "Корень фунции равен: " << setprecision(13) << x2 << "\
        \nОтвет найден за " << iter_count << " итерации";
        else
            cout << "Нет решений на заданном промежутке" << '\n';
    }
}

/*
int main() {
    setlocale(LC_ALL, "Rus");
    double x1, x2, a, b, e;
    bool solution = true;
    cin >> a >> b >> e;
    if ((sin(a) - 0.4) * -sin(a) > 0) {
        x2 = a;
    }
    else if ((sin(b) - 0.4) * -sin(b) > 0) {
        x2 = b;
    }
    else {
        cout << "Точки не подходят для нахождения решения";
        solution = false;
    }
    if (solution) {
        int k = 0;
        do {
            k++;
            x1 = x2;
            x2 = x1 - (sin(x1) - 0.4) / cos(x1);
            
        } while (abs(x2 - x1) > e && solution);
        if (solution) {
            cout << "Решение: " << x2 << '\n' << "Найдено за " << k << " итераций цикла" << '\n';
        }
        else {
            cout << "Решения нет!";
        }
    }
    return 0;
}


double equation(double x)
{
    return x - 2 + sin(1 / x);
}

int main()
{
    int iter_count = 0;
    double a, b, x;
    double eps = 0;
    setlocale(LC_ALL, "Rus");
    cout << "Для решения уравнения y = x - 2 + sin(1/x) = 0 (ожидаемый ответ: 1,3077),\nведите пераметры интервала a и b (рекомендуем 1 и 2!): ";
    cin >> a >> b;
    while ((eps == 0) or (eps >= abs(a - b))) {
        cout << "Введите значение эпсилон(0 < eps < " << abs(a - b) << "): ";
        cin >> eps;
    }
    bool flag = true;
    while ((abs(a - b) > eps) and flag){
        x = (a + b) / 2;
        if (equation(x) * equation(a) < 0)
            b = x;
        else if (equation(x) * equation(b) < 0)
            a = x;
        else {
            cout << "Нет решений на заданном промежутке" << '\n';
            flag = false;
        }
        iter_count++;
    }
    if (flag)
        cout << "Корень фунции равен: " << x << "\nОтвет найден за " << iter_count << " итерации";
}
*/