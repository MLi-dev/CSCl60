//
// Created by Matthew Li on 1/20/22.
//

#ifndef SD_SD_H
#define SD_SD_H
#include <string>


class Sd {
private:
    std::string name_;
    int capacity_;
    int memUsed_;
public:
    Sd();
    Sd(std::string SdName, int cap, int mem);
    //pre: mem must be less than cap.
    //post: sets the values for sd name, capacity, and memory.
    std::string getName();
    int getCapacity();
    int getMemUsed();
    bool takePicture();
    void empty();
    bool dump(Sd& sd);

};


#endif //SD_SD_H
