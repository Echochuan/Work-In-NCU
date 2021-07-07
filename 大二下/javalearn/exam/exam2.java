package exam;

import java.util.Scanner;

public class exam2 {
    //生成一个随机的nxn的包含1与0的二维矩阵
    public static void displayMatrix(int n) {
        int[][] matrix = new int[n][n];
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                //随机为0或1
                matrix[i][j] = (int)(Math.random() * 2);

        //输出显示该矩阵
        for (int i = 0;i < n;i++) {
            for (int j = 0; j < n; j++)
                System.out.print(matrix[i][j] + " ");
            System.out.println();
        }

        //查找每一行的1的数量
        System.out.println("Each row counts(only 1):");
        int count = 0;
        for (int i = 0;i < n; i++) {
            for (int j = 0;j < n;j++) {
                if (matrix[i][j] == 1) {
                    count++;
                }
            }
            System.out.print(count + " ");
            count = 0;
        }

        System.out.println();

        //查找每一列的1的数量
        System.out.println("Each column counts(only 1):");
        for (int i = 0;i < n; i++) {
            for (int j = 0;j < n;j++) {
                if (matrix[j][i] == 1) {
                    count++;
                }
            }
            System.out.print(count + " ");
            count = 0;
        }

        System.out.println();

        //判断正对角线上的1的个数是否为n
        System.out.println("Is the number of 1's on the diagonal of the matrix equal to 4?");
        for (int i = 0;i < n; i++) {
            if (matrix[i][i] == 1) {
                count++;
            }
        }
        if (count == n) {
            System.out.println("True");
        }
        else {
            System.out.println("False");
        }

        //清空count
        count = 0;

        //判断负对角线上1的个数是否为n 3，0  2，1  1，2， 0，3
        System.out.println("Is the number of 1's on the back diagonal of the matrix equal to 4?");
        for (int i = 0;i < n; i++) {
            if (matrix[3-i][i] == 1) {
                count++;
            }
        }

        if (count == n) {
            System.out.println("True");
        }
        else {
            System.out.println("False");
        }
    }


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter n:");
        int n = input.nextInt();
        displayMatrix(n);
    }
}
