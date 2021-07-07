class PrintChar {
    public static void main(String[] args){
        //特殊字符‘ ’（字符代码点：u+1D307），在Java中的表示为"\uD834\uDF07"
        String n = "\uD834\uDF07";
        for(int i = 0; i < 10; i++) {
            System.out.print(n + "\t");
        }
    }
}