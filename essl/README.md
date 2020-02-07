# Engineering and Scientific Library (ESSL)

Pronounced like the two letters "SL".

Does work with gromacs.

Does not work with PETSc.

## PETSc

According to the [PETSc installation page](https://www.mcs.anl.gov/petsc/documentation/installation.html):

> Sadly, IBM's ESSL does not have all the routines of BLAS and LAPACK that some packages, such as SuperLU expect; in particular slamch, dlamch and xerbla. In this case instead of using ESSL we suggest --download-fblaslapack. If you really want to use ESSL, see https://www.pdc.kth.se/hpc-services.
