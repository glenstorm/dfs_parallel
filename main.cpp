#include <iostream>
#include <sstream>
#include <iterator>
#include "BuildGraph.h"
#include "Builder.h"

using namespace std;

int main(int argc, char const *argv[]) {
	// input and construct graph
	int vertexex_nums = 0;
	cin >> vertexex_nums;
	TargetStore targetStore( vertexex_nums );
	BuildGraph g( vertexex_nums, &targetStore );

	string in_line;
	getline( std::cin, in_line ); // empty line after vertex_num
	while( getline( std::cin, in_line ) )
	{
		stringstream lineStream( in_line );
 		vector<size_t> vert_an_edges( istream_iterator<size_t>( lineStream ), {} );
		g.addEdges( vert_an_edges );
	}

	// g.printGraph();
	Builder b( 2 );

	try
	{
		b.execute( g, 0 );
	}
	catch( CycleException e )
	{
		cout << "Exception: " << e.what() << endl;
	}
	catch( std::runtime_error e )
	{
		cout << "Exception: " << e.what() << endl;
	}
	catch( ... )
	{
		cout << "Unknown exception" << endl;
	}

	return 0;
}
