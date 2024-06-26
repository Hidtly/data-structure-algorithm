
# 数据结构及其算法 👋

🔗记录学习过程 *[github](https://github.com/Hidtly/data-structure-algorithm)*

## 数据结构

### 1. 线性表

#### - 顺序存储结构
  
 >顺序存储结构：依次存储，地址连续--**中间没有空的存储单元**

##### 1.1 平均查找长度ASL(Aver Search Length)

>为确定记录在表中的位置，需要与给定值进行比较的关键字的个数的**期望值**叫做查找算法的***平均查找长度***

$$ ASL = \sum_{i=1}^{n} P_iC_i $$

$$    P_i为第i个记录被查找的概率 $$

$$    C_i为找到第i个记录需比较的次数 $$

顺序查找的平均查找长度：

$$ ASL = P_1 + 2P_2+...+(n-1)P_n-1+nP_n $$

假设每个记录的查找概率相等：

$$ P_i = \frac{1}{n} $$

则：

$$    ASL_{ss} = \sum_{i=1}^{n} P_iC_i = \frac{1}{n} \sum_{i = 1}^{n} i = \frac{n + 1}{2}$$

- 顺序表平均查找长度的算法平均时间复杂度为**O(n)**。

##### 1.2 插入

$$
    E_{ins} = \frac{1}{n+1} \sum_{i = 1}^{n + 1} (n - i +1) =\frac{1}{n + 1} \frac{n(n + 1)}{2} = \frac{n}{2}
$$

- 顺序表插入算法的平均时间复杂度为**O(n)**

##### 1.3 删除

$$
    E_{del} = \frac{1}{n} \sum_{i = 1}^{n} (n - i) =\frac{1}{n} \frac{(n - 1)n}{2} = \frac{n - 1}{2}
$$

- 顺序表删除算法的平均时间复杂度为**O(n)**。

##### 1.4 优缺点

- 优点

  1.存储密度大

  2.可以随机存取表中任一元素

- 缺点
  
  1.在插入、删除某一元素时，需要移动大量元素

  2.浪费存储空间
  
  3.属于静态存储方式，数据元素的个数不能自由扩充

#### - 链式存储结构

### 2. 栈和队列

>限定插入和删除只能在表的**端点**进行的***线性表***
