# Compilers

## IBM XL C/C++ and Fortran

The native or vendor-supplied compiler for Traverse are the IBM xlc/C/f. In general, there are performance advantages to using the vendor compiler suite.

```
$ xlc --help
$ xlc --help
# nothing for xlf
```

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
```

## Notes

The Intel compiler is not compatible with POWER9.
