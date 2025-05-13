#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

template<typename T>
class Logger {
private:
    std::ofstream m_file;
    std::string m_filename;
public:
    Logger(const std::string& filename)
    :m_filename(filename)
    {
        m_file.open(filename, std::ios::app); 
        if (!m_file.is_open()) {
            throw std::runtime_error("Failed to open log file: " + filename);
        }
    }

    ~Logger() {
        if (m_file.is_open()) {
            m_file.close();
        }
    }

    void log(const T& message) {
        m_file << message << std::endl;
    }

    void clear() {
        if (m_file.is_open()) {
            m_file.close();
        }
        openFile(std::ios::trunc); // Clear log-file
    }

private:
    void openFile(std::ios_base::openmode mode) {
        m_file.open(m_filename, mode);
        if (!m_file.is_open()) {
            throw std::runtime_error("Failed to open log-file: " + m_filename);
        }
    }
};
