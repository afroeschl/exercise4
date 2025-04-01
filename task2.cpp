/// @file
/// @brief Task2: member function definitions/implementations

#include "task2.hpp"      // task2::Vec2, task2::BBox, task2::Circle, task2::Triangle
#include "task2.misc.hpp" // task2::operator<<, task2::isnan, task2::isclose

#include "iue-num/numerics.hpp" // iue::num::isclose

/// @todo Include standard library headers as needed

namespace task2 {

/// ====================================  Bounding Box
/// =================================================
/// @todo Implement the missing member functions for bounding box as declared and specified in
/// task2.hpp

/// @todo implement member function 'BBox::scale'
BBox BBox::scale(const Vec2d& org, double s) const { return {}; }

/// @todo implement member function 'BBox::translate'
BBox BBox::translate(const Vec2d& offset) const { return {}; }

/// @todo implement member function 'BBox::check_invariants'
bool BBox::check_invariants() const { return {}; }

/// ====================================  Circle  ================================================
/// @todo Implement the missing member functions for Circle as declared and specified in task2.hpp

/// @todo implement member function 'Circle::bbox'
BBox Circle::bbox() const { return {}; }

/// @todo implement member function 'Circle::scale'
Circle Circle::scale(const Vec2d& org, double s) const { return {}; }

/// @todo implement member function 'Circle::rotate'
Circle Circle::rotate(const Vec2d& org, double angle) const { return {}; }

/// @todo implement member function 'Circle::translate'
Circle Circle::translate(const Vec2d& offset) const { return {}; }

/// @todo implement member function 'Circle::check_invariants'
bool Circle::check_invariants() const { return {}; }

/// ====================================  Triangle  ================================================
/// @todo Implement the missing member functions for Triangle as declared and specified in task2.hpp

/// @todo implement member function 'Triangle::bbox'
BBox Triangle::bbox() const { return {}; }

/// @todo implement member function 'Triangle::scale'
Triangle Triangle::scale(const Vec2d& org, double s) const { return {}; }

/// @todo implement member function 'Triangle::rotate'
Triangle Triangle::rotate(const Vec2d& org, double angle) const { return {}; }

/// @todo implement member function 'Triangle::translate'
Triangle Triangle::translate(const Vec2d& offset) const { return {}; }

/// @todo implement member function 'Triangle::check_invariants'
bool Triangle::check_invariants() const { return {}; }

} // namespace task2
