package exp;

import java.util.Scanner;

public class calendar {

    //判断闰年
    public static  int leap(int year){
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 1;
        } else return 0;
    }


    //通过（年份总和+基准天）%7计算年份的第一天
    public static int  firstDayOfYear(int year) {
        int baseYear = 2000;
        int firstDay = 6;
        int i = 2000;
        int total = 0;
        for (i = baseYear; i < year; i++)
            total = total + 365 + leap(i);
        return (total + firstDay) % 7;
    }

    //判断月份的第一天
    public static int firstDayOfMonth(int year,int month, int firstYear){
        int[][] mon = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
        int total = 0;
        int i = 0;
        for (i = 1; i < month; i++)
            total = total + mon[leap(year)][i];
        return (total + firstYear)%7;
    }

    //对日历进行展示
    public static void show(int year,int month,int firstMonth){
        int[][] mon = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
        int i = 0;
        System.out.println("\t"+ month+ " "+ year);
        System.out.println("——————————————————");
        System.out.println("Mon  Tue  Wen  Thu  Fri  Sat  Sun");
        if(firstMonth == 0) {
            System.out.print("                              ");
        }
//        空出第一天之前的空格
        for(i=0; i<firstMonth-1; i++) {
            System.out.print("      ");
        }
        for (i=1; i<=mon[leap(year)][month]; i++) {
            System.out.print(String.format("%-5d", i));
            if ((firstMonth - 1 + i) % 7 == 0) System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {

        System.out.print("输入年份");
        Scanner input = new Scanner(System.in);
        int year = input.nextInt();

        System.out.print("输入月份");
        Scanner Input = new Scanner(System.in);
        int month = Input.nextInt();

        int firstYear = firstDayOfYear(year);
        int firstMonth = firstDayOfMonth(year,month,firstYear);
        show(year,month,firstMonth);
    }
}
