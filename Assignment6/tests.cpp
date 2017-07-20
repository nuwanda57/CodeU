#include <vector>
#include "tests.h"
#include "CParkingLot.h"


void AllTests() {
    TestAlgorithm_v0();
    TestAlgorithm_v1();
    TestAlgorithm_v2();
    TestAlgorithm_v3();
    TestAlgorithm_v4();
    TestAlgorithm_v5();
}


void TestAlgorithm(std::vector<int>& FirstState, std::vector<int>& SecondState){
    std::cout << "output:" << std::endl;
    CParkingLot ParkingLot(FirstState, SecondState);
    ParkingLot.how_to_rearrange();
}


void TestAlgorithm_v0(){ // empty
    std::cout << "__Empty Parking__" << std::endl;
    std::cout << "Given vectors: [], []" << std::endl;
    std::vector<int> FirstState (0);
    std::vector<int>SecondState (0);
    TestAlgorithm(FirstState, SecondState);
    std::cout << "\n\n";
}


void TestAlgorithm_v1() { // no cars
    std::cout << "__No cars__" << std::endl;
    std::cout << "Given vectors: [0], [0]" << std::endl;
    std::vector<int> FirstState = {0};
    std::vector<int>SecondState = {0};
    TestAlgorithm(FirstState, SecondState);
    std::cout << "\n\n";
}


void TestAlgorithm_v2() { // equals
    std::cout << "__Equal arrays__" << std::endl;
    std::cout << "Given vectors: " << std::endl;
    std::cout << "[4, 1, 3, 2, 0]" << std::endl;
    std::cout << "[4, 1, 3, 2, 0]" << std::endl;
    std::vector<int> FirstState = {4, 1, 3, 2, 0};
    std::vector<int>SecondState = {4, 1, 3, 2, 0};
    TestAlgorithm(FirstState, SecondState);
    std::cout << "\n\n";
}


void TestAlgorithm_v3() { // cycle
    std::cout << "__Cycle__" << std::endl;
    std::cout << "Given vectors:" << std::endl;
    std::cout << "[2, 3, 4, 1, 0]" << std::endl;
    std::cout << "[3, 4, 1, 0, 2]" << std::endl;
    std::vector<int> FirstState = {2, 3, 4, 1, 0};
    std::vector<int>SecondState = {3, 4, 1, 0, 2};
    TestAlgorithm(FirstState, SecondState);
    std::cout << "\n\n";
}


void TestAlgorithm_v4() { // empty place in cycle
    std::cout << "__Empty place in cycle__" << std::endl;
    std::cout << "Given vectors:" << std::endl;
    std::cout << "[6, 4, 3, 5, 1, 0, 2]" << std::endl;
    std:: cout << "[6, 3, 5, 4, 2, 1, 0]" << std::endl;
    std::vector<int> FirstState = {6, 4, 3, 5, 1, 0, 2};
    std::vector<int>SecondState = {6, 3, 5, 4, 2, 1, 0};
    TestAlgorithm(FirstState, SecondState);
    std::cout << "\n\n";
};


void TestAlgorithm_v5() { // empty place in the right place
    std::cout << "__Empty place in the right place__" << std::endl;
    std::cout << "Given vectors:" << std::endl;
    std::cout << "[0, 6, 4, 3, 5, 1, 2]" << std::endl;
    std:: cout << "[0, 6, 3, 5, 4, 2, 1]" << std::endl;
    std::vector<int> FirstState = {6, 4, 3, 5, 1, 0, 2};
    std::vector<int>SecondState = {6, 3, 5, 4, 2, 1, 0};
    TestAlgorithm(FirstState, SecondState);
    std::cout << "\n\n";
};