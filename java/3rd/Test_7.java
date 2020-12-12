/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-10 22:13:53
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-10 23:29:34
 * @Description  :
*********************************************/

class Employee {
    private int m_id;
    private String m_name;
    private int m_salary;
    private String m_department;

    Employee(){
    }
    Employee(int id){
        m_id = id;
        m_name = "无名氏";
        m_salary = 0;
        m_department = "未定";
    }
    Employee(int id, String name){
        m_id = id;
        m_name = name;
        m_salary = 1000;
        m_department = "后勤";
    }
    Employee(int id, String name, int salary, String department){
        m_id = id;
        m_name = name;
        m_salary = salary;
        m_department = department;
    }

    public void setId(int id) {
        m_id = id;
    }
    public void setName(String name) {
        m_name = name;
    }
    public void setSalary(int salary) {
        m_salary = salary;
    }
    public void setDepartment(String department) {
        m_department = department;
    }

    public int getId() {
        return m_id;
    }
    public String getName() {
        return m_name;
    }
    public int getSalary() {
        return m_salary;
    }
    public String getDepartment() {
        return m_department;
    }

    public void printInformation() {
        System.out.println("ID : " + m_id);
        System.out.println("Name : " + m_name);
        System.out.println("Salary : " + m_salary);
        System.out.println("Department : " + m_department);
    }
}

public class Test_7 {
    public static void main(String [] args) {
        Employee a = new Employee();
        a.printInformation();
    }
}