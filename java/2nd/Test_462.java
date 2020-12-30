/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:10:16
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 23:57:48
 * @Description  :
*********************************************/
import java.util.Scanner;

public class Test_462 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int[] a = new int[10];

        int count = 0;
        for (int i = 0; i < 10; ++ i ){
            a[i] = s.nextInt();
            if (a[i] % 2 == 0) {
                ++ count;
            }
        }

        System.out.println("even : " + count);
        System.out.println("uneven : " + (10 - count));

        s.close();
    }
}
