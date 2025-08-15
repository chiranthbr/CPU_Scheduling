class Process {
   public:

      int pid;
      int arrivalTime;
      int burstTime;
      int waitingTime;
      int completedTime;

      Process(int pid, int atime, int btime);

      void changeBurstAndWaitingTime(int btime, int wtime);
};
