# Compilers

## IBM XL C/C++ and Fortran

The native or vendor-supplied compiler for Traverse are the IBM xlc/C/f. In general, there are performance advantages to using the vendor compiler suite.

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

[Code Optimization with IBM XL Compilers](https://www-01.ibm.com/support/docview.wss?uid=swg27005174&aid=1)

```
$ xlc --version
IBM XL C/C++ for Linux, V16.1.1 (Community Edition)
Version: 16.01.0001.0003
/opt/ibm/xlC/16.1.1/bin/.orig/xlc: note: XL C/C++ Community Edition is a no-charge product and does not include official IBM support. You can provide feedback at the XL on POWER C/C++ Community Edition forum (http://ibm.biz/xlcpp-linux-ce). For information about a fully supported XL C/C++ compiler, visit XL C/C++ for Linux (http://ibm.biz/xlcpp-linux).
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

## Notes

The Intel compiler is not compatible with POWER9.
