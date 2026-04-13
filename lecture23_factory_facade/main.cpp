#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "ext/nlohman/json.hpp"

namespace fs = std::filesystem;

const std::string TXT_EXTENSION = ".txt";
const std::string BIN_EXTENSION = ".bin";
const std::string JSON_EXTENSION = ".json";

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
  using FormatProcessor::FormatProcessor; 

  std::string Read() override {
    in_.open(filename_);
    if(!in_.is_open()) {
      throw std::runtime_error("[Read]: file not opened");
    }
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

class JSONProcessor : public FormatProcessor {
public:
  using FormatProcessor::FormatProcessor; 

  std::string Read() override {
    // TODO
    return "fake_string";
  }
  void Write(const std::string& msg) override {
    // TODO
  }
  void Write(int value) override {
    out_.open(filename_);
    if (!out_.is_open()) {
      throw std::runtime_error("[Write]: file not opened");
    }
    nlohmann::json output_data = {
      {"age", value}
    };
    out_ << output_data;
    out_.close();
  }
};

enum class FormatType {
  ASCII = 0,
  BINARY,
  JSON
};

FormatType define_type(const fs::path& filename) {
  FormatType type;
  std::string ext = filename.extension().string();
  if (ext == TXT_EXTENSION) {
    type = FormatType::ASCII;
  }
  else if (ext == BIN_EXTENSION) {
    type = FormatType::BINARY;
  }
  else if (ext == JSON_EXTENSION) {
    type = FormatType::JSON;
  }
  else {
    throw std::invalid_argument("[define_type]: unsupported file extension");
  }
  return type;
}

FormatProcessor* create_processor(FormatType type, const std::string& filename) {
  // check is extension is ok
  if (type == FormatType::ASCII) {
    return new ASCIIProcessor(filename);
  }
  if (type == FormatType::BINARY) {
    return new BinaryProcessor(filename);
  }  
  if (type == FormatType::JSON) {
    return new JSONProcessor(filename);
  }    
  throw std::invalid_argument("[create_processor]: not supported type");
}

class ProcessorFacade {
public:
  void Create(const std::vector<fs::path>& filenames) {
    for (size_t i = 0; i < filenames.size(); ++i) {
      // 1. std::string, crop extension after dot
      FormatType type = define_type(filenames[i]);
      processors_.emplace_back(create_processor(type, filenames[i].string()));
    }
  }
  void Write(int value) {
    for (size_t i = 0; i < processors_.size(); ++i) {
      processors_[i]->Write(value);
    }
  }
  ~ProcessorFacade() {
    for (size_t i = 0; i < processors_.size(); ++i) {
      delete processors_[i];
    }
  }
private:
  std::vector<FormatProcessor*> processors_;
};

int main() {
  ProcessorFacade processors_facade;
  try {
    processors_facade.Create({"input.txt", "input.bin", "input.json"});
    processors_facade.Write(123);
  }
  catch (const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
  catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }
}