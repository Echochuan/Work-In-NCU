package exp;

import java.util.Scanner;

public class ChineseChange {
    public static void main(String args[]) {
            int i = -1, w, intFee;
            double money = 0;
            String outtxt = "";//用来记录分析结果
            String[] digits = {"分", "角", "元", "拾", "佰", "仟", "萬", "拾萬", "佰萬", "仟萬", "亿"};
            String[] num = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
            boolean method;//记录输入的浮点数是否为整数，整数记为true

            try {//执行可能发生异常的语句
                Scanner reader = new Scanner(System.in);
                System.out.println("请输入需要转换的数值");
                money = reader.nextDouble();
                if (money % 1 == 0) {//判断浮点数是否为整数，整数记为true
                    method = true;
                    outtxt = "整" + outtxt;
                    i = 1;
                } else {
                    method = false;
                    i = -1;
                }

                //如果为整数，则直接转换为int做除法，否则记录两位小数（角和分）
                if (method) {
                    intFee = (int) money;
                } else {
                    intFee = (int) (money * 100);
                }

                //循环判断并记录应该输出的值
                //如果为中间段有0且在个位，则添加一个元
                //中间段有0且不在个位，不添加0

                while (intFee != 0) {
                    w = intFee % 10;
                    i += 1;
                    if (w != 0) {
                        outtxt = num[w] + digits[i] + outtxt;
                        intFee /= 10;
                    } else if (w == 0 && i == 2) {
                        outtxt = digits[i] + outtxt;
                        intFee /= 10;
                    } else {
                        intFee /= 10;
                    }
                }
                System.out.println(outtxt);
            }
            //预防错误情况
            catch (NumberFormatException e) {
                outtxt = "请输入正确的数额!";
                System.out.println(outtxt);
            }
    }
            }


