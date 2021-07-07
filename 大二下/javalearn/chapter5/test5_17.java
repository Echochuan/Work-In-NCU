package chapter5;/*
    每一行有2*n+1个数字(从0计数)
    一共有n行
    使用二维数组遍历输出所需要的结构
    首先定义一个数组[n][2*n+1]
    将各个数据存入数组的对应位置
    每个位置的大小应该是总行数与当前行数的差的差加一
    金字塔的数据呈一个类似镜面，所以我们只需要考虑一边，另一边只需要对其取绝对值即可
    由于每一行的第一个数总是和当前的行数相同，于是只要用行数表示列数，再递增即可确定数的位置
    最后遍历输出
 */

import java.util.Scanner;

public class test5_17 {
    public static void main(String[] args) {
        System.out.print("Enter the number of the lines:");
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = 2*n+1;

        int i,j;
        int[][] arr = new int[n][m];
        for (i = 0;i < n; i++)
            for (j = n-i;j <= n+i; j++)     //n-i是总行数与当前行数的差 n+i是总行数与当前行数的和
                if (n-j > 0){
                    arr[i][j] = (n-j) + 1;
                }
                else {
                    arr[i][j] = -(n-j) + 1;
                }

        for (i = 0;i < n;i++) {
            for (j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    System.out.print(" ");
                }else {
                    System.out.print(arr[i][j]);
                }
            }
            System.out.println();
        }


    }
}
