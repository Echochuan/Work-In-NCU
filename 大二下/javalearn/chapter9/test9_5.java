package chapter9;

import java.util.GregorianCalendar;

public class test9_5 {
    public static void main(String[] args) {
        GregorianCalendar now = new GregorianCalendar();

        System.out.println("当前年月日为 " + now.get(GregorianCalendar.YEAR) + " " + now.get(GregorianCalendar.MONTH) + " " + now.get(GregorianCalendar.DAY_OF_MONTH));

        now.setTimeInMillis(1234567898765L);

        System.out.println("对应年月日为 " + now.get(GregorianCalendar.YEAR) + " " + now.get(GregorianCalendar.MONTH) + " " + now.get(GregorianCalendar.DAY_OF_MONTH));
    }
}
