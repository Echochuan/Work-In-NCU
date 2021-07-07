# coding=UTF-8
#!/usr/bin/env python3
import random

class people():
    def __init__(self,name,sex,age):
        self.name=name
        self.age=age
        self.sex=sex

        count = 0

        print('name:'+str(self.name)+',age:',str(self.age)+'sex::'+str(self.sex))

class grade():
    def __init__(self):
        competitor_grade[8]
        sum_judge_eight = 0
        sum_judge_six = 0
        i = 0
        a = random.randint(0,100)
        for i in range(0,9):
            {
                competitor_grade[i]=a;
                sum_judge_eight += competitor_grade[i]
            }
        max = competitor_grade[0]
        min = competitor_grade[0]
        for(i=0;i<8;i++)
        {
            if(max<competitor_grade[i]):
                max = competitor_grade[i];
            if(min>competitor_grade[i]):
                min = competitor_grade[i];
        }
        sum_judge_six = (sum_judge_eight - min - max) / 6.0
        print('his judge is:'+str(sum_judge_six))

if __name__ == '__main__':
    people('liqing','male',12)
    grade()
