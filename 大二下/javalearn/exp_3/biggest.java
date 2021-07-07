package exp_3;

/*
    首先输入行数，根据用户输入的行数生成一个二维数组。
    接下来，如果用户输入n，则输入时，每n个一次换行，对数组对应位置的值赋值
    记录方阵的数值，以便于输出最大块
 */


import java.util.Scanner;

public class biggest {

    //用于查询最大块的函数
    public static int[] check(int[][]a, int n) {
        int max = 1, x = 0, y = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    //求出上方、左方以及上左的最小值
                    int min = Math.min(a[i - 1][j], a[i][j - 1]);
                    min = Math.min(a[i - 1][j - 1], min);
                    a[i][j] = min + 1;
                    //记录方阵右下角的位置
                    if(max < a[i][j])
                    {
                        max = a[i][j];
                        x=i;y=j;
                    }
                }
            }
        }
        //获取所得结果之后放入数组，以便展示
        int[] Arr = {max,x-max+1,y-max+1};
        return Arr;
    }


    public static void main(String[] args) {
        System.out.print("Enter the number of rows in the square matrix：");
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        int [][] arr = new int[n][n];

        //用户输入方阵
        for (int i = 0; i < n; i++){

            Scanner scanner = new Scanner(System.in);
            String str = scanner.nextLine();
            String s[]  = str.split(" ");

            for (int j = 0; j < n; j++){
                arr[i][j] = Integer.parseInt(s[j]);
            }
        }

        int[] key = check(arr, n);
        System.out.print("The maximum square submatrix is at ("+key[1]+","+key[2]+")  ");
        System.out.println("with size "+key[0]);

    }
}
