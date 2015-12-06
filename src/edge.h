// The MIT License (MIT)
//
// Copyright (c) 2015 Lukáš Bednařík
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#ifndef EDGE_H
#define EDGE_H

#include "point.h"
#include <utility>


namespace Voronoi
{
	/// Edge class stores an edge in Voronoi diagram
	class Edge
	{
	public:
		Edge(const Point & left, const Point & right);
		Point begin() const;
		Point end() const;
		Point left() const;
		Point right() const;
		void setBegin(const Point & begin);
		void setEnd(const Point & end);

		Edge * neighbour;  ///< some edges consist of two parts, so we add the pointer to another part to connect them at the end of an algorithm

	private:
		Point _begin;  ///< Start of the edge
		Point _end;    ///< End of the edge
		Point _left;   ///< Each edge lies between two points, this is the left
		Point _right;  ///< Each edge lies between two points, this is the right
	};
}


// Implementation

inline Voronoi::Edge::Edge(const Point & left, const Point & right) :
	neighbour(nullptr),
	_left(left),
	_right(right)
{
}


inline Voronoi::Point Voronoi::Edge::begin() const
{
	return _begin;
}


inline Voronoi::Point Voronoi::Edge::end() const
{
	return _end;
}


inline Voronoi::Point Voronoi::Edge::left() const
{
	return _left;
}


inline Voronoi::Point Voronoi::Edge::right() const
{
	return _right;
}


inline void Voronoi::Edge::setBegin(const Point & begin)
{
	_begin = begin;
}


inline void Voronoi::Edge::setEnd(const Point & end)
{
	_end = end;
}


#endif  // EDGE_H
