//Rearranging cars
//
//  Complexity: O(n*log(n))
//  Solution:
//      Data is stored in 4 dictionaries: CarsToPlaces, PlacesToCars - current arrangement
//                                      and ResultingCarsToPlaces, ResultingPlacesToCars - resulting arrangement
//      So we can access car's places and cars for O(1)
//      Idea:
//          We can divide an arrangement into cycles.
//          for example: given arrays [1, 3, 4, 0, 2, 5, 6] and [3, 1, 0, 4, 5, 6, 2]
//          In this case we have 3 cycles: (1, 3); (4, 0); (2, 5, 6)
//          Each of these cycles can't be rearranged less then by n operations, where n is the length of the cycle
//          Also, to rearrange cycles (1, 3) and (2, 5, 6)
//          we need to implement the empty place there to make (1, 3, 0) and (2, 5, 6)
//          That means that we can rearrange a parking lot <= NumberOfPlaces + NumberOfNonSingleCycles*2
//          NumberOfNonSingleCycles <= NumberOfPlaces / 2, so number of operation: O(NumberOfSpaces)
//      Algorithm:
//          function rearrange()
//          The algorithm contains 2 parts:
//          1) method rotate(): rearranges cycles
//          2) searching for cycles


#include "CParkingLot.h"
#include "tests.h"


int main() {
    //CParkingLot ParkingLot;
    //ParkingLot.how_to_rearrange();
    AllTests();
    return 0;
}
