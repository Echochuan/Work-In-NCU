package chapter4;

/*
    字符串处理
 */

import java.util.Scanner;

public class test4_20 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入需要处理的字符串： ");

        String a = input.next();

        System.out.print("长度为 " + a.length() + " 第一个字符为 " + String.valueOf(a.charAt(0)));

    }
}
