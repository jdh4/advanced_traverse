# Overview of Traverse

## IBM POWER9 Achitecture

Traverse is composed of 46 IBM POWER9 nodes with four NVIDIA V100 GPUs per node. The cluster is primarily intended
to support research at the <a href="https://www.pppl.gov">Princeton
Plasma Physics Lab</a> (PPPL). Traverse is also available to Princeton researchers whose work is particularly
suited to the architecture of this system either because it is very similar to
the <a href="https://www.olcf.ornl.gov/olcf-resources/compute-systems/summit/">Summit cluster</a> at Oak Ridge National
Laboratory or because the application to be run can take particular advantage of
the <a href="https://www.nvidia.com/en-us/data-center/nvlink/">NVLink</a> architecture. Programs that move a lot of
data in or out of the GPU should see an especially large speed up.

1.4 PFlops

![smt-core](http://3s81si1s5ygj3mzby34dq6qf-wpengine.netdna-ssl.com/wp-content/uploads/2016/08/ibm-hot-chips-power9-smt4-core.jpg)

![nvlink](https://images.exxactcorp.com/CMS/technologies/nvidia-solutions/nvidia-nvlink-solutions/tesla-v100-nvlink-gpu-cpu-diagram.png)

Read an [article](https://www.princeton.edu/news/2019/10/07/princetons-new-supercomputer-traverse-accelerate-scientific-discovery-fusion) about the debut of Traverse.

ppcle64 is PowerPC little endian 64-bit memory model

## Onramp to Summit

Summit is 1000 times bigger than Traverse.

## Images

Data center photos

### Simultaneous Multithreading (SMT)

```
$ snodes | head
HOSTNAMES     STATE    CPUS S:C:T    CPUS(A/I/O/T)   CPU_LOAD MEMORY   GRES                                PARTITION          AVAIL_FEATURES
traverse-k01g alloc    128  2:16:4   128/0/0/128     4.09     250000   gpu:tesla_v100:4(S:0-1)             all*               rh8
traverse-k01g mix      128  2:16:4   68/60/0/128     71.92    250000   gpu:tesla_v100:4(S:0-1)             all*               rh8
traverse-k01g mix      128  2:16:4   68/60/0/128     73.42    250000   gpu:tesla_v100:4(S:0-1)             all*               rh8
traverse-k01g alloc    128  2:16:4   128/0/0/128     46.94    250000   gpu:tesla_v100:4(S:0-1)             all*               rh8
traverse-k01g alloc    128  2:16:4   128/0/0/128     44.85    250000   gpu:tesla_v100:4(S:0-1)             all*               rh8
traverse-k01g mix      128  2:16:4   68/60/0/128     72.70    250000   gpu:tesla_v100:4(S:0-1)             all*               rh8
traverse-k01g mix      128  2:16:4   116/12/0/128    90.92    250000   gpu:tesla_v100:4(S:0-1)             all*               rh8
traverse-k01g mix      128  2:16:4   16/112/0/128    5.70     250000   gpu:tesla_v100:4(S:0-1)             all*               rh8
traverse-k01g mix      128  2:16:4   68/60/0/128     71.29    250000   gpu:tesla_v100:4(S:0-1)             all*               rh8
```

More information:

```
$ lscpu
Architecture:        ppc64le
Byte Order:          Little Endian
CPU(s):              128
On-line CPU(s) list: 0-127
Thread(s) per core:  4
Core(s) per socket:  16
Socket(s):           2
NUMA node(s):        6
Model:               2.3 (pvr 004e 1203)
Model name:          POWER9, altivec supported
CPU max MHz:         3800.0000
CPU min MHz:         2300.0000
L1d cache:           32K
L1i cache:           32K
L2 cache:            512K
L3 cache:            10240K
NUMA node0 CPU(s):   0-63
NUMA node8 CPU(s):   64-127
NUMA node252 CPU(s): 
NUMA node253 CPU(s): 
NUMA node254 CPU(s): 
NUMA node255 CPU(s): 
```

Operating system:

```
$ cat /etc/os-release 
NAME="Red Hat Enterprise Linux"
VERSION="8.2 (Ootpa)"
ID="rhel"
ID_LIKE="fedora"
VERSION_ID="8.2"
PLATFORM_ID="platform:el8"
PRETTY_NAME="Red Hat Enterprise Linux 8.2 (Ootpa)"
ANSI_COLOR="0;31"
CPE_NAME="cpe:/o:redhat:enterprise_linux:8.2:GA"
HOME_URL="https://www.redhat.com/"
BUG_REPORT_URL="https://bugzilla.redhat.com/"

REDHAT_BUGZILLA_PRODUCT="Red Hat Enterprise Linux 8"
REDHAT_BUGZILLA_PRODUCT_VERSION=8.2
REDHAT_SUPPORT_PRODUCT="Red Hat Enterprise Linux"
REDHAT_SUPPORT_PRODUCT_VERSION="8.2"
```

While Traverse uses RHEL, the HPC clusters at Princeton use Springdale Linux. In most cases the
distinction is immaterial.
