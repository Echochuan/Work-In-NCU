package exp_3;

/*
    首先用户需要输入这个序列的长度，通过这个长度来创造一个相对应长度的数组
    然后用户输入一个数字序列，我们需要对其判断是否已经排好序了
    那么就要将用户输入的序列放进一个数组表示
    然后从这个数组把各个元素拿出来进行排序，并依次将其放到另外一个数组里
    然后判断这两个数组是否是相同的
 */


import java.util.Arrays;
import java.util.Scanner;

public class sequence {
    public static void main(String[] args) {

        //用户输入序列的长度
        System.out.print("Enter the size of the list: ");
        Scanner input = new Scanner(System.in);
        int size = input.nextInt();

        //用户输入其序列，将序列中的各个数依次存进数组里
        System.out.print("Enter the contents of the list: ");
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        String[] user = str.split(" ");

        //对用户输入的序列进行遍历
        System.out.print("The list has " + size + " integers ");
        for (int i = 0; i < size; i++){
            System.out.print(user[i] + " ");
        }

        System.out.println();

        //将用户输入的序列放入另一个数组存放
        String[] answer = new String[size];
        if (size >= 0) System.arraycopy(user, 0, answer, 0, size);

        //对用户给出的序列进行升序排列
        Arrays.sort(user);

        System.out.println(Arrays.toString(user));
        System.out.println(Arrays.toString(answer));

        if (Arrays.equals(user, answer)) {
            System.out.println("The list is already sorted");
        }
        else {
            System.out.println("The list is not sorted");
        }

    }
}
