#include <iostream>
#include <fstream>
#include <string>

class FormatProcessor {
public:
  FormatProcessor(const std::string& filename) : filename_(filename) {}
  virtual ~FormatProcessor() = default;
  virtual std::string Read() = 0;
  virtual void Write(const std::string&) = 0;
  virtual void Write(int) = 0;

protected:
  std::ifstream in_;
  std::ofstream out_;
  std::string value_;
  std::string filename_;
};

class ASCIIProcessor : public FormatProcessor {
public:
  // ASCIIProcessor(const std::string& filename) : FormatProcessor(filename) {}
  using FormatProcessor::FormatProcessor; 

  std::string Read() override {
    in_.open(filename_);
    if(!in_.is_open()) {
      throw std::runtime_error("[Read]: file not opened");
    }
    // std::string p; // SSO
    in_ >> value_;
    in_.close();
    return value_;
  }
  void Write(const std::string& msg) override {
    out_.open(filename_);
    if(!out_.is_open()) {
      throw std::runtime_error("[Write]: file not opened");
    }
    out_ << msg;
    out_.close();
  }
  void Write(int msg) override {
    out_.open(filename_);
    if(!out_.is_open()) {
      throw std::runtime_error("[Write]: file not opened");
    }
    out_ << msg;
    out_.close();
  }
};

class BinaryProcessor : public FormatProcessor {
public:
  using FormatProcessor::FormatProcessor; 

  std::string Read() override {
    in_.open(filename_, std::ios::binary);
    if(!in_.is_open()) {
      throw std::runtime_error("[Read]: file not opened");
    }
    // std::string p; // SSO
    int x;
    in_.read(reinterpret_cast<char*>(&x), sizeof(int));
    in_.close();
    return std::to_string(x);
  }
  void Write(const std::string& msg) override {
    out_.open(filename_, std::ios::binary);
    if (!out_.is_open()) {
      throw std::runtime_error("[Write]: file not opened");
    }
    out_ << msg;
    out_.close();
  }
  void Write(int value) override {
    out_.open(filename_, std::ios::binary);
    if (!out_.is_open()) {
      throw std::runtime_error("[Write]: file not opened");
    }
    out_.write(reinterpret_cast<const char*>(&value), sizeof(int));
    out_.close();
  }
};

int main() {
  try {
    BinaryProcessor binary_processor("test.txt");
    binary_processor.Write(2'147'000'000);
    std::cerr << binary_processor.Read() << std::endl;
  }
  catch (const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
  catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }
}