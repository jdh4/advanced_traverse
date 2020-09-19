# Leveraging the Advanced Capabilities of the Traverse Supercomputer

## Outline

Intro to Traverse
- 46 POWER9 + NVIDIA V100 (head node has 2 GPUs)
- NVLink and GPU Direct
- Each socket connects to an IB card running EDR (100Gb/s)
- I never found a picture showing 4 hardware threads per core
- This section should be short. I hope we can offer demos/results of specific things that will actually change how people work instead of lots of overview.

SLURM and Queueing
- update on test queue
- turning off SMT
- QoS

Compilers
- GCC 8.3.1 is now the base version for the system (use rh/7 only when needed)
- I played a lot with the XL compiler and VSX vectorization and got nothing out of it even for a code that was tailored for vectorization
- We should list optimization flags for GCC, PGI, XL and GPU flags
- PGI (a.k.a. NVIDIA HPC SDK) preferred for OpenACC GPU programming 

MPI
- Josko's "in place" module substitutions (we cannot use a print statement in module to alert people)
- CUDA-Aware MPI (overview and modules)
- SHArP (I need to work on this)
- No IBM Spectrum MPI

TensorCores (JH)
- I can show results of this using PyTorch and the NVIDAI Apex library
- Important that people know about this since A100's have even more of these
- I want to show people the TensorFlow and PyTorch webpages as well as different software in the IBM Conda AI channel (eg, cuDF and cuML).

MPS (do you want this one) 
- Would be good to have results for with/without

MAP/DDT
- update on license and usage (now 576 processes)
- I have directions for debugging CUDA kernels

Numerical libraries
- ESSL (I can talk about this)
- MAGMA
- cuBLAS, cuFFT, etc.

TurboVNC - I tried this a few days ago and it did not work
- We should also use this workshop as an opportunity to take requests. Maybe a brief discussion about a proper viz /post-analysis node
- Running Jupyter notebooks on head node (we allow this)

Filesystems and NVMe
- Would be good to have a demo/results for NVMe. I find the speeds are only better than /scratch/gpfs when writing large files or large block size so not useful to most

## About

This guide shows how to take advantage of the advanced features of Traverse including:

- GPU Direct
- NVLink
- CUDA Multi-Process Service (MPS)
- CUDA-Aware MPI
- NVIDIA V100 GPU Tensor Cores
- Scalable Hierarchical Aggregation Protocol (SHArP)
- IBM POWER9 architecture
- VSX vectorization
- Simultaneous Multithreading (SMT)
- GPU-enabled IBM Engineering and Scientific Subroutine Library (ESSL)
- IBM XL and PGI compilers
- NVMe storage

## Workshop Survey

After the workshop please complete [this survey](https://forms.gle/wJsovb7nw8nCJbop9).

## Getting Help

If you encounter any difficulties with the material in this guide then please send an email to <a href="mailto:cses@princeton.edu">cses@princeton.edu</a> or attend a <a href="https://researchcomputing.princeton.edu/education/help-sessions">help session</a>.

## Authorship

This guide was created by Jonathan Halverson, Stéphane Ethier and members of Princeton Research Computing.
