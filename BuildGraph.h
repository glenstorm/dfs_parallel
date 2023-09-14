#ifndef _BUILD_GRAPH_H_GUARD_
#define _BUILD_GRAPH_H_GUARD_

#include <vector>
#include <iostream>
#include "Target.h"
#include "TargetStore.h"

class BuildGraph
{
public:
	explicit BuildGraph( size_t g_size, TargetStore *targetStore )
		:vertexes_num( g_size )
		,targetStore_( targetStore )
	{
		adjGraph_.resize( vertexes_num );
		revAdjGraph_.resize( vertexes_num );
	}

	// first number - tail, the next - head vertexes
	// must be at least 1
	void addEdges( const std::vector<size_t>& edges )
	{
		size_t head = edges[0];
		targetStore_->add(head);
		for( int i = 1; i < edges.size(); ++i )
		{
			adjGraph_[head].push_back( edges[i] );
			++(*targetStore_)[head].unprDegree_;

			revAdjGraph_[edges[i]].push_back( head );
		}
	}

	// Print the graph
	void printGraph() {
		for( int d = 0; d < vertexes_num; ++d ) {
			std::cout << "\n Vertex " << d << ":";
			for ( auto x : adjGraph_[d] )
				std::cout << "-> " << x;
			std::cout << " degree = " << (*targetStore_)[d].unprDegree_ <<  std::endl;
		}

		std::cout << "=================================================" << std::endl;

		for( int d = 0; d < vertexes_num; ++d ) {
			std::cout << "\n Vertex " << d << ":";
			for ( auto x : revAdjGraph_[d] )
				std::cout << "-> " << x;
			std::cout << " degree = " << (*targetStore_)[d].unprDegree_ <<  std::endl;
		}
	}

	const std::vector<int>& getOutEdges(size_t v_idx) const
	{
		return adjGraph_[v_idx];
	}

	const std::vector<int>& getInEdges(size_t v_idx) const
	{
		return revAdjGraph_[v_idx];
	}

	Color getVColor( size_t id ) const
	{
		return (*targetStore_)[id].color_;
	}

	void setVColor( size_t id, Color color ) const
	{
		(*targetStore_)[id].color_ = color;
	}

	size_t getVertexNum() const
	{
		return vertexes_num;
	}

	size_t getVertexDegree( size_t id ) const
	{
		return (*targetStore_)[id].unprDegree_;
	}

	void reduceVertexDegree( size_t id ) const
	{
		--(*targetStore_)[id].unprDegree_;
	}

	void runTask( size_t id ) const
	{
		(*targetStore_)[id].task();
	}

private:
	const size_t vertexes_num;
	// Create a graph ( only on )
	std::vector<std::vector<int>> adjGraph_;
	std::vector<std::vector<int>> revAdjGraph_;

	// vertex properties
	TargetStore *targetStore_;
};

#endif
	// _BUILD_GRAPH_H_GUARD_
