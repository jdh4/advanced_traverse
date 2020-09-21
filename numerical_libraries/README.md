# Numerical Libraries

## NVIDIA

## MAGMA

![magma](http://icl.cs.utk.edu/projectsfiles/magma/doxygen/magma-logo.png)

MAGMA is a linear algebra library that is designed for multicore nodes that have GPUs such as Traverse. It can be thought of as an improvement over LAPACK for the aforementioned hardware.

Here is a sample build of MAGMA on Traverse:

```
$ ssh traverse
$ cd software
$ wget http://icl.utk.edu/projectsfiles/magma/downloads/magma-2.5.3.tar.gz
$ tar zxf magma-2.5.3.tar.gz
$ cd magma-2.5.3
$ wget <make.inc>
$ module load cudatoolkit/10.2
$ export CUDADIR=/usr/local/cuda-10.2
$ make
$ make install prefix=$HOME/software/magma
```

MAGMA appears to not support CUDA 11 (10/13/2020).

[Magma website](https://icl.utk.edu/magma/)  
[Magam documentation](http://icl.cs.utk.edu/projectsfiles/magma/doxygen/)  

## IBM Engineering and Scientific Library (ESSL)

Pronounced like the two letters "SL".

This is analogous to Intel Math Kernel Library (MKL).

Does work with gromacs.

Does not work with PETSc.

### Where is ESSL on Traverse?

```
$ ls -lL /lib64/*essl*
-rw-r--r--. 1 bin bin 45719787 Mar 29  2018 /lib64/libessl6464.so
-rw-r--r--. 1 bin bin 45719787 Mar 29  2018 /lib64/libessl6464.so.1
-rw-r--r--. 1 bin bin 45719787 Mar 29  2018 /lib64/libessl6464.so.1.10
-rw-r--r--. 1 bin bin 53379191 Mar 29  2018 /lib64/libesslsmp6464.so
-rw-r--r--. 1 bin bin 53379191 Mar 29  2018 /lib64/libesslsmp6464.so.1
-rw-r--r--. 1 bin bin 53379191 Mar 29  2018 /lib64/libesslsmp6464.so.1.10
-rw-r--r--. 1 bin bin 54737430 Mar 29  2018 /lib64/libesslsmpcuda.so
-rw-r--r--. 1 bin bin 54737430 Mar 29  2018 /lib64/libesslsmpcuda.so.1
-rw-r--r--. 1 bin bin 54737430 Mar 29  2018 /lib64/libesslsmpcuda.so.1.10
-rw-r--r--. 1 bin bin 53925425 Mar 29  2018 /lib64/libesslsmp.so
-rw-r--r--. 1 bin bin 53925425 Mar 29  2018 /lib64/libesslsmp.so.1
-rw-r--r--. 1 bin bin 53925425 Mar 29  2018 /lib64/libesslsmp.so.1.10
-rw-r--r--. 1 bin bin 46826939 Mar 29  2018 /lib64/libessl.so
-rw-r--r--. 1 bin bin 46826939 Mar 29  2018 /lib64/libessl.so.1
-rw-r--r--. 1 bin bin 46826939 Mar 29  2018 /lib64/libessl.so.1.10
```

### PETSc

According to the PETSc [installation page](https://www.mcs.anl.gov/petsc/documentation/installation.html):

> Sadly, IBM's ESSL does not have all the routines of BLAS and LAPACK that some packages, such as SuperLU expect; in particular slamch, dlamch and xerbla. In this case instead of using ESSL we suggest --download-fblaslapack. If you really want to use ESSL, see https://www.pdc.kth.se/hpc-services.

### GROMACS

```
[100%] Linking CXX executable ../../bin/template
../../lib/libgromacs.so.4.0.0: undefined reference to `ssteqr_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dsteqr_'
../../lib/libgromacs.so.4.0.0: undefined reference to `slasr_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dlartg_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dlacpy_'
../../lib/libgromacs.so.4.0.0: undefined reference to `slapy2_'
../../lib/libgromacs.so.4.0.0: undefined reference to `slascl_'
../../lib/libgromacs.so.4.0.0: undefined reference to `slaset_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dlapy2_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dlaev2_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dlarnv_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dlanst_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dlascl_'
../../lib/libgromacs.so.4.0.0: undefined reference to `slacpy_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dorm2r_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dgeqr2_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dlasr_'
../../lib/libgromacs.so.4.0.0: undefined reference to `slarnv_'
../../lib/libgromacs.so.4.0.0: undefined reference to `slartg_'
../../lib/libgromacs.so.4.0.0: undefined reference to `sgeqr2_'
../../lib/libgromacs.so.4.0.0: undefined reference to `slaev2_'
../../lib/libgromacs.so.4.0.0: undefined reference to `slanst_'
../../lib/libgromacs.so.4.0.0: undefined reference to `sorm2r_'
../../lib/libgromacs.so.4.0.0: undefined reference to `dlaset_'
collect2: error: ld returned 1 exit status
make[2]: *** [share/template/CMakeFiles/template.dir/build.make:85: bin/template] Error 1
make[1]: *** [CMakeFiles/Makefile2:2311: share/template/CMakeFiles/template.dir/all] Error 2
make: *** [Makefile:163: all] Error 2
```
