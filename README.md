# Modified-Linux-Scheduler
A modified CFS Scheduler with added soft real-time requirement functionalities to it which has a higher priority than vruntime, along with added system call to modify process’s new real time requirements.


## Testing

- Patch the diff file onto the Linux Kernel Versional 5.9.1 and compile and install it onto your system.
- Test the newly added functionality from the test files.
