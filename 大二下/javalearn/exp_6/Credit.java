package exp_6;

/*
    首先读取对应路径所在的文件，
    然后调用类的方法读取其中的数并进行求和运算，得出总分
    最后再将该数据写入需要写入的文件即可
 */

import java.io.*;
import java.util.Scanner;

public class Credit {
    //设置类用其中的方法读取并计算总分
    public static class Sum {
        public int Score(String str){
            Scanner scanner = new Scanner(str);
            scanner.useDelimiter("[^0123456789.]+");
            int sum = 0;
            while (scanner.hasNext()){
                try {
                    int i = scanner.nextInt();
                    System.out.println(i);
                    sum = sum + i;
                }catch(Exception e){
                    scanner.next();
                }
            }
            return sum;
        }
    }

    public static void main(String[] args) {
        //初始化
        FileReader fileReader = null;
        FileWriter fileWriter = null;
        BufferedReader bufferedReader = null;
        BufferedWriter bufferedWriter = null;

        try {
            fileReader = new FileReader("/Users/sairen/javalearn/exp_6/cre.txt");
            fileWriter = new FileWriter("/Users/sairen/javalearn/exp_6/newCre.txt");
            bufferedReader = new BufferedReader(fileReader);
            bufferedWriter = new BufferedWriter(fileWriter);
            String b;
            while ((b = bufferedReader.readLine()) != null) {
                System.out.println(b);

                Sum s = new Sum();
                int i = s.Score(b);

                bufferedWriter.write(b + "总分：" + i);
                bufferedWriter.newLine();
            }
        } catch(IOException e){
            e.printStackTrace();
        } finally{
            try {
                assert fileReader != null;
                fileReader.close();
                assert bufferedWriter != null;
                bufferedWriter.flush();
                fileWriter.close();
                bufferedReader.close();
                bufferedWriter.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}

