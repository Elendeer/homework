/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 22:21:15
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 23:03:22
 * @Description  :
*********************************************/

public class Test_3711 {
    public static void main(String[] args) {
        int sum = 0;
        for(int i = 1;i <= 20; ++ i ){
            int t = 1;
            for (int j = 1; j <= i; ++ j) {
                t *= j;
            }
            sum += t;
        }
        System.out.println(sum);
    }
}
