/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 22:21:15
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 22:34:09
 * @Description  :
*********************************************/

public class Test_376 {
    public static void main(String[] args) {
        int sum = 0;
        for (int i = 13; i < 1000; i = i + 20) {
            sum += i;
        }
        for (int i = 23; i < 1000; i = i + 20) {
            sum -= i;
        }
        System.out.println(sum);
    }
}
