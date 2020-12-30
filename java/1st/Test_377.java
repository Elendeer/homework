/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 22:21:15
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 22:47:01
 * @Description  :
*********************************************/
import java.util.Scanner;

public class Test_377 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.println("Input 2 num, swap them :");
        System.out.println("num1 : ");
        double num1 = s.nextDouble();
        System.out.println("num2 : ");
        double num2 = s.nextDouble();

        double temp = num1;
        num1 = num2;
        num2 = temp;
        System.out.println("num1 : " + num1);
        System.out.println("num2 : " + num2);

        s.close();
    }
}
