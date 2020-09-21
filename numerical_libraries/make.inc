#//////////////////////////////////////////////////////////////////////////////
#   -- MAGMA (version 2.5.3) --
#      Univ. of Tennessee, Knoxville
#      Univ. of California, Berkeley
#      Univ. of Colorado, Denver
#      @date March 2020
#//////////////////////////////////////////////////////////////////////////////

# GPU_TARGET contains one or more of Fermi, Kepler, or Maxwell,
# to specify for which GPUs you want to compile MAGMA:
#     Fermi   - NVIDIA compute capability 2.x cards
#     Kepler  - NVIDIA compute capability 3.x cards
#     Maxwell - NVIDIA compute capability 5.x cards
#     Pascal  - NVIDIA compute capability 6.x cards
# The default is "Fermi Kepler".
# Note that NVIDIA no longer supports 1.x cards, as of CUDA 6.5.
# See http://developer.nvidia.com/cuda-gpus
#
GPU_TARGET ?= Volta

# --------------------
# programs

CC        = gcc
CXX       = g++
NVCC      = nvcc
FORT      = gfortran

ARCH      = ar
ARCHFLAGS = cr
RANLIB    = ranlib


# --------------------
# flags

# Use -fPIC to make shared (.so) and static (.a) library;
# can be commented out if making only static library.
FPIC      = -fPIC

CFLAGS    = -Ofast -mcpu=power9 $(FPIC) -fopenmp -DNDEBUG -DADD_ -Wall -Wshadow 
FFLAGS    = -Ofast $(FPIC)       -DNDEBUG -DADD_
F90FLAGS  = -Ofast $(FPIC)       -DNDEBUG -DADD_
NVCCFLAGS = -O3 --use_fast_math -arch=sm_70 --std=c++11 -DNDEBUG -DADD_ -Xcompiler "-mno-float128 $(FPIC) -Wall -Wno-unused-function"
LDFLAGS   = $(FPIC) -fopenmp

# C++11 (gcc >= 4.7) is not required, but has benefits like atomic operations
CXXFLAGS := $(CFLAGS) -std=c++11
CFLAGS   += -std=c99


# --------------------
# libraries

# ESSL is not LAPACK complete, so reference LAPACK must be added
LIB       = -lesslsmp -lpthread -lstdc++ -lm -llapack

LIB      += -lcublas -lcusparse -lcudart -lcudadevrt

# --------------------
# directories

# define library directories preferably in your environment, or here.
PU_ESSL_ROOT ?= /opt/ibmmath/essl/6.1
PU_CUDA_ROOT ?= /usr/local/cuda-10.2
#-include make.check-cuda

LIBDIR    = -L$(PU_CUDA_ROOT)/lib64 \
            -L$(PU_ESSL_ROOT)/lib64

INC       = -I$(PU_CUDA_ROOT)/include \
            -I$(PU_ESSL_ROOT)/include
