package chapter8;
import java.util.Scanner;

public class test8_13 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int row = 0, column = 0;
        System.out.print("请输入行数、列数：");
        row = input.nextInt();
        column = input.nextInt();
        int[][] nums = new int[row][column];
        System.out.println("请输入数组中的值：");
        for(int i  = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                nums[i][j] = input.nextInt();
                if (j == column-1) {
                    System.out.println();
                }
            }
        }
        System.out.println("有4个连续相等的数字？" + isConsecutiveFour(nums));
    }
    public static boolean isConsecutiveFour(int[][] values) {
        boolean result = false;
        for(int i = 0; i < values.length; i++) {//行遍历
            for(int j = 0; j < values[0].length; j++) {//列遍历
                try{
                    if (j <= 3) {
                        if ((values[i][j] == values[i][j + 1] &&
                                values[i][j + 1] == values[i][j + 2] &&
                                values[i][j + 1] == values[i][j + 3]) ||
                                (values[i][j] == values[i + 1][j] &&
                                        values[i + 1][j] == values[i + 2][j] &&
                                        values[i + 1][j] == values[i + 3][j]) ||
                                (values[i][j] == values[i + 1][j + 1] &&
                                        values[i + 1][j + 1] == values[i + 2][j + 2] &&
                                        values[i + 1][j + 1] == values[i + 3][j + 3])) {
                            result = true;
                        }
                    } else {
                        if ((values[i][j] == values[i][j + 1] &&
                                values[i][j + 1] == values[i][j + 2] &&
                                values[i][j + 1] == values[i][j + 3]) ||
                                (values[i][j] == values[i + 1][j] &&
                                        values[i + 1][j] == values[i + 2][j] &&
                                        values[i + 1][j] == values[i + 3][j]) ||
                                (values[i][j] == values[i + 1][j + 1] &&
                                        values[i + 1][j + 1] == values[i + 2][j + 2] &&
                                        values[i + 1][j + 1] == values[i + 3][j + 3]) ||
                                (values[i][j] == values[i - 1][j - 1] &&
                                        values[i - 1][j - 1] == values[i - 2][j - 2] &&
                                        values[i - 1][j - 1] == values[i - 3][j - 3])) {
                            result = true;
                        }
                    }
                } catch (ArrayIndexOutOfBoundsException e) {
                }
            }
        }
        return result;
    }
}
