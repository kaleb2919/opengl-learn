#pragma once
#include <glm/vec3.hpp>
#include "MarchingCubesData.h"

class Terrain
{
public:
   typedef struct {
      glm::vec3 p[3];
   } triangle;

   typedef struct {
      glm::vec3 p[8];
      double val[8];
   } grid_cell;

   int getValue(grid_cell grid, double isolevel, triangle *triangles);
   glm::vec3 interpolation(double isolevel, glm::vec3 p1,glm::vec3 p2, double val_p1, double val_p2);
};
