/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:10:16
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 23:21:05
 * @Description  :
*********************************************/
import java.math.BigInteger;

public class Test_461 {
    public static void main(String[] args) {
        BigInteger count = new BigInteger(String.valueOf(0));

        for (int i = 1; i <= 30; ++ i ){
            count = count.add(factorial(i));
        }
        System.out.println(count);
    }

    public static BigInteger factorial(int t){
        BigInteger fact = new BigInteger(String.valueOf(1));

        for (int i = 1; i <= t; ++ i){
            fact = fact.multiply(BigInteger.valueOf(i));
        }

        return fact;
    }
}