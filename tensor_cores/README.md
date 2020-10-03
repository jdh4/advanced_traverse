# NVIDIA Tensor Cores

The V100 GPUs have 640 Tensor Cores (8 per streaming multiprocessor) where half-precision Warp Matrix-Matrix and
Accumulate (WMMA) operations can be carried out. That is, each Tensor Core can multiply two 4 x 4 matrices together
in half-precision and add the result to a third matrix which is in full precision. This is especially useful for
training and inference on deep neural networks.

![volta](https://devblogs.nvidia.com/wp-content/uploads/2017/05/image3.png)

NVIDIA has invested in Tensor Cores in the [A100](https://www.nvidia.com/en-us/data-center/a100).

## Example from Deep Learning

The [Apex](https://github.com/nvidia/apex) library allows for [automatic mixed-precision](https://docs.nvidia.com/deeplearning/performance/mixed-precision-training/index.html) (AMP) training and distributed training:

```
$ ssh <YourNetID>@adroit.princeton.edu  # mixed precision only possible on V100
$ module load anaconda3/2020.2 rh/devtoolset/8 cudatoolkit/10.2
$ conda activate dark-env-v2
$ cd software/dark
$ git clone https://github.com/NVIDIA/apex
$ cd apex
$ export TORCH_CUDA_ARCH_LIST="7.0"
$ CUDA_HOME=/usr/local/cuda-10.2 pip install -v --no-cache-dir --global-option="--cpp_ext" --global-option="--cuda_ext" ./
```

The speed-up comes from using the Tensor Cores on the GPU applied to matrix multiplications and convolutions. However, to use fp16 the dimension of each matrix must be a multiple of 8. Read about the constraints [here](https://docs.nvidia.com/deeplearning/performance/mixed-precision-training/index.html#opt-tensor-cores).

For simple PyTorch codes these are the necessary changes:

```
from apex import amp
...
model, optimizer = amp.initialize(model, optimizer, opt_level="O1")
...
with amp.scale_loss(loss, optimizer) as scaled_loss:
    scaled_loss.backward()
```

To see the half-precision speed up a code, download the [dcgan example](https://github.com/NVIDIA/apex/tree/master/examples/dcgan) and run it with these parameters:

```
# set download=False in main_amp.py for the data set (see below)
#SBATCH --cpus-per-task=4
[1] python main_amp.py --opt_level O1 --dataroot /scratch/network/jdh4/dcgan --workers $SLURM_CPUS_PER_TASK
[2] python main_amp.py --opt_level O0 --dataroot /scratch/network/jdh4/dcgan --workers $SLURM_CPUS_PER_TASK
```

On the V100 node, for [1] the run time was found to be 6:59 and [2] gave 9:43. One also gets 9:43 if you go through and strip out all amp code instead of trusting the O0 setting. Note that the choice of O3 gave NaNs. O1 is the recommended optimization level by NVIDIA.

To go further one can profile with `nsys` and then use `nsight-sys` to see that the fp16 kernels are being called.

You need to download the data on the head node since compute nodes don't have internet access. This script can be used:

```
import torchvision
import torchvision.datasets as dset
import torchvision.transforms as transforms
    
dataset = dset.CIFAR10(root='./', download=True,
                           transform=transforms.Compose([
                               transforms.Resize(64),
                               transforms.ToTensor(),
                               transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5)),
                           ]))
```
11:22,  8 cores, O0 (95467)  
10:35,  8 cores, O1 (95466)  
10:15, 16 cores, O0 (95392)  
09:17, 16 cores, O1 (95391)    
11:00, 32 cores, O0 (95463)  
09:15, 32 cores, 01 (95464)  

## Other examples where Tensor Cores can be used

- [NVIDIA blog post on using Tenor Cores with Fortran](https://developer.nvidia.com/blog/bringing-tensor-cores-to-standard-fortran/)
- MAGMA
- CUB
- cuTensor
