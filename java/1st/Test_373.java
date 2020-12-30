/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 22:21:15
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 22:29:08
 * @Description  :
*********************************************/

public class Test_373 {
    public static void main(String[] args) {
        int a = 100, b = 101, c = 302;

        int max = a;

        if (b > max) max = b;
        if (c > max) max = c;

        System.out.println("Max : " + max);
    }
}
