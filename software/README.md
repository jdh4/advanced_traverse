# Software

```bash
$ module avail

------------------------------------- /usr/share/Modules/modulefiles --------------------------------------
at12.0      dot         module-git  module-info modules     null        use.own

------------------------------------ /usr/licensed/Modules/modulefiles ------------------------------------
anaconda/2019.10(default)  anaconda3/2019.10(default) ddt/20.0.1
anaconda/2019.3            anaconda3/2019.3

---------------------------------- /usr/local/share/Modules/modulefiles -----------------------------------
boost/1.55.0                           hdf5/gcc/openmpi-4.0.1/1.10.5
cmake/3.x                              hdf5/pgi-19.5/1.10.5
cudatoolkit/10.0                       hdf5/pgi-19.5/openmpi-4.0.2rc1/1.10.5
cudatoolkit/10.1                       nccl/cuda-10.0/2.5.6
cudatoolkit/10.2(default)              nccl/cuda-10.1/2.5.6
cudatoolkit/9.2                        nccl/cuda-10.2/2.5.6
cudnn/cuda-10.0/7.6.1                  openmpi/devtoolset-8/3.1.4/64
cudnn/cuda-10.1/7.6.1                  openmpi/devtoolset-8/4.0.1/64
cudnn/cuda-9.2/7.6.1                   openmpi/devtoolset-8/4.0.3rc1/64
fftw/gcc/3.3.8                         openmpi/gcc/3.1.4/64
fftw/gcc/openmpi-3.1.4/3.3.8           openmpi/gcc/4.0.1/64
fftw/gcc/openmpi-4.0.1/3.3.8           openmpi/gcc/4.0.2rc1/64
hdf5/devtoolset-8/1.10.5               openmpi/gcc/4.0.3rc1/64
hdf5/devtoolset-8/openmpi-4.0.1/1.10.5 openmpi/pgi-19.5/4.0.2rc1/64
hdf5/gcc/1.10.5                        openmpi/pgi-19.9/4.0.2rc1/64
hdf5/gcc/openmpi-3.1.4/1.10.5          openmpi/pgi-19.9/4.0.3rc1/64

------------------------------------- /opt/share/Modules/modulefiles --------------------------------------
git/2.18        pgi/19.5/64     pgi/19.9/64     rh/devtoolset/6 rh/devtoolset/7 rh/devtoolset/8
```

## Import Notes

Use the `openmpi/devtoolset-8` modules when working with Fortran mod files. Mod files are intermediate files during Fortran
compilations.

## CUDAToolkit

Note that `libcublas.so` is now in `/usr/lib64` as of version 10.1.

## PETSc

XL compilers don't work. ESSL cannot be used.

## GROMACS

d

##

To see how an Open MPI module was built:

```
$ module load openmpi/devtoolset-8/4.0.3rc1/64
$ ompi_info
```

