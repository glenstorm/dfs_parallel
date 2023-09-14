#ifndef _BUILDER_H_GUARD_
#define _BUILDER_H_GUARD_

#include <algorithm>
#include <iostream>
#include <queue>
#include "BuildGraph.h"
#include "CycleException.h"

class Builder {
public:
	explicit Builder( size_t num_threads )
		:numThreads_( num_threads ) {}

	void execute( const BuildGraph& build_graph, size_t target_id )
	{
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		// distribute new  parallel order between theads
		// seeds
		std::queue<size_t> tasks_2_process;
		for( int i = 0; i < build_graph.getVertexNum(); ++i )
		{
			if(build_graph.getVertexDegree(i) == 0 )
				tasks_2_process.push( i );

		}

		while( !tasks_2_process.empty() )
		{
			// reduce in degree of dependent tasks
			for( int i = 0; i < numThreads_; ++i )
			{
				if( tasks_2_process.empty() )
					break;
				size_t leaf = tasks_2_process.front();
				build_graph.setVColor( leaf, grey );

				// ========================================================
				// build_graph.runTask( leaf );
				// ========================================================

				std::cout << i << " thread --> " << leaf << " task competed" << std::endl;

				auto outVertexes = build_graph.getInEdges( leaf );
				for_each( outVertexes.begin(), outVertexes.end(), [&build_graph, &tasks_2_process]( int j )
				{
					if( build_graph.getVColor( j ) == grey )
						throw new CycleException( "Cycle detected" );

					build_graph.reduceVertexDegree( j ); // check is ready 2 process
					if( build_graph.getVertexDegree( j ) == 0 )
						tasks_2_process.push( j );
				});

				build_graph.setVColor( leaf, black );
				tasks_2_process.pop();

			}
			std::cout << "======================================================================" << std::endl;
		}
	}

private:
	const size_t numThreads_;
};

#endif
	// _BUILDER_H_GUARD_
