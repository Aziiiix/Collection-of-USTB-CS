本答案项目用于完成OS Lab奖励实验 从平坦软盘镜像引导加载内核

[domain relative url](engintime/os-lab/bonus-lab/lab02-mission1.git)访问本答案项目对应的实验模板

# 主要修改
1.boot程序因为读扇区较少，使用了CHS寻址方式。  
2.loader程序读kernel.dll到物理内存0x10000处，因为文件大小将近300K，因此使用loop循环读600个连续扇区。  
3.调整了项目配置，调用mkfloppy将boot.bin、loader.bin、kernel.dll依次写到了平坦镜像文件Floppy.img。  
4.注释掉了ioinit.c中关于软驱的部分代码第174至第226行，否则会导致无法进入内核程序。  