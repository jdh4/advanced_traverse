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

### Simultaneous Multithreading (SMT)

```
$ snodes | head
HOSTNAMES     STATE    CPUS S:C:T    CPUS(A/I/O/T)   CPU_LOAD MEMORY   GRES     PARTITION          AVAIL_FEATURES
traverse-k01g alloc    128  2:16:4   128/0/0/128     4.03     250000   gpu:tesl all*               (null)
traverse-k01g alloc    128  2:16:4   128/0/0/128     4.08     250000   gpu:tesl all*               (null)
traverse-k01g idle     128  2:16:4   0/128/0/128     0.00     250000   gpu:tesl all*               (null)
traverse-k01g idle     128  2:16:4   0/128/0/128     0.04     250000   gpu:tesl all*               (null)
traverse-k01g resv     128  2:16:4   0/128/0/128     1.78     250000   gpu:tesl all*               (null)
traverse-k01g resv     128  2:16:4   0/128/0/128     1.74     250000   gpu:tesl all*               (null)
traverse-k01g resv     128  2:16:4   0/128/0/128     1.73     250000   gpu:tesl all*               (null)
traverse-k01g resv     128  2:16:4   0/128/0/128     1.74     250000   gpu:tesl all*               (null)
traverse-k01g alloc    128  2:16:4   128/0/0/128     0.02     250000   gpu:tesl all*               (null)
```

More information:

```
$ lscpu
Architecture:          ppc64le
Byte Order:            Little Endian
CPU(s):                128
On-line CPU(s) list:   0-127
Thread(s) per core:    4
Core(s) per socket:    16
Socket(s):             2
NUMA node(s):          6
Model:                 2.3 (pvr 004e 1203)
Model name:            POWER9, altivec supported
CPU max MHz:           3800.0000
CPU min MHz:           2300.0000
L1d cache:             32K
L1i cache:             32K
L2 cache:              512K
L3 cache:              10240K
NUMA node0 CPU(s):     0-63
NUMA node8 CPU(s):     64-127
NUMA node252 CPU(s):   
NUMA node253 CPU(s):   
NUMA node254 CPU(s):   
NUMA node255 CPU(s):   
```
