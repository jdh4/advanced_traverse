# NVMe Storage

Each Traverse node has a non-nolatile memory express (NVMe) card which can be thought of as a hard drive that is especially
fast in certain cases. However,
fast read and write speeds can only be achieved for large block sizes. One will not see a performance boost over
the other filesystems (e.g., `/scratch/gpfs/`) otherwise.

```
$ ssh traverse
dd if=/dev/zero of=/scratch/myfile bs=1M count=10
```

## Applications that can utilize the NVMe cards

None.

## Globus

traverse-dtn
