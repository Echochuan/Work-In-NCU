//下面是实验一与实验二的内容
//HelloWorld.java
// import java.util.Date;
// public class HelloJava {
//         public static void main(String[] args) {
//                      System.out.println("Hello World!");
//            System.out.println("现在时间是：" + new Date().toString());
//         }
//  }

 //HelloTest.java
import java.util.Scanner;
public class HelloJava {
        public static void main(String[] args) {
          System.out.println("Please input your name:");
			Scanner input = new Scanner (System.in);
			String yourName = input.next();    
            System.out.println("Hello," + yourName + "!");
            input.close();
        }
 }
