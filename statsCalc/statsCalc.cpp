/*
statsCalc.cpp
Calculates central tendency trends given a dataset
*/
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <cmath>

class statsCalc {
    public:    
// class vars
    std::string dataSetStr;
    std::vector<long double> dataVector;
    int dataSetLen;
    long double mean;
    long double median;
    long double mode;
    long double range;
    long double stdDev;

// funcs
    void getData() {
        // define and get data set
        std::cout << "Data set separated by commas:" << std::endl;
        std::string dataSetStr;
        std::getline(std::cin, dataSetStr);

        // populate data vector
        // match vars
        std::regex numMatch(R"~(\d+)~");
        std::smatch numM;
        do {
            std::regex_search(dataSetStr, numM, numMatch);
            dataVector.push_back(std::stoi(numM[0]));
            dataSetStr.erase(numM.position(), numM.length() + 1);
        } while (std::regex_search(dataSetStr, numM, numMatch) != false);
        
        // sort data vector
        std::sort(dataVector.begin(), dataVector.end());

        // print vector contents (debug)
        std::cout << "interpreted [";
        for (auto num : dataVector) {
            std::cout << num << ", ";
        }
        std::cout << "]" << std::endl;
    }

    void calcMean() {
        // sum each term
        long double dataSum = 0;
        for (auto num : dataVector) {
            dataSum += num;
        }
        // calculate mean
        mean = dataSum / (long double) dataVector.size();
        std::cout << "Mean: " << mean << std::endl;
    }

    void calcMedian() {
        int dataVectorLen = dataVector.size();
        // check if length is odd or even
        if (dataVectorLen % 2 != 0) {
            auto p = (dataVectorLen + 1) / 2;
            median = dataVector[p - 1];
            std::cout << "Median: " << median << std::endl; // zero based vectors
        } else {
            auto p = (dataVectorLen) / 2;
            median = (dataVector[p - 1] + dataVector[p]) / 2;
            std::cout << "Median: " << median << std::endl; // zero based vectors
        }
    }


    /* 
    stops at first reoccurence of a digit and treats that as the mode
    ex. 1,2,2,11,11,11 mode should be 11, but says 2
    */
    void calcMode() {
        // iterate through vector using map to determine frequency
        int max = 0;
        std::map<long double, long double> m;
        for (auto vectorIndex: dataVector) {
            if (m[vectorIndex]++ > max) {
                max = m[vectorIndex];
                mode = vectorIndex;
            }
        }
        // handle if mode doesn't exist
        if (mode != 0) {
            std::cout << "Mode: " << mode << std::endl;
        } else {
            std::cout << "Mode: undefined" << std::endl;
        }
    }

    void calcRange() {
        range = dataVector.back() - dataVector.front();
        std::cout << "Range: " << range << std::endl;
    }

    void calcStdDeviation() {
        // calc summation
        long double sum;
        for (auto num : dataVector) {
            sum += std::pow((num - mean), 2);
        }
        // calc stddev
        stdDev = sqrtl(sum / dataVector.size());
        std::cout << "Standard Deviation: " << stdDev << std::endl;
    }
};

int main() {
    // class obj
    statsCalc classObj;
    // get data
    classObj.getData();
    // calc mean
    classObj.calcMean();
    // calc median
    classObj.calcMedian();
    // calc mode
    classObj.calcMode();
    // calc range
    classObj.calcRange();
    // calc stdDev
    classObj.calcStdDeviation();
    // persist window
    system("pause");
}