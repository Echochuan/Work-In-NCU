package chapter2;

/*
    第二章练习题2 计算圆柱体体积
 */

import java.util.Scanner;

public class bulk {
    public static void main(String[] args) {
        System.out.print("Enter the radius and length of a cylinder: ");
        Scanner input = new Scanner(System.in);

        double a = input.nextDouble();
        double b = input.nextDouble();

        System.out.print("The area is " + Math.PI * a * a);
        System.out.println();
        System.out.print("The volume is " + Math.PI * a * a * b);

    }
}
