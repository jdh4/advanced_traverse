# NVIDIA Tensor Cores

The V100 GPUs have 640 Tensor Cores (8 per streaming multiprocessor) where half-precision Warp Matrix-Matrix and
Accumulate (WMMA) operations can be carried out. That is, each Tensor Core can multiply two 4 x 4 matrices together
in half-precision and add the result to a third matrix which is in full precision. This is especially useful for
training and inference on deep neural networks.

![volta](https://devblogs.nvidia.com/wp-content/uploads/2017/05/image3.png)
