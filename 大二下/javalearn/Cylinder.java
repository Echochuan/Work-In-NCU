//以下为实验四的内容
import java.util.Scanner;

public class Cylinder {
    public static void main(String[] args) {
      float r,h,s,v;
      final float PI = 3.14f;
      Scanner reader = new Scanner(System.in);
      System.out.print("请输入底面半径: ");
      r = reader.nextFloat();
      System.out.print("请输入高: ");
      h = reader.nextFloat();
      s = PI * r * r;
      v = PI * r * r * h;
      System.out.print("该圆柱体的底面积是: " + s + ",体积是: " + v);
      reader.close();
    }
}