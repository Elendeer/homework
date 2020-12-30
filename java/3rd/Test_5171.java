/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:59:35
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-31 00:43:51
 * @Description  :
*********************************************/

class Address {
    String m_country = null;
    String m_prov = null;
    String m_city = null;
    String m_street = null;
    String m_postcode = null;

    public void setCountry(String country) {
        this.m_country = country;
    }

    public void setProvince(String province) {
        this.m_prov = province;
    }

    public void setCity(String city) {
        this.m_city = city;
    }

    public void setStreet(String street) {
        this.m_street = street;
    }

    public void setPostcode(String postcode) {
        this.m_postcode = postcode;
    }
    public void print(){
        System.out.println("country is " + m_country);
        System.out.println("province is " + m_prov);
        System.out.println("city is " + m_city);
        System.out.println("street is " + m_street);
        System.out.println("postcode is " + m_postcode);
    }
}

public class Test_5171 {
    public static void main(String[] args) {
        Address A = new Address();

        A.setCountry("China");
        A.setProvince("Fujian");
        A.setCity("Sanming");
        A.setStreet("ninghua");
        A.setPostcode("365400");

        A.print();
    }
}
