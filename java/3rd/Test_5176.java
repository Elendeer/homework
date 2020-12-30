
/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:59:35
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-31 00:34:31
 * @Description  :
*********************************************/
import java.util.Scanner;

public class Test_5176 {
    public static void main(String[] args) {
        String str1 = "Java技术学习班20070326";
        char c[] = str1.toCharArray();

        System.out.print("开办日期为");
        for (int i = 0; i < str1.length(); ++i) {
            if (c[i] >= '0' && c[i] <= '9')
                System.out.print(c[i]);
        }

        System.out.println();

        String str2 = "MLDNJAVA";
        System.out.println(str2);
        String E = str2.replaceAll("JAVA", "J2EE");
        System.out.println(E);

        System.out.println("第八个字符为" + c[7]);
        for (int i = 0; i < str1.length(); ++ i) {
            if (c[i] != '0')
                System.out.print(c[i]);
        }
        System.out.println();

        String str3 = "Java 技术学习班 20070326 MDLN 老师";
        System.out.println(str3);
        char m[] = str3.toCharArray();
        for (int i = 0; i < str3.length(); ++ i) {
            if (m[i] != ' ')
                System.out.print(m[i]);
        }
        System.out.println();

        Scanner s = new Scanner(System.in);
        String str4 = new String();
        str4 = s.next();
        System.out.print("ta的出生日期为" + str4.substring(6, 14));

        s.close();
    }
}
