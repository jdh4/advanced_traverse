# Compilers

## IBM xlc/C

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

## Notes

The Intel compiler is not compatible with POWER9.
