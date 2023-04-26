# git使用

打算用GitHub来记笔记，所以学个git

win11

2023/4/26

 [创建版本库 - 廖雪峰的官方网站 (liaoxuefeng.com)](https://www.liaoxuefeng.com/wiki/896043488029600/896827951938304) 

命令行进入D盘

![1682496036734](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682496036734.png)

查看当前路径

![1682496150075](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682496150075.png)



![1682496203081](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682496203081.png)

查看当前目录下文件

![1682496347051](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682496347051.png)

对打算上传的文件选择UTF-8（主要是指代码啦）,好像typora默认就是这个

一直按照教程操作，然后push的时候遇到以下问题

![1682498023760](C:\Users\chexinn\AppData\Roaming\Typora\typora-user-images\1682498023760.png)

解决

```
git remote rm origin
git remote add origin https://github.com/Chexinn/Learning-record.git
git push origin main
```

不要push到master上，现在时main为默认，强迫症受不了

