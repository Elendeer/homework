/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 22:21:15
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 22:50:54
 * @Description  :
*********************************************/
import java.util.Scanner;

public class Test_378 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int num1 = s.nextInt();
        int num2 = s.nextInt();
        int num3 = s.nextInt();

        int max = num1;
        if (num2 > max) max = num2;
        if (num3 > max) max = num3;

        System.out.println(max);

        s.close();
    }
}
