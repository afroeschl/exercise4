/// @file
/// @brief Task3: implementation

#include "task3.hpp" // task3::render_something

#include "task3.misc.hpp" // task3::render_wrapper

#include "task2.hpp" // task2::BBox, task2::Circle, task2::Triangle

#include "iue-rnd/random.hpp" // iue::rnd::UniformValue, iue::rnd::UniformCircle, iue::rnd::UniformTriangle

#include <filesystem> // std::filesystem::path

/// @todo Include additional standard library headers as needed


namespace task3 {

/// @todo Implement function 'render_something' as declared and specified in task3.hpp
/// Implementation Hints:
///   - You can plot whatever you want, but you need to plot at least 20 primitives!
///   - You can view .svg-files using your web browser (or installing a VSCode extension to preview SVGs)
///   - use the provided function 'task3::render_wrapper' from 'task3.misc.hpp' to plot
///     task2::BBox, task2::Circle, task2::Triangle to a SVG-file
///   - The idea is that you make use of the functionality (scale/shift/rotate) you implemented in task2
///   - Optional: you can make use of the random Generators in 'iue-rnd/random.hpp' to obtain random values, circles, and triangles
int render_something(std::filesystem::path filepath) {

  task2::Vec2d min = {0, 0};
  task2::Vec2d max = {10, 10};
  task2::BBox box = {min, max};
  std::vector<task2::BBox> bboxes;
  bboxes.push_back(box);

  task2::Vec2d center = {5, 5};
  double radius = 5;
  task2::Circle circle = {center, radius};
  std::vector<task2::Circle> circles;
  circles.push_back(circle);

  task2::Vec2d a = {0, 0};
  task2::Vec2d b = {10, 0};
  task2::Vec2d c = {10, 10};
  task2::Triangle triangle = {{a,b,c}};
  std::vector<task2::Triangle> triangles;
  triangles.push_back(triangle);

  auto [bbmin, bbmax] = task3::render_wrapper(filepath, bboxes, circles, triangles);

  return triangles.size() + bboxes.size() + circles.size();
};

} // namespace task3
