#include "logger.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <thread>



    Streamer::~Streamer() {};

      void Streamer::LogInfo(const std::string& time_, const std::string& func_name, const std::string& file_name, int line_number) {
        inside_stream_.str("");
        inside_stream_ << "TID["<< std::hash<std::thread::id>{}(std::this_thread::get_id())<< "][" <<time_ << "]" << " IN FILE <" << file_name  << "> IN LINE <" << line_number << "> IN FUNC <" <<  func_name << "> INFO_MSG:: ";
    }


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

    bool Streamer::checkAllStreams() {
        if(my_stream_.empty()) {
           throw  std::logic_error("Stream map is empty");
        }
        for(const auto&[num, vec_str] : my_stream_) {
            if(my_stream_.at(num).empty()) {
                std::cerr << "Stream at " << num <<  " is empty" << std::endl;
                throw std::logic_error("Stream is empty");
            }
        }
        return 1;
    }



    void Streamer::deleteStream(int num) {
       if(my_stream_.find(num) != my_stream_.end()) {
            my_stream_.erase(num);
            std::cerr << "Stream " << num << " delete" << std::endl;
       }
       throw std::invalid_argument("Don't have this stream");
    }


    void Streamer::deleteAllStream() {
        my_stream_.clear();
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
