package exp_4;

/*
    首先创建复数类并定义其构造函数，之后再根据复数的计算方式即实数与实数相加减，虚数与虚数相加减从而定义加减的方法函数。
    最后在main中创建并使用即可
 */

public class complexNum {

    static class complex {
        double real;
        double imaginary;

        //定义构造
        complex(){
        }

        complex(double nowReal, double nowImaginary) {
            real = nowReal;
            imaginary = nowImaginary;
        }

        //实现复数与复数之间的加法计算
        String plus(complex num) {
            double addReal;
            double addImaginary;

            addReal = real + num.real;
            addImaginary = imaginary + num.imaginary;

            //区分实数部分是否为0的情况和虚数部分的正负情况
            if(addImaginary > 0) {
                if (addReal == 0) {
                    return " + " + addImaginary + "i";
                }
                else {
                    return addReal + " + " + addImaginary + "i";
                }
            }
            else if (addImaginary == 0) {
                return  addReal + " ";
            }
            else {
                if (addReal == 0) {
                    return addImaginary + "i";
                }
                else {
                    return addReal + addImaginary + "i";
                }
            }
        }

        //计算复数与实数之间的加法
        String plus(double x) {
            double plusReal = real + x;
            if (imaginary > 0) {
                return plusReal + " + " + imaginary + "i";
            }
            else if (imaginary == 0) {
                return plusReal + " ";
            }
            else {
                return plusReal + " " + imaginary;
            }
        }

        //计算复数与复数的减法
        String minus(complex num) {
            double subReal;
            double subImaginary;

            subReal = real - num.real;
            subImaginary = imaginary - num.imaginary;
            if (subImaginary > 0) {
                if (subReal == 0) {
                    return " + " + subImaginary + "i";
                }
                else{
                    return subReal + " + " + subImaginary + "i";
                }
            }
            else if (subImaginary == 0) {
                return  subReal + " ";
            }
            else {
                if (subReal == 0) {
                    return subImaginary + "i";
                }
                else {
                    return subReal + subImaginary + "i";
                }
            }
        }

        //计算复数与实数的减法计算
        String minus(double x) {
            double minReal = real - x;
            if (imaginary > 0) {
                return minReal + " + " + imaginary + "i";
            }
            else if (imaginary == 0) {
                return minReal + " ";
            }
            else {
                return minReal + " " + imaginary;
            }
        }
    }

        //定义一个打印方法
        static void prin(String x) {
            System.out.println(x);
        }

    public static void main(String args[]) {
        complex num1 = new complex(1, 1);
        complex num2 = new complex(1, -1);


        prin(num1.plus(num2));
        prin(num1.minus(num2));

    }
}
