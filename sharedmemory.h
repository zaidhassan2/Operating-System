#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <QObject>
#include <sys/ipc.h>
#include <sys/shm.h>

class SharedMemory : public QObject {
    Q_OBJECT

public:
    static SharedMemory& instance() {
        static SharedMemory instance;
        return instance;
    }

    bool initialize() {
        shmid = shmget((key_t)8749, sizeof(int), IPC_CREAT | 0666);
        if (shmid == -1) {
            return false;
        }

        sharedData = (int*)shmat(shmid, NULL, 0);
        if (sharedData == (int*)(-1)) {
            return false;
        }

        return true;
    }

    void setTotalMemory(int memory) {
        totalMemory = memory;
        *sharedData = memory;
    }

    int getTotalMemory() const {
        return totalMemory;
    }

    int getAvailableMemory() const {
        return *sharedData;
    }

    void allocateMemory(int amount) {
        *sharedData -= amount;
    }

    void releaseMemory(int amount) {
        *sharedData += amount;
    }

    int getDiskSpace() const {
        return diskSpace;
    }

    void setDiskSpace(int space) {
        diskSpace = space;
    }

    int getCpuCores() const {
        return cpuCores;
    }

    void setCpuCores(int cores) {
        cpuCores = cores;
    }

private:
    SharedMemory() {
        initialize();
    }
    ~SharedMemory() {
        if (sharedData != (int*)(-1)) {
            shmdt(sharedData);
        }
    }

    SharedMemory(const SharedMemory&) = delete;
    SharedMemory& operator=(const SharedMemory&) = delete;

    int shmid;
    int* sharedData;
    int totalMemory = 0;
    int diskSpace = 0;
    int cpuCores = 0;
};

#endif // SHAREDMEMORY_H
