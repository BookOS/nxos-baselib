# NXBASE基础库

作为NXOS在用户态的最基础的库，提供了最为基础的内存管理，进程/线程管理，文件操作，网络操作等基础API。

## 使用方法

```shell
# 1. 设置环境变量 setup [arch]
setup.bat # windows环境，默认x86
source setup.sh # linux环境
setup.bat riscv64 # windows环境
source setup.sh riscv64 # linux环境
# 2. 编译库，生成的库需要用户环境make ulib同步后使用
make
```
