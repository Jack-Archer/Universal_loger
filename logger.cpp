#include "logger.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>


std::string LogExpr(const std::string& func_name, const std::string& file_name, int line_number) {
    std::stringstream ss{};
    ss  << "IN FILE <" << file_name  << "> IN LINE <" << line_number << "> IN FUNC <" <<  func_name << "> INFO_MSG:: ";
    return ss.str();
}


    Streamer::~Streamer() {};


    void Streamer::addStream(int num, std::ostream* ptr_stream) {
        if(my_stream_.find(num) != my_stream_.end()) {
          for(auto const stream : my_stream_.at(num)) {
            if(stream == ptr_stream) {
                std::cerr << "Stream already here" << std::endl;
                return;
            }
          }
            my_stream_.at(num).push_back(ptr_stream);
        } else {
            my_stream_[num].push_back(ptr_stream);
        }
    }





     void Streamer::deleteStream(){

    }


    const void Streamer::printStream(int number) const {

    }


    const void Streamer::printAllStream() const {
         for(const auto &[key, vec] : my_stream_) {
            std::cout << "key = "<< key << std::endl;
            for(const auto v : vec) {
                std::cout << &v << "  ";
            }
            std::cout << std::endl;
        }
    }
