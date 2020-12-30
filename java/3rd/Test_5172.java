/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:59:35
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-31 00:43:33
 * @Description  :
*********************************************/

class Employees {
    int m_num;
    String m_name;
    double m_basic_salary;

    public double addSalary(double basicSalary) {
        return basicSalary * 0.2;
    }

    public double totalSalary(double basicSalary) {
        return basicSalary * 1.2;
    }

    public void Set(int num,String name, double salary) {
        this.m_num = num;
        this.m_name = name;
        this.m_basic_salary = salary;
    }

    public void print() {
        System.out.println("Employee num : " + m_num);
        System.out.println("Employee name : " + m_name);
        System.out.println("Employee basic salary : " + m_basic_salary);
        System.out.println("Employee total salary : " + this.totalSalary(m_basic_salary));
    }
}

public class Test_5172 {
    public static void main(String[] args) {

        Employees A = new Employees();
        A.Set(2019063,"test",100);
        A.print();
    }
}
