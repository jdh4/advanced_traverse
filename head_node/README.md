# Head Node

The head node `traverse.princeton.edu` can be used for compiling codes, running short test jobs, submitting batch jobs and so on. Two V100 GPUs are available on the head node. Make sure that you do not use more than 10% of the machine (cores and memory) for more than 10 minutes at a time since it is shared by all users.

## Jupyter Notebooks

To run a Jupyter Notebook or JupyterLab on the Traverse head node follow the directions under "Running on Tigressdata" on [this page](https://researchcomputing.princeton.edu/jupyter#tigressdata) replacing `tigressdata` with `traverse`.

If using a VPN is not an option then use the directions under "Avoiding Using a VPN from Off-Campus". Once again be sure to replace `tigressdata` with `traverse`.

## TurboVNC

If you need to use graphical applications on the Traverse head node such as DDT, MAP or an IDE then considering using TurboVNC. TurboVNC is based on VNC which has many advantages over X11 forwarding (i.e., `ssh -X`). There is a substantial amount of setup required but it is worth it. Begin by reading [this page](https://researchcomputing.princeton.edu/turbovnc) while substituting `traverse` for `tigressdata`. Be sure to use the shell functions at the bottom of the page to quickly use TurboVNC.
