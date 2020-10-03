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
$ gcc -Ofast -mcpu=power9 -mtune=power9 -mvsx -o myprog myprog.c
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

## PGI


## IBM XL C/C++ and Fortran

We have the [community edition](https://www.ibm.com/us-en/marketplace/xl-cpp-linux-compiler-power) (version 16.1.1) of the IBM XL compilers. This version was released in December 2018. While it offers several GPU features, it can only go as high as version 10.1 of CUDA. See [this video](https://www.youtube.com/watch?v=p6-pfj3tCmY) for an overview.

Users should favor GCC or one of the other compilers over XL. A newer, [paid](https://www.ibm.com/us-en/marketplace/xl-cpp-linux-compiler-power/purchase) version with additional optimizations is available.

To get started:

```
$ xlc -qhelp
$ xlC -qhelp
# xlf -qhelp
```

-Ofast -qarch=pwr9 -qtune=pwr9 -qsimd=auto

Below is an example build of FFTW:

```
#!/bin/bash
version_fftw=3.3.8

wget ftp://ftp.fftw.org/pub/fftw/fftw-${version_fftw}.tar.gz
tar -zxvf fftw-${version_fftw}.tar.gz
cd fftw-${version_fftw}

./configure CC=xlc CFLAGS="-Ofast -qarch=pwr9 -qtune=pwr9 -mvsx -DNDEBUG" --prefix=$HOME/.local \
--enable-shared --enable-single --enable-vsx --disable-fortran

make -j 10
make install
```

ppcle64 - PowerPC little endian 64-bit (memory model)

[Code Optimization with IBM XL Compilers](https://www-01.ibm.com/support/docview.wss?uid=swg27005174&aid=1)

This guide says: "VMX and VSX machine
instructions can execute up to sixteen operations in parallel."

```
$ xlc --version
IBM XL C/C++ for Linux, V16.1.1 (Community Edition)
Version: 16.01.0001.0003
/opt/ibm/xlC/16.1.1/bin/.orig/xlc: note: XL C/C++ Community Edition is a no-charge product and does not include official IBM support. You can provide feedback at the XL on POWER C/C++ Community Edition forum (http://ibm.biz/xlcpp-linux-ce). For information about a fully supported XL C/C++ compiler, visit XL C/C++ for Linux (http://ibm.biz/xlcpp-linux).
```

All roads lead to `xlf` -- it calls /usr/bin then /etc/alternatives then /opt/ibm:

```
-rwxr-xr-x. 1 root root 764K Apr  4  2019 xlf
-rwxr-xr-x. 1 root root 699K Apr  4  2019 minilink
-rwxr-xr-x. 1 root root 700K Apr  4  2019 minicomp
lrwxrwxrwx. 1 root root    3 Jul  1  2019 fort77 -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 f95 -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 f90 -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 f77 -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 f2008 -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 f2003 -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 xlcuf -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 xlf2003 -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 xlf_r -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 xlf95_r -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 xlf95 -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 xlf90_r -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 xlf90 -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 xlf2008_r -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 xlf2008 -> xlf
lrwxrwxrwx. 1 root root    3 Jul  1  2019 xlf2003_r -> xlf
```

## PGI

Portland Group, Inc. was takenover by NVIDIA in 20XX. OpenACC


## GCC

GCC is the GNU Compiler Collection.

```
$ g++ --version
g++ (GCC) 4.8.5 20150623 (Red Hat 4.8.5-39)
```

```
$ module load rh/devtoolset/8
$ g++ --version
g++ (GCC) 8.3.1 20190311 (Red Hat 8.3.1-3)
```

After loading the `rh` module the C/C++ and Fortran compilers and related tools are also updated.

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

## Notes

The Intel compiler is not compatible with POWER9.
