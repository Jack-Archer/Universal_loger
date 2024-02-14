#include <iostream>

#include "logger.h"





int main(){
std::fstream fs("hello.txt",std::fstream::in | std::fstream::out | std::fstream::app);;
    LOG.addStream(1, &(std::cout));
    LOG.addStream(1, &fs);
    LOG.printAllStream();


    LOG[1]<< "I love you ALINKA";


return 0;
}
