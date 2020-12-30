/*********************************************
 * @Author : Daniel_Elendeer
 * @Date : 2020-12-30 23:59:35
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-31 00:42:46
 * @Description :
 *********************************************/
class User {
    String m_user_name;
    String m_command;
    int m_num;

    public void init() {
        m_user_name = null;
        m_command = null;
        m_num = 0;
    }

    public void setUserName(String userName) {
        this.m_user_name = userName;
        ++ this.m_num;
    }

    public void Set(String userName, String command) {
        this.m_user_name = userName;
        this.m_command = command;
        ++ this.m_num;
    }

    public String getCommand() {
        return m_command;
    }

    public void setCommand(String command) {
        this.m_command = command;
    }

    public void print() {
        System.out.println("user name : " + m_user_name);
        System.out.println("command : " + m_command);
        System.out.println("user num : " + m_num);
    }
}

public class Test_5175 {
    public static void main(String[] args) {

        User A = new User();
        A.init();
        A.print();
        System.out.println();
        A.Set("name", "ohhhhh!");
        A.print();
        System.out.println();
        A.setCommand("wow!");
        A.getCommand();
        A.print();
    }
}
