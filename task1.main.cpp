/// @file
/// @brief Task1: "single-file" excutable C++ program

#include <array>     // std::array
#include <cmath>     // std::sin, std::cos
#include <iostream>  // std::cout, std::endl
#include <numbers>   // std::numbers::pi

/// @todo Include standard library headers as needed
namespace task1 {

using Coord = std::array<double, 2>;

Coord rotate_counter_clockwise(Coord coord, double angle) {
    double r = std::sqrt(std::pow(coord[0], 2) + std::pow(coord[1], 2));
    Coord result;
    result[0] = coord[0] * std::cos(angle);
    result[1] = coord[1] * std::sin(angle + std::numbers::pi*0.5);

    return result;
}

/// @todo Implement a function 'rotate_counter_clockwise' according to the
/// description below:
/// - the function receives a two-dimensional coordinate in form of a
/// 'std::array<double, 2>'
/// - the function receives a rotation angle (in radians) in form of a 'double'
/// - the function rotates the coordinate counter clockwise around the origin
/// - the function returns the rotated coordinate as a std::array<double, 2>

}  // namespace task1

/// @todo Implement a main function conducting the following tasks in this
/// order:
/// - Create two coordinates (local variables):
///   - std::array<double, 2> coord1 = {112,211};
///   - std::array<double, 2> coord2 = {-42,23};
/// - Use your 'rotate_counter_clockwise' function to rotate both coordinate by
/// 180 degrees
/// - Print the resulting rotated coordinates to the console
/// - Hint: the expected coordinates after rotating 180 degrees are
///     - std::array<double, 2> coord1_rotated = {-112,-211};
///     - std::array<double, 2> coord2_rotated = {42,-23};
int main() {
    using namespace task1;

    std::array<double, 2> coord1 = {112, 211};
    std::array<double, 2> coord2 = {-42, 23};

    Coord coord = {1, 2};

    auto [xrot1, yrot1] = rotate_counter_clockwise(coord1, std::numbers::pi);
    std::cout << xrot1 << " " << yrot1 << std::endl;

    auto [xrot2, yrot2] = rotate_counter_clockwise(coord2, std::numbers::pi);
    std::cout << xrot2 << " " << yrot2 << std::endl;

    return 0;
}
