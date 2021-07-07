public class Computer {

    static class CPU {
        int speed;

        CPU(){}

        int getSpeed() {
            return speed;
        }

        int setSpeed(int m) {
            return speed = m;
        }
    }

    static class HardDisk {
        int amount;

        HardDisk(){};

        int getAmount() {
            return amount;
        }

        int setAmount(int m) {
            return amount  = m;
        }
    }

    static class PC {
        CPU cpu;
        HardDisk HD;

        void setCPU(CPU c) {
            cpu = c;
        }

        void setHardDisk(HardDisk h) {
            HD = h;
        }

        void show() {
            System.out.print("CPU的速度为 " + cpu.getSpeed() + " HD的容量为 " + HD.getAmount());
        }

    }

    static class Test {
        public static void main (String [] args) {
            CPU cpu = new CPU();
            cpu.setSpeed(2200);

            HardDisk disk = new HardDisk();
            disk.setAmount(200);

            PC pc = new PC();
            pc.setCPU(cpu);
            pc.setHardDisk(disk);
            pc.show();
        }
    }
}
