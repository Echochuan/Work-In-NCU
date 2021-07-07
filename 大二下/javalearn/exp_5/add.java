package exp_5;

/*
    将从键盘上读取的数存入a中，然后判断a是否为正确答案（14），如果是，则跳出循环，输出got it ，
    如果不是，则判断数组列表中是否含有该值，若是，则输出提示
    如果不是，则将该数加入数组列表中，并输出错误信息重新调用answer方法
 */

import java.util.ArrayList;
import java.util.Scanner;

public class add {
    public static void alreadyAdd(ArrayList<Integer> list, int num) {
        for (Integer integer : list) {
            if (integer == num) {
                System.out.println("You already entered " + num);
                break;
            }
        }
    }

    public static void answer(ArrayList<Integer> list) {
        Scanner input = new Scanner(System.in);

        int a = input.nextInt();
        while (a != 14) {
            alreadyAdd(list, a);
            list.add(a);
            System.out.print("Wrong answer. Try again. What is 5 + 9? ");
            answer(list);
            a = 14;
        }
    }

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>();

        System.out.print("what is 5 + 9? ");
        answer(list);
        System.out.println("You got it!");
    }
}
