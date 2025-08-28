## CPU Scheduling Algorithms Visualiations

An interactive in-terminal visualization of scheduling algorithms, with a cool menu based interface to select the algorithm of your choice. Just provide the amount of processes and see, how OS will schedule each process by using different algorithms. I have included a progress bar for each process, which gives the amount of process executed, along with the process which is present in CPU and executing right now.

For now, below mentioned algorithms can be visualized:
- First come First serve (FCFS)
- Shortest Job First (SJB)
- Round Robin (RR) (!! Ongoing )
- (More incoming..)

# Installation guide:

- Clone repo in a directory
- cd into the directory
- `cd build` (for building the project)
- `cmake .. && make`
- `./cpuScheduling`

How to use:
- Select algorithm by using either Arrow keys ("up, down" or "left, right") or 'j' and 'k' for vim users
- It will ask for number of processes to begin with
- The visuals starts
- After visuals complete, press any key to see the stats (avg. WT, avg. TAT, etc)

