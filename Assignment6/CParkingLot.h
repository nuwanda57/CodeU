#ifndef REARRANGING_CARS_CPARKINGLOT_H
#define REARRANGING_CARS_CPARKINGLOT_H

#include <iostream>
#include <map>
#include <vector>

class CParkingLot {
private:
    int NumberOfPlaces_;
    int CarsToRearrange_;
    int ResultingZeroPlace_; // the number of place that must be empty after the rearrangement
    std::vector<std::pair<int, int>> Rearranging_; // answer
    std::map<int, int> PlacesToCars_;
    std::map<int, int> CarsToPlaces_;
    std::map<int, int> ResultingPlacesToCars_;
    std::map<int, int> ResultingCarsToPlaces_;

    void get_parking_information(std::map<int, int>& PlacesToCars, std::map<int, int>& CarsToPlaces); // for input
    void rotate();
    void rearrange();
public:
    CParkingLot();
    CParkingLot(std::vector<int>& FirstState, std::vector<int>& SecondState);
    void how_to_rearrange();
};


#endif //REARRANGING_CARS_CPARKINGLOT_H
