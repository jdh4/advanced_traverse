# Compilers

## IBM XL C/C++ and Fortran

The native or vendor-supplied compiler for Traverse are the IBM xlc/C/f

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
