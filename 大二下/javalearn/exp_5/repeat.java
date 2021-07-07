package exp_5;

/*
    首先将输入的字符串按照空格分割并转化为数字类型后依次存入数组，之后对数组调用removeDuplicate方法
    将每个数都分别和之后的数比较，如果相同，就删除后面的那个相同的元素。
 */

import java.util.ArrayList;
import java.util.Scanner;

public class repeat {
    public static void removeDuplicate(ArrayList<Integer> list) {
        for (int i = 0; i < list.size(); i++) {
            int a = list.get(i);
            for (int j = i+1; j < list.size(); j++) {
                if (a == list.get(j)) {
                    list.remove(j);
                }
            }
        }

        System.out.print("The distinct integers are ");
        for (Integer i : list) {
            System.out.print(i + " ");
        }
    }

    public static void main(String[] args) {
        ArrayList<Integer> nums = new ArrayList<Integer>();

        System.out.print("Enter 10 integers: ");

        Scanner input = new Scanner(System.in);
        while (input.hasNextLine()) {
            String[] str = input.nextLine().split(" ");
            for (String a : str) {
                nums.add(Integer.valueOf(a));
            }
            break;
        }

        removeDuplicate(nums);
    }
}
