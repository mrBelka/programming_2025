#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void readFrom1To10(int x) {
    if (x < 1 || x > 10) {
        std::stringstream s;
        s << "[readFrom1To10]: Expected argument from 1 to 10. Got " << x << " " << __FILE__ 
        << " " << __LINE__; 
        throw std::invalid_argument(s.str());
    }
}

int divide_except(int a, int b) {
    if (b == 0) {
        throw std::logic_error("[divide_except]: B is equal 0.");
    }
    return a / b;
}

int divide(int a, int b, int& errorCode) {
    if (b == 0) {
        std::cerr << "B is equal 0 in " << __FILE__ << __LINE__ << std::endl;
        errorCode = -1;
        return 0;
    }
    errorCode = 0;
    return a / b;
}

void foo() {
    divide_except(1,0);
    readFrom1To10(1);
}

int main() {
    try {
        foo();
    } 
    catch(const std::invalid_argument& ex) {
        std::cerr << "Invalid argument" << std::endl;
        std::cerr << ex.what() << std::endl;
    }
    catch(const std::logic_error& ex) {
        std::cerr << "Logic error" << std::endl;
        std::cerr << ex.what() << std::endl;
    }
    catch(const std::exception& ex) {
        std::cerr << "Exception" << std::endl;
        std::cerr << ex.what() << std::endl;
    }
    catch(...) {
        std::cerr << "Unhandled error" << std::endl;
    }
    /*int a = 10;
    int b = 0;
    int c;
    try {
        c = divide_except(a, b);
    } catch(const char* msg) {
        std::cerr << "Const char* " << msg << std::endl;
        return -1;
    }catch(int errorCode) {
        std::cerr << "Int " << errorCode << std::endl;
        return -1;
    } catch(float errorCode) {
        std::cerr << "Float " << errorCode << std::endl;
        return -1;
    } catch (...) {
        std::cerr << "Unhandled error" << std::endl;
        return -1;
    }*/


    /*int a = 10;
    int b = 0;
    int errorCode;
    int c = divide(a, b, errorCode);
    if (errorCode != 0)
        return -1;
    }
    std::cout << c << std::endl;*/

    /*int a = 10;
    int b;
    std::cin >> b;
    if (b == 0) {
        std::cerr << "B is equal 0 in " << __FILE__ << __LINE__ << std::endl;
        return -1;
    }
    int c = a / b;*/
}