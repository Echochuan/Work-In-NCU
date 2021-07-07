package exp;/*
    首先录入用户输入的字母，然后将输入的字符串改为数组的形式存储。
    数组的第一个元素代表专业，对其进行判断得出相对应的专业信息
    数组的第二个元素代表年级，对其进行判断得出相对应的年级信息
    将以上内容输出即可
 */

import java.util.Scanner;

public class MajorAndGrade {
    public static void main(String[] args) {
        //录入用户输入的字符
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter two characters：");
        String str = scanner.nextLine();
        scanner.close();
        char[] Arr = str.toCharArray();

        String major = String.valueOf(Arr[0]);
        switch (major) {
            case "M" :
                major = "Mathematics";
                break;

            case "C" :
                major = "Computer Science";
                break;

            case "I" :
                major = "Information Technology";
                break;
        }

        String grade = String.valueOf(Arr[1]);
        switch (grade) {
            case "1" :
                grade = " Freshman";
                break;

            case "2" :
                grade = " Sophomore";
                break;

            case "3" :
                grade = " Junior";
                break;

            case "4" :
                grade = " Senior";
                break;
        }

        if (major.equals(String.valueOf(Arr[0]))) {
            System.out.println("Invalid input");
        }else if (grade.equals(String.valueOf(Arr[1]))) {
            System.out.println("Invalid Input");
        }else {
            System.out.println(major + grade);
        }
    }
}
