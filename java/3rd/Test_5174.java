/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:59:35
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-31 00:43:05
 * @Description  :
*********************************************/
class Dog{
    String m_name;
    String m_color;
    int m_age;

    public void setName(String m_name) {
        this.m_name = m_name;
    }

    public void setColor(String m_color) {
        this.m_color = m_color;
    }

    public void setAge(int age) {
        this.m_age = age;
    }
    public void print(){
        System.out.println("name : "+ m_name);
        System.out.println("color : "+ m_color);
        System.out.println("age : "+ m_age);
    }
}

public class Test_5174 {
    public static void main(String[] args) {

        Dog A = new Dog();
        A.setName("black");
        A.setColor("black");
        A.setAge(3);

        A.print();
    }
}
