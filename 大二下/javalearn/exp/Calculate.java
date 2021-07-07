package exp;

import java.util.Scanner;

/*
    按照平年来计算的话，一年中的1，3，5，7，8，10，12月为31天
    4，6，9，11为30天
    2月为28天

    和平年不同的是，闰年的2月为29天

    所以可以首先判断月份是否是2月，如果不是，则直接判断得出是否为31天，如果是，则对年份进行判断
 */


public class Calculate {

    //判断是否为闰年
    public static int leap(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 29;
        } else return 28;
    }

    public static void main(String[] args){
        int days = 0;
        //分别记录用户输入的年月
        System.out.print("Enter a year:");
        Scanner input = new Scanner(System.in);
        int year = input.nextInt();

        System.out.print("Enter a month:");
        Scanner Scan = new Scanner(System.in);
        String month = Scan.next();

        switch (month) {
            case "Apr" :

            case "Jun" :

            case "Sep" :

            case "Sept" :

            case "Nov" :
                days = 30;
                break;

            case "Jan" :

            case "Mar" :

            case "Jul" :

            case "Aug" :

            case "Oct" :

            case "Dec" :
                days = 31;
                break;

            case "Feb" :
                days = leap(year);
                break;
        }
        if (days == 0) {
            System.out.println(month + " is not a correct month name");
        } else {
            System.out.println(month + " " + year + " has " + days + " days");
        }
    }

}
