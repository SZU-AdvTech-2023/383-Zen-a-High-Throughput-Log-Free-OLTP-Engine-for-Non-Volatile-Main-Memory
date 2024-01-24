# README

文件下，共分为 benchmarks、concurrency_control、lib、storage 和 system 文件夹以及其根目录下的其他若干文件。

- benchmarks 文件夹存储的是对于实验数据的处理文件。在复现实验中，支持 YCSB 和 TPC-C两种 benchmark。这两种 benchmark 是目前对于 OLTP 数据库最主流的选择，所以使用二者的实验结果具有一定的说服力；
- concurrency_control 文件夹存储的是 Zen 关于并发控制的相关代码。包括对于死锁（deadlock）、乐观并发控制和多版本并发控制等内容；

- libs 文件夹中是对现有的关于空间分配静态库的引用；

- storage 中则是对于论文中 Zen 复杂架构的实现，包括混合表、树型索引和元组信息等内容；

- system 文件夹中则是关于整个 Zen 引擎系统的一些组件，如对于非易失性存储元组缓存的管理机制、线程的相关管理和最重要的内存以及非易失性存储器的空间分配管理。需要说明的是在其中的 nvm_memory.cpp 等相关文件中需要引用 libpmem.h 文件（即

```cpp
# include < libpmem.h >
```

）。这个头文件是英特尔公司专门为操作其非易失性存储器 Optane 产品所推出的开发工具，需要在系统级安装 pmdk 依赖；

- 在实验文件的目录下还有一些其他的零散文件，包括 M akef ille 文件，config 相关文件。config 相关文件记录了实验中所有的参数信息并可供选择和切换，如 benchmark 的相关配置，线程个数和页面大小等大量信息。

编译实验代码时，需要在实验文件目录的终端下执行 make 命令。此时，实验文件目录下就会生成一个名为 rundb 的可执行文件。再在终端下执行 ./rundb 命令即可运行相关的实验。

