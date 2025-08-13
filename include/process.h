class Process {
   public:

      int pid;
      int arrivalTime;
      int burstTime;
      int waitingTime;

      Process(int pid, int atime, int btime) : pid(pid), arrivalTime(atime), burstTime(btime), waitingTime(0) {}

      void changeBurstAndWaitingTime(int btime, int wtime);
};
