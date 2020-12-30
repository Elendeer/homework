/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:10:16
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 23:57:14
 * @Description  :
*********************************************/

public class Test_466 {
    public static void main(String[] args) {
        int [] a = new int [10];

        for (int i = 0; i < 10; ++ i ) {
            a[i] = i;
        }

        for (int i = 0; i < 10; ++ i ) {
            System.out.print(a[i] + " ");
        }
        System.out.println("");

        for (int i = 9; i >= 0; -- i ) {
            System.out.print(a[i] + " ");
        }
    }
}
