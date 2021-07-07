package exam;

import java.util.Scanner;

public class exam1 {

    public static class Test {
        public static void main(String[] args) {
            Queue queue = new Queue();
            // 获取用户输入的整数
            System.out.print("Enter an integer: ");
            Scanner input = new Scanner(System.in);
            int a = input.nextInt();
            int b = a;//将最初值储存
            // 查找并存储该正整数的所有最小因子
            int i;
            for(i=2;i<=a;)
            {
                if (a % i == 0) {
                    queue.enqueue(i);
                    a /= i;
                } else
                    i++;//因为求的是最小因子，所以只有在i小的时候不能除尽，才进行i加一的操作，
            }
            // 显示因子
            System.out.print("The factors for " + b + " is: ");
            for (int num = 0; num < queue.elements.length; num++) {
                if (queue.elements[num] != 0) {
                    System.out.print(queue.elements[num] + " ");
                }
            }
        }
    }

    static class Queue {
        private int[] elements;
        private int size;
        /** 构造一个默认大小为 20 的 Queue*/
        public Queue() {
            elements = new int[20];
        }
        /** 将一个新的整数添加到 Queue */
        public void enqueue(int value) {
            //如果size比原内容大，就扩大两倍的长度
            if (size >= elements.length) {
                int[] temp = new int[elements.length * 2];
                System.arraycopy(elements, 0, temp, 0, elements.length);
                elements = temp;
            }
            elements[size++] = value;
        }
        /** 从 Queue 中删除一个元素并返回该元素 */
        public int dequeue() {
            int v = elements[0];

            for (int i = 0; i < size - 1; i++) {
                elements[i] = elements[i++];
            }
            size--;
            return v;
        }
        /** 判断 Queue 是否为空 */
        public boolean empty() {
            return size==0;
        }
    }

}
