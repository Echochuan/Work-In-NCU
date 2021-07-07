package chapter7;

/*
    首先需要生成一个随机数，从而达到随机生成一个单词的效果
    取出这个单词，对他进行拆分，每个字母作为一个元素放进另一个数组2里
    设定一个新的数组3，根据单词的长度生成，每个元素都是*
    读取用户输入的字母，并将之与数组2逐位匹配，如果没有相匹配的，输出is not in the word，并计数元素+1
    如果有匹配的，那么就将这一位的值赋给数组3的对应元素，输出数组3

    以上的行为需要先判定数组3是不是等于数组2，如果不是则一直运行，如果是，则输出结果。
    结束后，判定y和n ,决定游戏是否重复。所以可以将上面的环节写成一个函数，这里就能直接调用
 */

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class test7_35 {

    //用于比较正确单词和用户猜测的单词是否一致
    public static boolean match(char[]a, String[]b) {
        String[] A = new String[a.length];
        for (int i = 0; i < a.length; i++){
            A[i] = String.valueOf(a[i]);
        }

        return Arrays.equals(A,b);
    }

    public static void loop(char[]a, String[]e, int time){
        //判定用户输入的字母是否与原单词匹配，如果是，则在已猜测的数组上显示

        //用于判断是否猜错的中间数
        int j = 0;

        //判定end与answer是否相等，如果相等，则进行猜测环节
        if (!match(a,e)){
//            System.out.println("尚未猜出答案 ");

            //读取用户输入
            System.out.print("请输入你认为单词含有的字母：");
            Scanner scanner = new Scanner(System.in);
            String str = scanner.nextLine();

            //对输入正确的位置进行赋值
            for (int i = 0; i < a.length; i++) {
                String answer = String.valueOf(a[i]);
                if (str.equals(answer)) {
                    e[i] = answer;
                    j++;
                }
            }

            if (j == 0) {
                time++;
            }

            System.out.print("现在单词的状态是：");
            for (String s : e) {
                System.out.print(s);
            }
            System.out.println();
            loop(a,e,time);
        }
        else {
            System.out.print("The word is ");
            for (String s : e) {
                System.out.print(s);
            }
            System.out.println(" 输错的次数为：" + time);
        }

    }

    public static void game() {
        //生成单词库
        String[] words = {"white", "blue", "yellow", "red", "purple"};

        //用于记录猜错的次数
        int time = 0;

        //生成包含正确单词的数组2
        Random r = new Random();
        int key = r.nextInt(words.length);
        char[] answer = words[key].toCharArray();


        //生成显示的数组3
        String[] end = new String[answer.length];
        for (int i = 0; i < answer.length; i++) {
            end[i] = "*";
        }

        //执行猜测环节
        loop(answer, end, time);

        //判断是否再来一次
        System.out.print("想要再来一次吗？（y/n）:");
        Scanner scanner = new Scanner(System.in);
        String choose = scanner.nextLine();

        if (choose.equals("y")) {
            game();
        }
        else {
            System.out.println("感谢你的使用");
        }
    }

    public static void main(String[] args) {
        game();
    }
}
