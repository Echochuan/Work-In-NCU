package exp;

class GreekAlphabet {
    public static void main(String[] args) {
        char start = 'α', end = 'ω';

        //使用Int转换，拿到开始和结束时候的unicode位置
        int positionOfStart = (int)start;
        int positionOfEnd = (int)end;

//        System.out.println("希腊字母\'α\'在Unicode表中的顺序位置: " + positionOfStart);
        System.out.println("希腊字母表：");
        for (int i = positionOfStart; i <= positionOfEnd; i++) {
            //i做char型转换运算，并将结果赋值给C
            char c = (char)i;
            System.out.print("\t" + c);
            if ((i - positionOfStart + 1) % 10 == 0)
                System.out.println("");
        }
    }
}