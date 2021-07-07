package exp_4;

/*
    分别创建两个角色的类，并定义其默认的体力
    之后在fight方法中使用random定义造成的伤害，将其与对方的体力做减法运算
    当某次fight之后，双方有一方的体力为负数之后结束循环并输出对应的结果
 */

import java.util.Random;

public class Game {

    //创建角色Titan类
    static class Titan {
        int Energy;

        Titan() {
            Energy = 800;
        }

        Titan(int e) {
            Energy = e;
        }

        void fight(Zues z) {
            int track = (int)(Math.random()*91)+10;
            z.Energy = z.Energy - track;
            System.out.println("Titan攻击Zues，产生" + track + "点攻击值，Zues当前Energy值为" + z.Energy);
        }
    }

    //创建角色Zues类
    static class Zues {
        int Energy;

        Zues() {
            Energy = 1000;
        }

        Zues(int x) {
            Energy = x;
        }

        void fight(Titan t) {
            Random r = new Random();
            int track = r.nextInt(70);
            t.Energy = t.Energy - track;
            System.out.println("Zues攻击Titan，产生" + track + "点攻击值，Titan当前Energy值为" + t.Energy);
        }
    }


    public static void main(String[] args) {
        Titan T = new Titan();
        Zues Z = new Zues();
        double i = 0;

        //判断T和Z的体力是否大于0，如果均大于0，则执行fight方法，如果T小于等于0，则输出结果，并跳出循环。

        while (T.Energy > 0 && Z.Energy > 0) {
            T.fight(Z);
            Z.fight(T);
            if (T.Energy <= 0) {
                System.out.println("Titan的Energy值为" + T.Energy +"，已经失败，获胜者是Zues");
            }
            else if (Z.Energy <= 0) {
                System.out.println("Zues的Energy值为" + Z.Energy + "，已经失败，获胜者为Titan");
            }
        }
    }
}
