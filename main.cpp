#include <iostream>



#include "logger.h"





int main(){

    std::fstream fs("hello.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    CREATE_LOG.addStream(1, &(std::cout));
    CREATE_LOG.addStream(1, &fs);
    CREATE_LOG.addStream(2, &(std::cout));
    CREATE_LOG.addStream(2, &fs);
    CREATE_LOG.addStream(3, &(std::cout));
    CREATE_LOG.addStream(3, &fs);

    CREATE_LOG.printAllStream();
    //CREATE_LOG.deleteAllStream();
    CREATE_LOG.deleteStream(4);
    std::cout << std::endl;
    if(CREATE_LOG.checkAllStreams()) {
        LOG[1]<< "STREAM 1";
        LOG[2]<< "STREAM 2";
        LOG[3]<< "STREAM 3";
        LOG[3]<< "ADD STREAM 3";
        LOG[3]<< "ADD STREAM 3";
    }





return 0;
}
