本答案项目用于完成OS Lab奖励实验 从U盘镜像引导加载内核

[domain relative url](engintime/os-lab/bonus-lab/lab02-mission2.git)访问本答案项目对应的实验模板

# 主要修改
1.boot程序增加了硬盘分区表的内容，使用了LBA寻址方式，供学生改写loader.asm时参考。  
2.loader程序使用了LBA寻址方式，读kernel.dll到物理内存0x10000处，因为文件大小将近300K，因此使用读600个连续扇区。  
3.调整了项目配置，调用mkimage将boot.bin、loader.bin、kernel.dll依次写到了平坦镜像文件Floppy.img。同时还要保证镜像文件的大小不能太小且是512字节的整数倍。  
4.注释掉了ioinit.c中关于软驱的部分代码第174至第226行，否则会导致无法进入内核程序。  
5.注释掉了mempool.c文件的86行、87行，防止内存校验报错导致无法进入内核。  
6.注释掉了keyboard.c文件第291行“更新键盘LED指示灯的状态”，防止初始化时失败而无法进入到内核。  
7.调试前要确保Bochs已经采用了2.6.8这个版本，否则低版本无法通过U盘进行引导。  