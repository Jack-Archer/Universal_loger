#pragma once

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <fstream>
#include <memory>
#include <exception>
#include <execution>
#include <unistd.h>



#define CREATE_LOG Streamer::instance()
#define LOG Streamer::instance().LogInfo(__TIMESTAMP__, __FUNCTION__, __FILE__, __LINE__), Streamer::instance()



using user_stream = std::unordered_map<int, std::vector<std::ostream*>>;

class Streamer {
public:

    static Streamer& instance() {
        static Streamer  instance;
        return instance;
    }

    template <typename Type>
    Streamer &operator<<(const Type msg) {
        inside_stream_ << msg << std::endl;
        std::for_each((*stream_ptr_).rbegin(), (*stream_ptr_).rend(),[this](auto &strm){
            *strm << inside_stream_.str();
        });
        return *this;
    }

   Streamer &operator[](int num) {
        stream_ptr_ = nullptr;
        if(my_stream_.find(num) != my_stream_.end()) {
             stream_ptr_ = std::make_unique<std::vector<std::ostream*>>(my_stream_.at(num));
            return *this;
        } else {
            throw std::invalid_argument("Don't have this stream");
        }
    }


    void addStream(int num, std::ostream* ptr_stream);
    bool checkAllStreams();


    void deleteStream(int num);
    void deleteAllStream();
    const void printAllStream() const;

    void LogInfo(const std::string& time_, const std::string& func_name, const std::string& file_name, int line_number);


private:
    Streamer() = default;
    ~Streamer();
    Streamer(const Streamer&) = delete;
    Streamer& operator=( Streamer& ) = delete;

    user_stream my_stream_{};
    std::unique_ptr<std::vector<std::ostream*>> stream_ptr_{nullptr};
    std::stringstream inside_stream_{};
};

