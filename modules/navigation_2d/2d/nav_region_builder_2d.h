/**************************************************************************/
/*  nav_region_builder_2d.h                                               */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             REDOT ENGINE                               */
/*                        https://redotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2024-present Redot Engine contributors                   */
/*                                          (see REDOT_AUTHORS.md)        */
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

#include "../nav_utils_2d.h"

struct NavRegionIterationBuild2D;

class NavRegionBuilder2D {
	static void _build_step_process_navmesh_data(NavRegionIterationBuild2D &r_build);
	static void _build_step_find_edge_connection_pairs(NavRegionIterationBuild2D &r_build);
	static void _build_step_merge_edge_connection_pairs(NavRegionIterationBuild2D &r_build);
	static void _build_update_iteration(NavRegionIterationBuild2D &r_build);

public:
	static Nav2D::PointKey get_point_key(const Vector2 &p_pos, const Vector2 &p_cell_size);
	static Nav2D::EdgeKey get_edge_key(const Vector2 &p_vertex1, const Vector2 &p_vertex2, const Vector2 &p_cell_size);

	static void build_iteration(NavRegionIterationBuild2D &r_build);
};
