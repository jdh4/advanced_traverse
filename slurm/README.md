# SLURM

## Test Queue

There are four nodes reserved for test jobs of less than 1 hour. To use the test queue add this line to your Slurm script:

```
#SBATCH --reservation=test
```
