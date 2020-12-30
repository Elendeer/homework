/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:10:16
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 23:54:00
 * @Description  :
*********************************************/
import java.util.Scanner;

public class Test_465 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        final int length = 10;
        int [] a = new int[length];

        for (int i = 0; i < length;i++){
            a[i] = s.nextInt();
        }

        int num= s.nextInt();

        boolean flag = false;
        for (int i = 0; i < length; ++ i ) {
            if (a[i] == num) {
                System.out.println("Yes.");
                flag = true;
                break;
            }
        }

        if (!flag) {
            System.out.println("No.");
        }

        s.close();
    }
}
