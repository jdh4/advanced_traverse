# Numerical Libraries

## NVIDIA GPU-Accelerated Libraries

![nvidia](https://static.nvidiagrid.net/ngc/containers/cuda-logo-light.png)

To see the available modules:

```
$ module avail cudatoolkit
-------------------------- /usr/local/share/Modules/modulefiles --------------------------
cudatoolkit/9.2  cudatoolkit/10.0  cudatoolkit/10.1  cudatoolkit/10.2  cudatoolkit/11.0 

$ module avail cudnn
-------------------------- /usr/local/share/Modules/modulefiles --------------------------
cudnn/cuda-9.2/7.6.1  cudnn/cuda-10.0/7.6.1  cudnn/cuda-10.1/7.6.1  cudnn/cuda-11.0/8.0.1 
```

To see how the [cudatoolkit](https://developer.nvidia.com/cuda-toolkit) module changes the environment:

```
$ module show cudatoolkit/11.0 
-------------------------------------------------------------------
/usr/local/share/Modules/modulefiles/cudatoolkit/11.0:

module-whatis   {Sets up cudatoolkit110 11.0 in your environment}
prepend-path    PATH /usr/local/cuda-11.0/bin
prepend-path    LD_LIBRARY_PATH /usr/local/cuda-11.0/lib64
prepend-path    LIBRARY_PATH /usr/local/cuda-11.0/lib64
prepend-path    MANPATH /usr/local/cuda-11.0/doc/man
append-path     -d { } LDFLAGS -L/usr/local/cuda-11.0/lib64
append-path     -d { } INCLUDE -I/usr/local/cuda-11.0/include
append-path     CPATH /usr/local/cuda-11.0/include
append-path     -d { } FFLAGS -I/usr/local/cuda-11.0/include
append-path     -d { } LOCAL_LDFLAGS -L/usr/local/cuda-11.0/lib64
append-path     -d { } LOCAL_INCLUDE -I/usr/local/cuda-11.0/include
append-path     -d { } LOCAL_CFLAGS -I/usr/local/cuda-11.0/include
append-path     -d { } LOCAL_FFLAGS -I/usr/local/cuda-11.0/include
append-path     -d { } LOCAL_CXXFLAGS -I/usr/local/cuda-11.0/include
-------------------------------------------------------------------
```

The GPU-accelerated libraries are listed below:

```
$ module load cudatoolkit/11.0
$ ls -lL /usr/local/cuda-11.0/lib64/lib*.so
-rwxr-xr-x.  2 root root   1472552 Aug  5 18:15 /usr/local/cuda-11.0/lib64/libaccinj64.so
-rwxr-xr-x.  2 root root 165980664 Aug  5 18:12 /usr/local/cuda-11.0/lib64/libcublasLt.so
-rwxr-xr-x.  2 root root  98589456 Aug  5 18:12 /usr/local/cuda-11.0/lib64/libcublas.so
-rwxr-xr-x.  2 root root    593088 Aug  5 18:15 /usr/local/cuda-11.0/lib64/libcudart.so
-rwxr-xr-x.  2 root root 164635080 Aug  5 18:12 /usr/local/cuda-11.0/lib64/libcufft.so
-rwxr-xr-x.  2 root root    658920 Aug  5 18:12 /usr/local/cuda-11.0/lib64/libcufftw.so
-rwxr-xr-x.  2 root root   1895048 Aug  5 18:15 /usr/local/cuda-11.0/lib64/libcuinj64.so
-rwxr-xr-x.  3 root root   6992416 Aug  5 18:15 /usr/local/cuda-11.0/lib64/libcupti.so
-rwxr-xr-x.  2 root root  71480408 Aug  5 18:12 /usr/local/cuda-11.0/lib64/libcurand.so
-rwxr-xr-x.  2 root root 305197464 Aug  5 18:12 /usr/local/cuda-11.0/lib64/libcusolverMg.so
-rwxr-xr-x.  2 root root 519248896 Aug  5 18:12 /usr/local/cuda-11.0/lib64/libcusolver.so
-rwxr-xr-x.  2 root root 160966696 Aug  5 18:12 /usr/local/cuda-11.0/lib64/libcusparse.so
-rwxr-xr-x.  1 root root    658904 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnppc.so
-rwxr-xr-x.  1 root root  11341544 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnppial.so
-rwxr-xr-x.  1 root root   5115632 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnppicc.so
-rwxr-xr-x.  1 root root   8196176 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnppidei.so
-rwxr-xr-x.  1 root root  52564856 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnppif.so
-rwxr-xr-x.  1 root root  26873672 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnppig.so
-rwxr-xr-x.  1 root root   6819584 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnppim.so
-rwxr-xr-x.  1 root root  20779040 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnppist.so
-rwxr-xr-x.  1 root root    593160 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnppisu.so
-rwxr-xr-x.  1 root root   3214888 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnppitc.so
-rwxr-xr-x.  1 root root   9507000 Jun 12 13:56 /usr/local/cuda-11.0/lib64/libnpps.so
-rwxr-xr-x.  2 root root    659120 Aug  5 18:12 /usr/local/cuda-11.0/lib64/libnvblas.so
-rwxr-xr-x.  1 root root   4132928 Jun 12 13:55 /usr/local/cuda-11.0/lib64/libnvjpeg.so
-rwxr-xr-x.  1 root root  11529488 Jun 12 14:02 /usr/local/cuda-11.0/lib64/libnvperf_host.so
-rwxr-xr-x.  1 root root   3190792 Jun 12 14:02 /usr/local/cuda-11.0/lib64/libnvperf_target.so
-rwxr-xr-x.  1 root root   5506648 Jun 12 14:07 /usr/local/cuda-11.0/lib64/libnvrtc-builtins.so
-rwxr-xr-x.  1 root root  23685768 Jun 12 14:07 /usr/local/cuda-11.0/lib64/libnvrtc.so
-rwxr-xr-x. 16 root root     44576 Aug  5 18:15 /usr/local/cuda-11.0/lib64/libnvToolsExt.so
-rwxr-xr-x.  1 root root     27288 Jun 12 14:02 /usr/local/cuda-11.0/lib64/libOpenCL.so
```

See [this page](https://developer.nvidia.com/gpu-accelerated-libraries) for the complete list.


Below are the executables of toolkit:

```
$ ls -lL /usr/local/cuda-11.0/bin
total 73264
-rwxr-xr-x. 2 root root   134352 Aug  5 18:15 bin2c
-rwxr-xr-x. 5 root root      285 Aug  5 18:15 computeprof
-rwxr-xr-x. 2 root root       89 Aug  5 18:15 compute-sanitizer
drwxr-xr-x. 2 root root       43 Sep 14 15:27 crt
-rwxr-xr-x. 2 root root  5652232 Aug  5 18:15 cudafe++
-rwxr-xr-x. 2 root root 13157200 Aug  5 18:15 cuda-gdb
-rwxr-xr-x. 1 root root  2334216 Jun 12 14:01 cuda-gdbserver
-rwxr-xr-x. 1 root root      800 Jun 12 13:13 cuda-install-samples-11.0.sh
-rwxr-xr-x. 2 root root   462672 Aug  5 18:15 cuda-memcheck
-rwxr-xr-x. 2 root root   331600 Aug  5 18:15 cuobjdump
-rwxr-xr-x. 2 root root   265760 Aug  5 18:15 fatbinary
-rwxr-xr-x. 1 root root     3066 Jul  2 19:20 ncu
-rwxr-xr-x. 3 root root     1580 Jun 12 14:03 nsight_ee_plugins_manage.sh
-rwxr-xr-x. 1 root root      745 Jul  2 19:20 nsight-sys
-rwxr-xr-x. 1 root root      746 Jul  2 19:20 nsys
-rwxr-xr-x. 1 root root      104 Jul  2 19:20 nsys-exporter
-rwxr-xr-x. 2 root root   332512 Aug  5 18:15 nvcc
-rwxr-xr-x. 5 root root      417 Aug  5 18:15 nvcc.profile
-rwxr-xr-x. 1 root root 28198672 Jun 12 13:59 nvdisasm
-rwxr-xr-x. 2 root root  9194672 Aug  5 18:15 nvlink
-rwxr-xr-x. 1 root root     3066 Jul  2 19:20 nv-nsight-cu-cli
-rwxr-xr-x. 2 root root  5700176 Aug  5 18:15 nvprof
-rwxr-xr-x. 1 root root   134576 May  7 22:05 nvprune
-rwxr-xr-x. 5 root root      285 Aug  5 18:15 nvvp
-rwxr-xr-x. 2 root root  9062600 Aug  5 18:15 ptxas
```

## MAGMA

![magma](http://icl.cs.utk.edu/projectsfiles/magma/doxygen/magma-logo.png)

[Magma](https://icl.utk.edu/magma/) is a linear algebra library that is designed for multicore nodes that have GPUs. It can be thought of as an improvement over LAPACK for such nodes. MAGMA is capable of using the [Tensor Cores](https://www.nvidia.com/en-us/data-center/tensor-cores/) of the V100 GPUs of Traverse.

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

## IBM Engineering and Scientific Subroutine Library (ESSL)

![essl](http://www.myiconfinder.com/uploads/iconsets/256-256-4be5cdae8f0f7b1d9c011b27d82107c5-ibm.png)

[ESSL](https://www.ibm.com/support/knowledgecenter/en/SSFHY8_6.1/navigation/welcome.html) is a linear algebra library.

Pronounced like the two letters "SL".

This is analogous to Intel Math Kernel Library (MKL).

```
$ ls -lL /usr/lib64/*essl*.so
-rw-r--r--. 1 bin bin 45719787 Mar 29  2018 /usr/lib64/libessl6464.so
-rw-r--r--. 1 bin bin 53379191 Mar 29  2018 /usr/lib64/libesslsmp6464.so
-rw-r--r--. 1 bin bin 54737430 Mar 29  2018 /usr/lib64/libesslsmpcuda.so
-rw-r--r--. 1 bin bin 53925425 Mar 29  2018 /usr/lib64/libesslsmp.so
-rw-r--r--. 1 bin bin 46826939 Mar 29  2018 /usr/lib64/libessl.so
```

### PETSc

According to the PETSc [installation page](https://www.mcs.anl.gov/petsc/documentation/installation.html):

> Sadly, IBM's ESSL does not have all the routines of BLAS and LAPACK that some packages, such as SuperLU expect; in particular slamch, dlamch and xerbla. In this case instead of using ESSL we suggest --download-fblaslapack. If you really want to use ESSL, see https://www.pdc.kth.se/hpc-services.
