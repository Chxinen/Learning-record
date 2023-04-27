# git使用

打算用GitHub来记笔记，所以学个git

win11

2023/4/26

 [创建版本库 - 廖雪峰的官方网站 (liaoxuefeng.com)](https://www.liaoxuefeng.com/wiki/896043488029600/896827951938304) 

建立仓库以及添加文件

```
//建立本地仓库
mkdir name_of_1
cd name_of_1
chdir//Windows查看当前目录
git init//建立仓库，仓库可能是隐藏的=>dir /b /s
//添加文件
git add name_of_2.type of file//可以先把所有要add的文件先add，再一起commit
git commit -m "something you want to say"
//第一次连接远程仓库(要先在GitHub上建立一个仓库)
git remote add origin https://github.com/Chxinen/Learning-record.git//origin是默认习惯命名
git push -u origin main//在main上建，也可以是master或其他分支
//以后
git push origin main
```

其他命令

```
git push -u origin main -f//如果提示需要pull,pull了之后也不行就强行push
git remote rm origin//删除远程仓库
git remote -v//查看远程库信息
```

