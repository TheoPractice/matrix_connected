/**
 * A program that analyzes a matrix representing an undirected 
 * graph and determines whether it is connected
 * uses adjacency matrix representation of a graph
 * @author Theo Greer
 * @version 11 September 2017
 */
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
#include "matrix.h"

using namespace std;

bool is_connected( const Matrix< bool > & graph ) const
{
  vector< bool > reached( graph.numrows(), false );

  queue< uint8_t > to_be_explored;
  to_be_explored.push( 0 );
  reached.at( 0 ) = true;
  uint16_t row = 0;

  cout << "tbe before while loop: " << to_be_explored.front() << endl;
  while( !to_be_explored.empty() )
  {
    row = to_be_explored.front();

    cout << "row: " << to_string(row) << endl;
    to_be_explored.pop();

    cout << "tbe after pop: " << to_be_explored.front() << endl;

    
    for( uint i = 0; i < graph.numcols(); i++ )
    {
      cout << "cols before conditional: " << i << endl;

      if( !reached.at(i) && graph.at( row, i ))
      {
	cout << "tbe before push: " << to_string(to_be_explored.front()) << endl;
	cout << "cols: " << i << endl;
	to_be_explored.push( i );
	cout << "tbe after push: " << to_string(to_be_explored.front()) << endl;
	reached.at( i ) = true;
      }
    }
  }
  return find( reached.begin(), reached.end(), false ) == reached.end();
}

int main()
{
  //Matrix< bool > graph( 4, 4 );

  Matrix< bool > graph( 3, 3 );

  graph.at( 0, 0 ) = false;
  graph.at( 0, 1 ) = true;
  graph.at( 0, 2 ) = false;

  graph.at( 1, 0 ) = true;
  graph.at( 1, 1 ) = false;
  graph.at( 1, 2 ) = true;

  graph.at( 2, 0 ) = false;
  graph.at( 2, 1 ) = true;
  graph.at( 2, 2 ) = false;
  
  
  /*graph.at( 0, 0 ) = false;
  graph.at( 0, 1 ) = false;
  graph.at( 0, 2 ) = true;
  graph.at( 0, 3 ) = true;
  
  graph.at( 1, 0 ) = false;
  graph.at( 1, 1 ) = false;
  graph.at( 1, 2 ) = true;
  graph.at( 1, 3 ) = false;

  graph.at( 2, 0 ) = true;
  graph.at( 2, 1 ) = true;
  graph.at( 2, 2 ) = false;
  graph.at( 2, 3 ) = false;

  graph.at( 3, 0 ) = true;
  graph.at( 3, 1 ) = false;
  graph.at( 3, 2 ) = false;
  graph.at( 3, 3 ) = false;  
  */
  cout << boolalpha << is_connected( graph ) << endl;

  return 0;
}
      
