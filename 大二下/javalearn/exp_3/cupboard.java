package exp_3;

/*
    用-1表示关，用1表示开。于是创造一个数组来存放柜子的开关情况。最后检验时只要遍历，然后把值为1的元素的索引值提出即可
 */

public class cupboard {
    public static void main(String[] args) {

        //初始化柜子的情况（均为关）
        int[] array = new int[100];
        for (int i = 0; i < 100; i++) {
            array[i] = -1;
        }

        for (int stu = 0; stu < 100; stu++) {
            for (int i = stu; i < 100; i = i + stu + 1){
                array[i] = -1 * array[i];
            }
        }

        for (int i = 0; i < 100; i++) {
            if (array[i] == 1) {
                System.out.print(i+1 + " ");
            }
        }

    }
}
