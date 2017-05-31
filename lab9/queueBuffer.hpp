#ifndef QUEUEBUFFER_HPP
#define QUEUEBUFFER_HPP
#include <queue>

class QueueBuffer {
private:
  std::queue<int> myIntQueue;
  int percentage;
  int roundsToPlay;
  int queueLengthCurrent;
  int queueLengthPrevious;
  int queueAverage;

public:
  QueueBuffer(int p, int rtp) {
    percentage = p;
    roundsToPlay = rtp;
    queueLengthCurrent = 0;
    queueLengthPrevious = 0;
    queueAverage = 0;
  }
  void runQueueBuffer();
  void displayQueueBuffer();
};

#endif
