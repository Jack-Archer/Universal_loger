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


std::string  LogExpr(const std::string& func_name, const std::string& file_name, int line_number);

#define LOG_INFO LogExpr(__FUNCTION__, __FILE__, __LINE__)
#define LOG Streamer::instance()

/*enum class StreamType {
};*/


using user_stream = std::unordered_map<int, std::vector<std::ostream*>>;

class Streamer {
public:

    static Streamer& instance() {
        static Streamer  instance;
        return instance;
    }

    template <typename Type>
    Streamer &operator<<(const Type msg) {
        //inside_stream_.clear();
        //inside_stream_ << msg;
        std::for_each((*stream_ptr_).rbegin(), (*stream_ptr_).rend(),[this, &msg](auto &strm){
            //*strm << inside_stream_.str();
            *strm << msg;
            *strm << std::endl;
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

    template <typename It>
    void addStream(int num, It beg_, It end_) {

    }

    void deleteStream();
    const void printStream(int number) const;
    const void printAllStream() const;


private:
    Streamer() = default;
    ~Streamer();
    Streamer(const Streamer&) = delete;
    Streamer& operator=( Streamer& ) = delete;

    user_stream my_stream_{};
    std::unique_ptr<std::vector<std::ostream*>> stream_ptr_{nullptr};
    //std::stringstream inside_stream_{};
};

