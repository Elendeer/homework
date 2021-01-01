/*
 * @Author: Elendeer
 * @Date: 2020-05-28 21:08:04
 * @LastEditors: Elendeer
 * @LastEditTime: 2020-06-05 16:17:36
 * @Description: file content
 */
#include <cmath>
#include <iostream>

class salesman {
   private:
    int m_num, m_quantity;
    double m_price;

    constexpr static double m_discount = 0.98;

   public:
    static double m_sum;
    static int m_n;

    salesman(int num, int quntity, double price)
        : m_num(num), m_quantity(quntity), m_price(price) {
        if (m_quantity <= 10) {
            m_sum += m_quantity * m_price;
        } else {
            m_sum += m_quantity * m_price * m_discount;
        }
        m_n += m_quantity;
    }

    static double average();
    static void display();
};
double salesman::m_sum = 0;
int salesman::m_n = 0;

double salesman::average() { return m_sum / m_n; }
void salesman::display() {
    using namespace std;

    cout << "sum: " << m_sum << endl;
    cout << "average: " << average() << endl;
}

int main() {
    salesman A(101, 5, 23.5), B(102, 12, 24.56), C(103, 100, 21.5);

    salesman::display();

    return 0;
}