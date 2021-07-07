package chapter5;

/*
    统计正数和负数的个数然后计算这些数的平均值
    读取键盘中收到的数 然后判断它是否为0，如果不为零，则将其存储进数组；如果为零，则结束循环。
    将输入的数据按照空格分割并加入数组，
 */

import java.util.Scanner;

public class test5_1 {
    public static void main(String[] args) {
        System.out.print("Enter an integer, the input ends if it is 0: ");
        Scanner input = new Scanner(System.in);
        String in = input.nextLine();
        String[] arr = in.split(" ");
        int[] array = new int[arr.length];
        for(int i = 0 ; i < array.length ; i++){

            array[i] = Integer.parseInt(arr[i]);
        }

        int zheng = 0;
        int fu = 0;
        double total = 0.0;

        for (int i = 0; i < arr.length ; i++) {
            total = total + array[i];
            if (array[i] > 0) {
                zheng++;
            }
            else if (array[i] < 0) {
                fu++;
            }
            else {
                break;
            }
        }

        double average = total / (arr.length-1);

        if (total == 0.0) {
            System.out.println("No number are entered except 0");
        }
        else {
            System.out.println("The number of positives is " + zheng);
            System.out.println("The number of negatives is " + fu);
            System.out.println("The total is " + total);
            System.out.println("The average is " + average);
        }
    }
}
