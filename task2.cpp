/// @file
/// @brief Task2: member function definitions/implementations

#include "task2.hpp"  // task2::Vec2, task2::BBox, task2::Circle, task2::Triangle

#include "iue-num/numerics.hpp"  // iue::num::isclose
#include "task2.misc.hpp"  // task2::operator<<, task2::isnan, task2::isclose

/// @todo Include standard library headers as needed
#include <algorithm>
#include <cmath>

namespace task2 {

/// ====================================  Bounding Box
/// =================================================
/// @todo Implement the missing member functions for bounding box as declared
/// and specified in task2.hpp

/// @todo implement member function 'BBox::scale'
BBox BBox::scale(const Vec2d& org, double s) const {
    BBox box;
    box.min = {org[0] + (min[0] - org[0]) * s, org[1] + (min[1] - org[1]) * s};
    box.max = {org[0] + (max[0] - org[0]) * s, org[1] + (max[1] - org[1]) * s};
    return box;
}

/// @todo implement member function 'BBox::translate'
BBox BBox::translate(const Vec2d& offset) const {
    BBox box;
    box.min = {min[0] + offset[0], min[1] + offset[1]};
    box.max = {max[0] + offset[0], max[1] + offset[1]};
    return box;
}

/// @todo implement member function 'BBox::check_invariants'
bool BBox::check_invariants() const {
    // is not NAN
    if (std::isnan(min[0]) || std::isnan(min[1]) || std::isnan(max[0]) ||
        std::isnan(max[1])) {
        return false;
    }

    // min < max
    if (min[0] > max[0] || min[1] > max[1]) {
        return false;
    }

    // min is not close to max
    if (iue::num::isclose(min[0], max[0]) ||
        iue::num::isclose(min[1], max[1])) {
        return false;
    }
    return true;
}

/// ====================================  Circle
/// ================================================
/// @todo Implement the missing member functions for Circle as declared and
/// specified in task2.hpp

/// @todo implement member function 'Circle::bbox'
BBox Circle::bbox() const {
    BBox box;
    box.min = {c[0] - r, c[1] - r};
    box.max = {c[0] + r, c[1] + r};
    return box;
}

/// @todo implement member function 'Circle::scale'
Circle Circle::scale(const Vec2d& org, double s) const {
    Circle circ;
    circ.c = {(c[0] - org[0]) * s + org[0], (c[1] - org[1]) * s + org[1]};
    circ.r = r * s;
    return circ;
}

/// @todo implement member function 'Circle::rotate'
Circle Circle::rotate(const Vec2d& org, double angle) const {
    Circle circ;

    circ.c = {(c[0] - org[0]) * std::cos(angle) -
                  (c[1] - org[1]) * std::sin(angle) + org[0],
              (c[0] - org[0]) * std::sin(angle) +
                  (c[1] - org[1]) * std::cos(angle) + org[1]};
    circ.r = r;
    return circ;
}

/// @todo implement member function 'Circle::translate'
Circle Circle::translate(const Vec2d& offset) const {
    Circle circ;

    circ.c = {c[0] + offset[0], c[1] + offset[1]};
    circ.r = r;
    return circ;
}

/// @todo implement member function 'Circle::check_invariants'
bool Circle::check_invariants() const {
    // is not NAN
    if (std::isnan(c[0]) || std::isnan(c[1]) || std::isnan(r)) {
        return false;
    }

    // min < max
    if (r < 0) {
        return false;
    }

    return true;
}

/// ====================================  Triangle
/// ================================================
/// @todo Implement the missing member functions for Triangle as declared and
/// specified in task2.hpp

/// @todo implement member function 'Triangle::bbox'
BBox Triangle::bbox() const {
    BBox box;
    box.min = {std::min({abc[0][0], abc[1][0], abc[2][0]}),
               std::min({abc[0][1], abc[1][1], abc[2][1]})};
    box.max = {std::max({abc[0][0], abc[1][0], abc[2][0]}),
               std::max({abc[0][1], abc[1][1], abc[2][1]})};
    return box;
}

/// @todo implement member function 'Triangle::scale'
Triangle Triangle::scale(const Vec2d& org, double s) const {
    Triangle t;

    Vec2d d1 = {abc[0][0] - org[0], abc[0][1] - org[1]};
    Vec2d d2 = {abc[1][0] - org[0], abc[1][1] - org[1]};
    Vec2d d3 = {abc[2][0] - org[0], abc[2][1] - org[1]};

    t.abc[0] = {org[0] + s * d1[0], org[1] + s * d1[1]};
    t.abc[1] = {org[0] + s * d2[0], org[1] + s * d2[1]};
    t.abc[2] = {org[0] + s * d3[0], org[1] + s * d3[1]};
    return t;
}

/// @todo implement member function 'Triangle::rotate'
Triangle Triangle::rotate(const Vec2d& org, double angle) const {
    Triangle t;

    Vec2d d1 = {abc[0][0] - org[0], abc[0][1] - org[1]};
    Vec2d d2 = {abc[1][0] - org[0], abc[1][1] - org[1]};
    Vec2d d3 = {abc[2][0] - org[0], abc[2][1] - org[1]};

    t.abc[0] = {d1[0] * std::cos(angle) - d1[1] * std::sin(angle) + org[0],
                d1[0] * std::sin(angle) + d1[1] * std::cos(angle) + org[1]};

    t.abc[1] = {d2[0] * std::cos(angle) - d2[1] * std::sin(angle) + org[0],
                d2[0] * std::sin(angle) + d2[1] * std::cos(angle) + org[1]};

    t.abc[2] = {d3[0] * std::cos(angle) - d3[1] * std::sin(angle) + org[0],
                d3[0] * std::sin(angle) + d3[1] * std::cos(angle) + org[1]};

    return t;
}

/// @todo implement member function 'Triangle::translate'
Triangle Triangle::translate(const Vec2d& offset) const {
    Triangle t;
    for (int i = 0; i < 3; ++i) {
        t.abc[i][0] = abc[i][0] + offset[0];
        t.abc[i][1] = abc[i][1] + offset[1];
    }
    return t;
}

/// @todo implement member function 'Triangle::check_invariants'
bool Triangle::check_invariants() const {
    // is not NAN
    for (int i = 0; i < 3; ++i) {
        if (std::isnan(abc[i][0]) || std::isnan(abc[i][1])) {
            return false;
        }
        for (int k = 0; k < 2; ++k) {
            for (int j = 0; j < 3; ++j) {
                if (j == i) continue;  // skip comparing point with itselfs
                if (iue::num::isclose(abc[i][0], abc[j][0]) &&
                    iue::num::isclose(abc[i][1], abc[j][1]))
                    return false;
            }
        }
    }
    return true;
}

}  // namespace task2
