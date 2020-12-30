/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 22:21:15
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 22:55:09
 * @Description  :
*********************************************/
public class Test_3710 {
    public static void main(String[] args) {
        for (int i = 1; i <= 1000; ++ i){
            if (i % 3 == 0 && i % 5 == 0 && i % 7 == 0) {
                System.out.println(i);
            }
        }
    }
}
