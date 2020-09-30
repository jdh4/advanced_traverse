# SLURM

## Test Queue

There are four nodes reserved for test jobs of less than 1 hour. To use the test queue add this line to your Slurm script:

```
#SBATCH --reservation=test
```

## Turning Off SMT

Let's say that you want to run a job with 32 MPI processes on Traverse and have each process run on its own physical CPU-core. Here are some approaches for doing this:

```
== #1 ==

#SBATCH --nodes=1
#SBATCH --ntasks=128
#SBATCH --cpus-per-task=1
srun -n 32 ./a.out


== #2 ==

#SBATCH --nodes=1
#SBATCH --ntasks=128
#SBATCH --cpus-per-task=1
numactl -C 0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124 srun ./a.out


== #3 ==

#SBATCH --nodes=1
#SBATCH --ntasks=32
#SBATCH --cpus-per-task=1
#SBATCH --threads-per-core=1
srun ./a.out


== #4 ==

#SBATCH --nodes=1
#SBATCH --ntasks=32
#SBATCH --cpus-per-task=1
#SBATCH --ntasks-per-core=1
srun ./a.out
```

You there is concern with a lack of thread pinning then consider adding: `--cpu-bind=cores`

In general, you should take an entire node when that is reasonable. It helps solve problems. `--exclusive`
