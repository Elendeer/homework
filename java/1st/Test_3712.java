/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 22:21:15
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 23:07:58
 * @Description  :
*********************************************/
public class Test_3712 {
    public static void main(String[] args) {
        for (int i = 1; i <= 5; ++ i ) {
            for (int j = 1; j <= 5 - i; ++ j ) {
                System.out.print(" ");
            }

            for (int j = 1; j <= i; ++ j ) {
                System.out.print("* ");
            }
            System.out.println("");
        }
    }
}
