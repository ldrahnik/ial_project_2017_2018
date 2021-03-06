/**
 * Name:							Tučková Martina, Tussupová Kymbat, Lázňovský David, Drahník Lukáš
 * Project: 					IAL: náhradní projekt: 4. Nejkratší cesta v grafu
 * Date:							21.10.2017
 * Email:						  <xtucko00@stud.fit.vutbr.cz>, <xtussu00@stud.fit.vutbr.cz>, <xlazno00@stud.fit.vutbr.cz>, <xdrahn00@stud.fit.vutbr.cz>
 * File:              Soubor zabývající se návratovými hodnotami programu.
 */

#ifndef _error_H_
#define _error_H_

enum ecodes {
  EOK = 0,               // ok
  EOPT = 1,              // invalid option (option argument is missing,
                         // unknown option, unknown option character)
  EVERTICE_START = 2,    // vertice_start is not valid
  EVERTICE_END = 3,      // vertice_end is not valid
  ERATED_GRAPH = 4,      // spec. rated graph: min length, error like edge is not digit number, negative cycle
  EUNRATED_GRAPH = 5,    // spec. unrated graph: min length
  EGRAPH = 6,            // graph common
  EALLOC = 7,            // alloc problem
  EFILE = 8,             // problem with the opening file (function fseek, )
  ENEGATIVE_CYCLE = 9,   // specific bellman ford algoritm error (detection of negative cycle which algoritm can not handle)
};

#endif
