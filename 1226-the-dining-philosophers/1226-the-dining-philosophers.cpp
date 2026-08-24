#include <mutex>

std::mutex forks[5];
class DiningPhilosophers {
public:
    DiningPhilosophers() {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
      int leftForkNum = philosopher % 5;
      int rightForkNum = (philosopher + 1) % 5;
      
      if (philosopher % 5 == 0) {
        swap(leftForkNum, rightForkNum);
      }
      
      // Acquire left fork then right fork
      forks[leftForkNum].lock();
      forks[rightForkNum].lock();
      
      pickLeftFork();
      pickRightFork();
      eat();
      
      putRightFork();
      putLeftFork();
      forks[rightForkNum].unlock();
      forks[leftForkNum].unlock();
		
    }
};