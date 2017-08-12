#include "CParkingLot.h"


CParkingLot::CParkingLot() {
    std::cout << "How many places are in the parking lot?" << std::endl;
    std::cin >> NumberOfPlaces_;

    if (NumberOfPlaces_ > 0) {
        std::cout << "Describe the parking lot" << std::endl;
    }
    get_parking_information(PlacesToCars_, CarsToPlaces_);

    if (NumberOfPlaces_ > 0) {
        std::cout << "How should we rearrange the parking lot?" << std::endl;
    }
    get_parking_information(ResultingPlacesToCars_, ResultingCarsToPlaces_);
    ResultingZeroPlace_ = ResultingCarsToPlaces_[0];
}


void CParkingLot::get_parking_information(std::map<int, int>& PlacesToCars, std::map<int, int>& CarsToPlaces) {
    int new_car;
    for (int place = 0; place < NumberOfPlaces_; ++place) {
        std::cin >> new_car;
        PlacesToCars[place] = new_car;
        CarsToPlaces[new_car] = place;
    }
}


CParkingLot::CParkingLot(std::vector<int> &FirstState, std::vector<int> &SecondState) {
    NumberOfPlaces_ = std::min(FirstState.size(), SecondState.size());
    for(int place = 0; place < NumberOfPlaces_; ++place) {
        PlacesToCars_[place] = FirstState[place];
        CarsToPlaces_[FirstState[place]] = place;
        ResultingPlacesToCars_[place] = SecondState[place];
        ResultingCarsToPlaces_[SecondState[place]] = place;
    }
    ResultingZeroPlace_ = ResultingCarsToPlaces_[0];
}


void CParkingLot::rotate() {
    int zero_place = CarsToPlaces_[0];
    int car_to_move, place_from_move;
    while (zero_place != ResultingZeroPlace_) {
        car_to_move = ResultingPlacesToCars_[zero_place];
        place_from_move = CarsToPlaces_[car_to_move];
        Rearranging_.push_back(std::pair<int, int>(place_from_move, zero_place));
        CarsToPlaces_[0] = place_from_move;
        CarsToPlaces_[car_to_move] = zero_place;
        PlacesToCars_[place_from_move] = 0;
        PlacesToCars_[zero_place] = car_to_move;
        zero_place = place_from_move;
    }
}


void CParkingLot::rearrange() {
    Rearranging_.clear();
    std::map<int,int>::iterator it;
    rotate();
    int car_to_move, zero_place, place_from_move;
    for (it = CarsToPlaces_.begin(); it != CarsToPlaces_.end(); ++it) { // searching for new cycle to rotate
        car_to_move = it->first;
        if (CarsToPlaces_[car_to_move] == ResultingCarsToPlaces_[car_to_move]) {
            // the car is already in the right place
            continue;
        } else {
            // the car is in a wrong place
            // we need to make it possible to put it in the right place
            // so we swap car_to_move with empty place
            zero_place = CarsToPlaces_[0];
            place_from_move = CarsToPlaces_[car_to_move];
            CarsToPlaces_[0] = place_from_move;
            CarsToPlaces_[car_to_move] = zero_place;
            PlacesToCars_[zero_place] = car_to_move;
            PlacesToCars_[place_from_move] = 0;
            Rearranging_.push_back(std::pair<int, int>(place_from_move, zero_place));
            rotate();
        }
    }
}


void CParkingLot::how_to_rearrange() {
    rearrange();
    if (Rearranging_.size() == 0) {
        std::cout << "There is nothing to move" << std::endl;
        return;
    }
    for (std::pair<int, int> iteration: Rearranging_) {
        std::cout << "move from " << iteration.first << " to " << iteration.second << std::endl;
    }
}
