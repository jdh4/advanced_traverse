# Head node

## TurboVNC

If you need to use graphical applications on the Traverse head node such as DDT or MAP then considering using TurboVNC. TurboVNC is based on VNC which has many advantages over X11 forwarding (i.e., `ssh -X`). There is a substantial amount of setup required but it is worth it. Begin by reading [this page](https://researchcomputing.princeton.edu/turbovnc) while substituting Traverse for Tigressdata. Be sure to use the shell functions at the bottom of the page to quickly use TurboVNC.

## Jupyter Notebooks

Follow the directions under "Running on Tigressdata" on [this page](https://researchcomputing.princeton.edu/jupyter). Be sure to replace `tigressdata` with `traverse`.

If using a VPN is not an option then use the directions under "Avoiding Using a VPN from Off-Campus". Once again be sure to replace `tigressdata` with `traverse`.
