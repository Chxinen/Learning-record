# web安全|渗透测试|网络安全

## 基础名词

### 域名：

第三方注册（万网）

二级域名：无www.

![1682126804971](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682126804971.png)

多级域名：

![1682126812621](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682126812621.png)

域名对安全的意义：

多级域名与主站有关系，可搜集多级域名，作为突破口

###### （IP地址可能要一样）

### DNS

知域名得IP

知IP得域名

不同DNS解析时间不同

先在本地host上寻找是否有目标网址IP，如果没有再去网络上获取。

加速软件：修改host文件，加快访问速度（结点）

DNS服务器被攻击时可使访问指向其他地址，造成恶意访问

#### CDN

缓存结点

![1682128165385](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682128165385.png)

访问时给就近结点

扫不到真实目标

### 脚本语言

语言的选用=>漏洞的多少

### 后门

攻击者留个后门便于下次操作

玩法（作用），免杀（不被杀毒杀掉）

### WBE

![1682129681246](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682129681246.png)

从web层面逐渐深入到底层（难度更小）

### WBE相关安全漏洞

![1682131980362](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682131980362.png)

### 演示案例

多级域名的枚举查找（直接搜索，工具layer子域名挖掘机爆破，运行商第三方接口：万网）

dns解析修改后分析

exe后门功能及危害及类似web后门（quasar）

app类结合web协议，pc类结合web协议

抓web协议工具（Burp Suite）

![1682133644228](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682133644228.png)

### 请求 响应

![1682235377379](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682235377379.png)

抓包软件相当于一个代理

![1682236317469](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682236317469.png)

数据包是client和server直接交流的介质

修改数据包进行改造信息

#####  X-Forwarded-for ：PHP中判断IP地址的东西，可以被修改。

burp suite添加一行 X-Forwarded-for ：192.168.1.1，后两位设为变量进行intruder

用来刷票

##### 总的来说就是要明白每个name对应的东西是什么，然后再去修改

比如referer是来源，User-agent是用户信息



## 搭建安全拓展

### 搭建平台脚本启用

### 域名IP目录解析安全问题

用IP地址访问（不加端口）和域名访问所进去的文件夹不同，IP所进的文件夹是域名的上一级

加了端口相当于指定一个IP地址指向的该级文件夹（比如域名指向的文件夹）

=>用IP地址扫描可获得更多信息

### 常见文件后缀解析对应安全

文件后缀对应一种解析，如果有的可以解析有的不能解析，很可能是网络搭建所用的中间件有自己的规则

### 常见安全测试中的安全防护

身份验证（要知道用户名与密码）

域名控制（黑白名单）

### web后门与用户及文件权限

限制来宾账户的权限（写入、读取……）

绕过：找没被限制的文件夹

#### 《web中间件常见漏洞总结》