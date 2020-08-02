sccanf的用法及实例
 
sscanf与scanf类似，都是用于输入的，只是后者以键盘(stdin)为输入源，前者以固定字符串为输入源。

第二个参数可以是一个或多个 {%[*] [width] [{h | I | I64 | L}]type | ' ' | '\t' | '\n' | 非%符号}
注：

1、*亦可用于格式中, (即 %*d 和 %*s) 加了星号 (*) 表示跳过此数据不读入. (也就是不把此数据读入参数中)
2、{a|b|c}表示a,b,c中选一，[d]表示可以有d也可以没有d。
3、width表示读取宽度。
4、{h | l | I64 | L}:参数的size,通常h表示单字节size，I表示2字节size,L表示4字节size(double例外),l64表示8字节size。
5、type :这就很多了，就是%s,%d之类。
6、特别的：%*[width] [{h | l | I64 | L}]type 表示满足该条件的被过滤掉，不会向目标参数中写入值
失败返回0，否则返回格式化的参数个数

支持集合操作

%[a-z] 表示匹配a到z中任意字符，贪婪性(尽可能多的匹配)
%[aB'] 匹配a、B、'中一员，贪婪性
%[^a] 匹配非a的任意字符，并且停止读入，贪婪性 C语言函数sscanf()的用法

例子

1. 常见用法。

char buf[512];
sscanf("123456","%s",buf);//此处buf是数组名，它的意思是将123456以%s的形式存入buf中！
printf("%s\n",buf);
结果为：123456

2. 取指定长度的字符串。如在下例中，取最大长度为4字节的字符串。

sscanf("123456","%4s",buf);
printf("%s\n",buf);
结果为：1234

3. 取到指定字符为止的字符串。如在下例中，取遇到任意小写字母为止的字符串。

sscanf("123456abcdedf","%[^a-z]",buf);
printf("%s\n",buf);
结果为：123456

4. 取仅包含指定字符集的字符串。如在下例中，取仅包含1到9和小写字母的字符串。

sscanf("123456abcdedfBCDEF","%[1-9a-z]",buf);
printf("%s\n",buf);
结果为：123456abcdedf

当输入： 　
sscanf("123456abcdedfBCDEF","%[1-9A-Z]",buf);
printf("%s\n",buf);

结果为：123456BCDEF(错！！！)
注：结果应该为：123456（因为遇到不是1-9或者A-Z的字符时，即遇到小写字母时，就已经结束。）

5. 取到指定字符集为止的字符串。如在下例中，取遇到大写字母为止的字符串。

sscanf("123456abcdedfBCDEF","%[^A-Z]",buf);
printf("%s\n",buf);
结果为：123456abcdedf

6、给定一个字符串iios/12DDWDFF@122，获取 / 和 @ 之间的字符串，
先将 "iios/"过滤掉，再将非'@'的一串内容送到buf中

sscanf("iios/12DDWDFF@122","%*[^/]/%[^@]",buf);
printf("%s\n",buf);
结果为：12DDWDFF

7、给定一个字符串“hello, world”，仅保留world。
（注意：“，”之后有一空格，%s遇空格停止，加*则是忽略第一个读到的字符串）

sscanf(“hello,world”,"%*s%s",buf);
printf("%s\n",buf);
结果为：world

%*s表示第一个匹配到的%s被过滤掉，即“hello,”被过滤了。
如果没有空格则结果为NULL。

8、最简明的格式是tab间隔的字符串

sscanf(“字符串1\t字符串2\t字符串3”,"%s%s%s",str1,str2,str3);
printf("%s\t%s\t%s\n",str1,str2,str3);
结果为：字符串1 字符串2 字符串3


