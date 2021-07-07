package exp_5;

class SuperClass {
    int x;
    SuperClass() {
        x = 4;
    }
    void doSomething() {
        System.out.println("in SuperClass.doSomething:");
        System.out.println("x=" + x);
    }
}

class SubClass extends SuperClass {
    int x;
    SubClass() {
        super();
        x = 5;
        System.out.println("in SubClass:");
        System.out.println("x=" + x);
    }

    void doSomething() {
        super.doSomething();
        System.out.println("in SubClass.doSomething:");
        System.out.println("super.x=" + super.x + " sub.x=" + x);
    }
}

public class Inheritance {
    public static void main(String[] args) {
        SuperClass superA = new SubClass();
        superA.doSomething();
    }
}
