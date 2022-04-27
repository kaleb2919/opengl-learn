#include "Terrain.h"

glm::vec3 Terrain::interpolation(double isolevel, glm::vec3 p1, glm::vec3 p2, double val_p1, double val_p2)
{
    glm::vec3 p;

    if (abs(isolevel - val_p1) < 0.00001)
        return p1;
    if (abs(isolevel - val_p2) < 0.00001)
        return p2;
    if (abs(val_p1 - val_p2) < 0.00001)
        return p1;

    double mu = (isolevel - val_p1) / (val_p2 - val_p1);
    p.x = p1.x + mu * (p2.x - p1.x);
    p.y = p1.y + mu * (p2.y - p1.y);
    p.z = p1.z + mu * (p2.z - p1.z);

    return p;
}

int Terrain::getValue(grid_cell grid, double isolevel, triangle* triangles)
{
    glm::vec3 vertex_list[12];

    int cube_index = 0;
    if (grid.val[0] < isolevel) cube_index |= 1;
    if (grid.val[1] < isolevel) cube_index |= 2;
    if (grid.val[2] < isolevel) cube_index |= 4;
    if (grid.val[3] < isolevel) cube_index |= 8;
    if (grid.val[4] < isolevel) cube_index |= 16;
    if (grid.val[5] < isolevel) cube_index |= 32;
    if (grid.val[6] < isolevel) cube_index |= 64;

    if (edge_table[cube_index] == 0)
        return 0;

    if (edge_table[cube_index] & 1)
        vertex_list[0] = interpolation(isolevel, grid.p[0], grid.p[1], grid.val[0], grid.val[1]);
    if (edge_table[cube_index] & 2)
        vertex_list[1] = interpolation(isolevel, grid.p[1], grid.p[2], grid.val[1], grid.val[2]);
    if (edge_table[cube_index] & 4)
        vertex_list[2] = interpolation(isolevel, grid.p[2], grid.p[3], grid.val[2], grid.val[3]);
    if (edge_table[cube_index] & 8)
        vertex_list[3] = interpolation(isolevel, grid.p[3], grid.p[0], grid.val[3], grid.val[0]);
    if (edge_table[cube_index] & 16)
        vertex_list[4] = interpolation(isolevel, grid.p[4], grid.p[5], grid.val[4], grid.val[5]);
    if (edge_table[cube_index] & 32)
        vertex_list[5] = interpolation(isolevel, grid.p[5], grid.p[6], grid.val[5], grid.val[6]);
    if (edge_table[cube_index] & 64)
        vertex_list[6] = interpolation(isolevel, grid.p[6], grid.p[7], grid.val[6], grid.val[7]);
    if (edge_table[cube_index] & 128)
        vertex_list[7] = interpolation(isolevel, grid.p[7], grid.p[4], grid.val[7], grid.val[4]);
    if (edge_table[cube_index] & 256)
        vertex_list[8] = interpolation(isolevel, grid.p[0], grid.p[4], grid.val[0], grid.val[4]);
    if (edge_table[cube_index] & 512)
        vertex_list[9] = interpolation(isolevel, grid.p[1], grid.p[5], grid.val[1], grid.val[5]);
    if (edge_table[cube_index] & 1024)
        vertex_list[10] = interpolation(isolevel, grid.p[2], grid.p[6], grid.val[2], grid.val[6]);
    if (edge_table[cube_index] & 2048)
        vertex_list[11] = interpolation(isolevel, grid.p[3], grid.p[7], grid.val[3], grid.val[7]);

    int count_triangle = 0;
    for (int i = 0; triangulation_table[cube_index][i] != -1; i += 3)
    {
        triangles[count_triangle].p[0] = vertex_list[triangulation_table[cube_index][i]];
        triangles[count_triangle].p[1] = vertex_list[triangulation_table[cube_index][i + 1]];
        triangles[count_triangle].p[2] = vertex_list[triangulation_table[cube_index][i + 2]];
        count_triangle++;
    }

    return count_triangle;
}
