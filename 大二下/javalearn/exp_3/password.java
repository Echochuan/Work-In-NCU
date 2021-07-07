package exp_3;

/*
    根据题意，用户所输入的密码需要满足三个条件；
    首先将用户输入的密码每一位都存入数组里，判断数组的长度从而判断位数是否满足要求
    然后再通过正则表达式对数组每一位进行判定，看是否有违法字符
    如果以上都合法，则没有问题，只要有一项违法，就输出错误信息
 */


import java.awt.*;
import java.util.Scanner;

public class password {

    //判断内容是否是数字字母下划线
    public static boolean rule2(String value) {
        String regex = "^\\w+$";
        return value.matches(regex);
    }

    //判断内容是否包含数字
    public static int rule3(String value, int n) {
        String regex =  "^[0-9]*$";
        if (value.matches(regex)){
            return n+1;
        }
        else return n;
    }

    public static void main(String[] args) {
        System.out.print("输入你的密码：");
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        scanner.close();
        char[] Arr = str.toCharArray();

        //使用n来对数字的个数进行计数，使用ruler对密码是否合法进行判定
        int n = 0;
        boolean ruler = true;

        for (char c : Arr) {

            //对是否含有八个以上字符进行判断
            if (Arr.length < 8) {
                ruler = false;
                break;
            }

            //对是否包含数字字母下划线进行判断
            boolean rule = rule2(String.valueOf(c));
            if (!rule) {
                ruler = false;
                break;
            }

            //判断是否含有两个以上的数字
            n = rule3(String.valueOf(c), n);
        }
        if (n < 2) {
            ruler = false;
        }

        //判定密码是否合法，如果不合法则输出错误信息
        if (!ruler) {
            System.out.println("Invalid Password");
        }
        else {
            System.out.println("Valid Password");
        }

    }
}
