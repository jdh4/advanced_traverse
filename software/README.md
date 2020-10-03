# Software

## Automatic Module Substitution

Many of the modules on Traverse are in fact only aliases to a native module. An "@" character at the end of the module name indicates an alias. Aliases are automatically substituted for the appropriate native RHEL8 module during loading. For example:

```
$ module load openmpi/gcc/3.1.4/64
$ module list
Currently Loaded Modulefiles:
 1) openmpi/gcc/4.0.4/64
```

There is no good way to explicitly alert the user to these substitutions.

## Import Notes

Use the `openmpi/devtoolset-8` modules when working with Fortran mod files. Mod files are intermediate files during Fortran
compilations.

## Python

### Anaconda

The Anaconda Python distrubtion ...

#### Python 3

```
module avail anaconda3
```

#### Python 2

```
module load anaconda
```

### System

The system Python is available if needed. This can be useful for building codes and other tasks. It should not be used for building isolated environments and running scientific codes.

```
$ python
-bash: python: command not found

$ python3
Python 3.6.8 (default, Dec  5 2019, 16:11:43) 
[GCC 8.3.1 20191121 (Red Hat 8.3.1-5)] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>>

$ python2
Python 2.7.17 (default, Oct 30 2019, 17:39:41) 
[GCC 8.3.1 20190507 (Red Hat 8.3.1-4)] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>>
```

In general, for scientific work one wants to use the Anaconda Python distribution which is described next.

## Deep Learning

[https://researchcomputing.princeton.edu/pytorch](https://researchcomputing.princeton.edu/pytorch)

[https://researchcomputing.princeton.edu/tensorflow](https://researchcomputing.princeton.edu/tensorflow)

Use the `conda-early-access` channel when you need a more recent version of PyTorch and TensorFlow than was is available.

Important Conda channels:

Note that `tensorrt` is available as a package.

## NVIDIA Rapids

Built based on the Apache Arrow columnar memory format, cuDF is a GPU DataFrame library for loading, joining, aggregating, filtering, and otherwise manipulating data.

cuDF provides a pandas-like API that will be familiar to data engineers & data scientists, so they can use it to easily accelerate their workflows without going into the details of CUDA programming.

cuML is a suite of libraries that implement machine learning algorithms and mathematical primitives functions that share compatible APIs with other RAPIDS projects.

cuML enables data scientists, researchers, and software engineers to run traditional tabular ML tasks on GPUs without going into the details of CUDA programming. In most cases, cuML's Python API matches the API from scikit-learn.

[Getting started](https://rapids.ai/start.html)

cuDF and cuML are available on the IBM conda channel. You can make an environment like this:

```
$ ssh traverse
$ module load anaconda3
$ conda create --name rapids-env --channel https://public.dhe.ibm.com/ibmdl/export/pub/software/server/ibm-ai/conda cudf cuml
# accept the license agreement
```

There are also dask-based packages available like `dask-cudf` which enble multi-GPU runs.

## CUDAToolkit

Note that `libcublas.so` is now in `/usr/lib64` as of version 10.1.

## PETSc

XL compilers don't work. ESSL cannot be used.

## Open MPI

To see how an Open MPI module was built:

```
$ module load openmpi/devtoolset-8/4.0.3rc1/64
$ ompi_info
```
