/*********************************************
 * @Author : Daniel_Elendeer
 * @Date : 2020-12-30 23:59:35
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-31 00:50:32
 * @Description :
 *********************************************/

class bankAccount {
    private double m_balance;
    private String m_name;

    public void Set(String name, double balance) {
        this.m_name = name;
        this.m_balance = balance;
    }

    public void search() {
        System.out.println(this.m_name + "'s balance is " + this.m_balance);
    }
}

public class Test_5178 {
    public static void main(String[] args) {

        bankAccount A = new bankAccount();
        A.Set("someone", 115.3);
        bankAccount B = new bankAccount();
        B.Set("LuoLao", 8848);

        A.search();
        B.search();
    }
}
