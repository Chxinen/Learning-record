# 1.01方程组的几何解释

row pictures

![1683635893611](Linear_Algebra.assets/1683635893611.png)

column pictures

![1683803150036](Linear_Algebra.assets/1683803150036.png)

任意b满足Ax=b => column picture 中向量不共线（面） 

计算

![1683805116318](Linear_Algebra.assets/1683805116318.png)

# 2.02矩阵消元

主元为0交换行（暂时有效 ）

![1683806018723](Linear_Algebra.assets/1683806018723.png)



第一个矩阵看为对第二个矩阵每一行的处理

1 0 0    1 2 1 =>1 2 1 不变，处理第一个式子

-3 1 0   3 8 1 =>0 2 -2 对第一个式子乘-3，在第二个式子中减去三倍行一，实现消元

0 0 1   0 4 1 =>0 4 1 处理第三个式子

### 初等矩阵

E21

![1683807052128](Linear_Algebra.assets/1683807052128.png)

E32

![1683807651063](Linear_Algebra.assets/1683807651063.png)



![1683807627972](Linear_Algebra.assets/1683807627972.png)

#### 逆变换

U->A

![1683808626494](Linear_Algebra.assets/1683808626494.png)



![1683808826628](Linear_Algebra.assets/1683808826628.png)



### 置换矩阵

行

![1683807784290](Linear_Algebra.assets/1683807784290.png)

列 

![1683808203646](Linear_Algebra.assets/1683808203646.png)