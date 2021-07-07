package exp_5;

/*
    首先编写各个类，然后编写随机生成动物类型的方法和随机编号的方法。赋予不同动物有独有的属性
    然后再根据随机生成动物类型所得的字符串创建相对应的对象，然后调用相对应的展示信息的方法输出并重复一百次上述步骤即可。
 */

import java.lang.reflect.InvocationTargetException;
import java.util.Random;
public class Test {
    public static void main(String[] args) throws InstantiationException, IllegalAccessException, ClassNotFoundException, NoSuchMethodException, InvocationTargetException {
        String []id = new String [100];
        randomId(id,5);
        Random r = new Random();
        String species = "";
        for(int i = 0;i<100;i++) {
            species = randomSpecies(r.nextInt(4));
            Class<Animal> animal1 = (Class<Animal>) Class.forName(species); //ERROR！
            Animal animal = animal1.getDeclaredConstructor().newInstance();
            animal.setAttr(id[i]);
            animal.showMessage();
            animal.showTalent();
        }
    }

    public static String randomSpecies(int i) {  //随机动物类型
        switch(i) {
            case 0:
                return "Bird";
            case 1:
                return "Insect";
            case 2:
                return "Reptile";
            case 3:
                return "Fish";
            default:
                return "";
        }
    }

    public static void randomId(String[] str,int idLen) {
            char []temp = new char[10];
            int index = 0;

            for(int i = 48;i<58;i++) {
                temp[index++] = (char)i;
            }

            Random r = new Random();  //随便取数字

        @SuppressWarnings("unused")
            String id = "";
        for(int i = 0;i < str.length;i++) {
            for(int j = 0;j<idLen;j++) {
                index = r.nextInt(10);
                id += temp[index];
            }
            str[i] = id;
            id = "";
        }
    }
}

abstract class Animal {
    protected String id;
    public String type;
    public abstract void showTalent();

    public void showMessage() {
        System.out.println("我的编号是 " + id + " ,类别是 " + type);
    }

    public void setAttr(String id) {
        this.id = id;
    }
}

class Bird extends Animal {
    public Bird() {
        type = "Bird";
    }

    public Bird(String id) {
        type = "Bird";
        this.id = id;
    }

    public void showTalent(){
        System.out.println("我能飞");
    }
}

class Insect extends Animal {
    public Insect() {
        type = "Insect";
    }

    public Insect(String id) {
        type = "Insect";
        this.id = id;
    }

    public void showTalent() {
        System.out.println("我很小");
    }
}

class Reptile extends Animal {
    public Reptile() {
        type = "Reptile";
    }

    public Reptile(String id) {
        type = "Reptile";
        this.id = id;
    }

    public void showTalent() {
        System.out.println("我很强壮");
    }
}

class Fish extends Animal {
    public Fish() {
        type = "Fish";
    }

    public Fish(String id) {
        type = "Fish";
        this.id = id;
    }

    public void showTalent() {
        System.out.println("我能游泳");
    }
}


