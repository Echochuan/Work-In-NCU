package exp;

import java.util.Scanner;

public class Caipiao {
        public static void main(String[] args){
            //将s设置为用户所购买的号码
            int s = (int)(Math.random() * 900 + 100);
            System.out.print("请输入你的彩票编号");
            Scanner input = new Scanner(System.in);
            int id = input.nextInt();
            //限定号码为三位数
            if(id < 100 || id > 999)
            {
                System.out.println("error input");
                return;
            }

            //生成中奖号码
            int s_001 = s % 10;
            int s_010 = s / 10 % 10;
            int s_100 = s /100;
            int temp = -1;
            if(s_100 > s_010){
                temp = s_100;
                s_100 = s_010;
                s_100 = temp;
            }
            if(s_100 > s_001){
                temp = s_100;
                s_100 = s_010;
                s_100 = temp;
            }
            if(s_010 > s_001){
                temp = s_010;
                s_010 = s_001;
                s_001 = s_010;
            }
            System.out.println("中奖号码是： " + s_100 + s_010 + s_001);

            int id_001 = id % 10;
            int id_010 = id / 10 % 10;
            int id_100 = id /100;
            if(id_100 > id_010){
                temp = id_100;
                id_100 = id_010;
                id_010 = temp;
            }
            if(id_100 > id_001){
                temp = id_100;
                id_100 = id_010;
                id_010 = temp;
            }
            if(id_010 > id_001){
                temp = id_010;
                id_010 = id_001;
                id_001 = id_010;
            }
            if(s == id){
                System.out.println("你赢得了10000美元");
            }
            else if(s_001 == id_001 && s_010 == id_010 && s_100 == id_100)
                System.out.println("你赢得了3000美元");
            else if(s_001 == id_001 || s_001 == id_010 || s_001 == id_100 || s_010 == id_001 || s_010 == id_010 || s_010 == id_100 || s_100 == id_001 || s_100 == id_010 || s_100 == id_100)
                System.out.println("你赢得了1000美元");
            else
                System.out.println("没有中奖哦");
        }
}
