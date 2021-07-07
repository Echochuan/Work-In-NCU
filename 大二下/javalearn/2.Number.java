import java.util.Scanner;
class Number {
    public static void main(String args[]) {
        int number = 0, d5, d4, d3, d2, d1;
        Scanner reader = new Scanner(System.in);
        System.out.println("输入一个1至99999之间的数");
        number = reader.nextInt();
        if (number <= 99999 && number >= 1) {
            //取出每一位的数字
            d5 = number / 10000;
            d4 = number % 10000 / 1000;
            d3 = number % 1000 / 100;
            d2 = number % 100 / 10;
            d1 = number % 10;
            if (number >= 10000) {//判断number是5位数的条件
                System.out.println(number + "是5位数");
                if (d1 == d5 && d2 == d4) {//判断number是回文数的条件
                    System.out.println(number + "是回文数");
                }
                else {
                    System.out.println(number + "不是回文数");
                }
            }
            else if (number >= 1000) {//判断number是4位数的条件
                System.out.println(number + "是4位数");
                if (d1 == d4 && d2 == d3) {//判断number是回文数的条件码
                    System.out.println(number + "是回文数");
                }
                else {
                    System.out.println(number + "不是回文数");
                }
            }
            else if (number >= 100){//判断为3位数
                System.out.println(number + "是3位数");
                if (d1 == d3) {//判断number是回文数的条件码
                    System.out.println(number + "是回文数");
                }
                else {
                    System.out.println(number + "不是回文数");
                }
            }
            else if(number >= 10) {
                System.out.println(number + "是2位数");
                if (d1 == d2) {//判断number是回文数的条件码
                    System.out.println(number + "是回文数");
                }
                else {
                    System.out.println(number + "不是回文数");
                }
            }
            else {
                System.out.println(number + "是1位数");
                System.out.println(number + "是回文数");
            }
        }
    }
}