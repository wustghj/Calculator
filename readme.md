### 计算器

主要界面

* 1.mainwindow (主窗口，设置菜单栏等)
* 2.choosepage (选择功能界面)

![image-20230506163012445](https://github.com/wustghj/markdownPhotos/blob/main/images/myCal.png?raw=true).

* 3.normalpage (标准计算器界面)

![image](https://github.com/wustghj/markdownPhotos/blob/main/images/normal.png?raw=true).

* 4.sciencepage (科学计算器界面)

![image](https://github.com/wustghj/markdownPhotos/blob/main/images/science.png?raw=true).

* 5.programmerpage (程序员界面)

![image](https://github.com/wustghj/markdownPhotos/blob/main/images/Hex.png?raw=true)![image](https://github.com/wustghj/markdownPhotos/blob/main/images/hexResult.png?raw=true)



* 6.datepage日期计算界面 



##### 后端

c++没有封装bignums库， 因此数字计算采用高精度算法[任意精度算术 - 维基百科](https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic)， [C++高精度算法_c++高精度计算_江河湖海 的博客-CSDN博客](https://blog.csdn.net/qq_59682549/article/details/127159839?app_version=5.11.1&code=app_1562916241&csdn_share_tail={"type"%3A"blog"%2C"rType"%3A"article"%2C"rId"%3A"127159839"%2C"source"%3A"qq_51048314"}&uLinkId=usr1mkqgl919blen&utm_source=app)



封装一个有理数Rational类

```cpp
class Rational
{
    QVector<int8_t> mInteger; // 整数部分， 使用signed char 来代表每个数字
    QVector<int8_t> mDecimal; // 小数部分
    
    // 并且将主要的运算符全部重载
    bool operator>(const Rational &A)const;                    //重载大于号
    bool operator>=(const Rational &A)const;                   //重载大于等于号
    bool operator<(const Rational &A)const;                    //重载小于号
    bool operator<=(const Rational &A)const;                   //重载小于等于号
    bool operator==(const Rational &A)const;                   //重载等于号
    bool operator!=(const Rational &A)const;                   //重载不等于号
    Rational operator+(const Rational &A)const;               //重载加法
    Rational operator-(const Rational &A)const;               //重载减法
    Rational operator*(const Rational &A)const;               //重载乘法
    Rational operator/(const Rational &A)const;               //重载除法
}
```

核心算法

```cpp
void rantionalAdd(const Rational &A,const Rational &B,Rational &Res)const;                           //高精度加法
void rantionalSubtract(const Rational &A,const Rational &B,Rational &Res)const;                      //高精度减法
void rantionalMultiply(const Rational &A,const Rational &B,Rational &Res)const;                      //高精度乘法
void rantionalDivide(const Rational &A,const Rational &B,Rational &Res,int32_t precision)const;      //高精度除法

QString getNumber()const;                                   //输出高精度数为字符串
QString getDecimal()const;                                  //单独获取小数部分
QString getInteger()const;                                  //获取整数部分
```

表达式运算算法

使用常规的中缀转后缀然后运算得出结果



计算出结果后，以科学计算器页面为例

页面逻辑：点击计算器按钮生成一个表达式(Expression)，获取控件text()文本然后发送到CalEngine

然后通过CalEngine计算出结果后更新当前输入框的内容为计算结果



##### 前端

mainwindow窗口

![image](https://github.com/wustghj/markdownPhotos/blob/main/images/mainwindow.png?raw=true).

sciencepage

![image](https://github.com/wustghj/markdownPhotos/blob/main/images/sciencepage.png?raw=true).

#### 致谢
https://github.com/EMILIIIIA/ExpressionCalculator
