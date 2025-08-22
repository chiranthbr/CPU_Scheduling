class Process {
   public:

      int pid;
      int arrivalTime;
      int burstTime;
      int waitingTime;
      int completedTime;
      int completedAt;

      Process(int pid, int atime, int btime);
};
