# Compilers

## GCC

The system version of GCC is 8.3.1. For instance:

```
$ gcc --version
gcc (GCC) 8.3.1 20191121 (Red Hat 8.3.1-5)

$ g++ --version
g++ (GCC) 8.3.1 20191121 (Red Hat 8.3.1-5)

$ gfortran --version
GNU Fortran (GCC) 8.3.1 20191121 (Red Hat 8.3.1-5)
```

A good starting point for GCC optimization flags on Traverse is:

```
$ gcc -Ofast -mcpu=power9 -mtune=power9 -mvsx -DNDEBUG -o myprog myprog.c
```

Take a look at `man gcc` for more.


The version of glibc is

```
$ ldd --version
ldd (GNU libc) 2.28
```

While you should prefer the system version of GCC (8.3.1), in some cases it may be necessary to use an earlier version. The `rh/devtoolset/7` environment module exists for this purpose:

```
$ module load rh/devtoolset/7
$ gcc --version
gcc (GCC) 7.3.1 20180303 (Red Hat 7.3.1-5)

$ g++ --version
g++ (GCC) 7.3.1 20180303 (Red Hat 7.3.1-5)

$ gfortran --version
GNU Fortran (GCC) 7.3.1 20180303 (Red Hat 7.3.1-5)
```

## NVIDIA HPC SDK

Preferred for OpenACC GPU programming. See the [documentation](https://docs.nvidia.com/hpc-sdk/index.html).

NVIDIA acquired PGI in 2013. See [this page](https://developer.nvidia.com/hpc-sdk).
OpenACC GPU programming

```
$ module avail nvhpc
--- /opt/share/Modules/modulefiles ---
nvhpc-nocompiler/20.7  nvhpc/20.7
```

Two workshops on GPU programming at Princeton/PPPL.


## PGI

```
$ module avail pgi
--- /opt/share/Modules/modulefiles ---
pgi/19.5/64  pgi/19.9/64  pgi/20.4/64
```

## IBM XL C/C++ and Fortran

We have the [community edition](https://www.ibm.com/us-en/marketplace/xl-cpp-linux-compiler-power) (version 16.1.1) of the IBM XL compilers. This version was released in December 2018. While it offers several GPU features, it can only go as high as version 10.1 of CUDA. See [this video](https://www.youtube.com/watch?v=p6-pfj3tCmY) for an overview.

Users should favor GCC or one of the other compilers over XL. A newer, [paid](https://www.ibm.com/us-en/marketplace/xl-cpp-linux-compiler-power/purchase) version with additional optimizations is available.

To get started:

```
$ xlc --version
IBM XL C/C++ for Linux, V16.1.1 (Community Edition)
Version: 16.01.0001.0003

$ xlc -qhelp
$ xlC -qhelp
$ xlf -qhelp
```

A good starting point for XL optimization flags on Traverse is:

```
$ xlc -Ofast -qarch=pwr9 -qtune=pwr9 -qsimd=auto -DNDEBUG -o myprog myprog.c
```

For more on optimization see [Code Optimization with IBM XL Compilers](https://www-01.ibm.com/support/docview.wss?uid=swg27005174&aid=1). This guide says: "VMX and VSX machine instructions can execute up to sixteen operations in parallel."

## Intel

The Intel compilers cannot be used on the PowerPC architecture of Traverse.

## Where is the vectorization?

```
$ module load rh/devtoolset/8

$ gcc -O2 -g abc.c 
$ time ./a.out 

real	0m36.145s
user	0m36.145s
sys	0m0.000s

$ gcc -Ofast abc.c 
$ time ./a.out 

real	0m15.666s
user	0m15.660s
sys	0m0.000s

$ gcc -Ofast -mcpu=power9 -mtune=power9 abc.c 
$ time ./a.out 

real	0m15.576s
user	0m15.573s
sys	0m0.000s

$ gcc -Ofast -mcpu=power9 -mtune=power9 -mvsx abc.c 
$ time ./a.out 

real	0m15.582s
user	0m15.579s
sys	0m0.001s

gcc -Ofast -mcpu=native -mtune=native -mvsx abc.c 
$ time ./a.out 

real	0m15.592s
user	0m15.590s
sys	0m0.000s

$ gcc -Ofast -march=power9 abc.c
gcc: error: unrecognized command line option ‘-march=power9’; did you mean ‘-mcpu=power9’?
```

```
$ xlc -Ofast abc.c 
$ time ./a.out

real	0m59.467s
user	0m59.462s
sys	0m0.000s

$ xlc -Ofast -qarch=pwr9 -qtune=pwr9 -mvsx abc.c 
$ time ./a.out

real	0m59.463s
user	0m59.463s
sys	0m0.000s

$ xlc -O3 -qarch=pwr9 -qtune=pwr9 -qsimd=auto abc.c
$ time ./a.out

real	1m3.029s
user	1m3.030s
sys	0m0.000s

$ xlc -Ofast -qarch=pwr9 -qtune=pwr9 -qsimd=auto -qaltivec=le abc.c
$ time ./a.out

real	0m59.459s
user	0m59.460s
sys	0m0.000s
```
