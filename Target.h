#ifndef _TARGET_H_GUARD_
#define _TARGET_H_GUARD_

#include <functional>
#include <vector>

enum Color
{
	white,
	grey,
	black,
};

// Vertex
struct Target {
	// c-tor
	Target()
		:color_( white )
		,unprDegree_( 0 ) {}
	Target(size_t m_id, bool isdirect = true )
		:id( m_id )
		,color_( white )
		,unprDegree_( 0 ) {}
	// vertex identificator
	size_t id;
	// build procedure
	std::function<void()> task;
	// Vertex color ( to bfs traverse )
	Color color_;
	//
	size_t unprDegree_;
};


// bool operator<(const Target& fk1, const Target& fk2) { return fk1.id < fk2.id; }

#endif
	// _TARGET_H_GUARD_
