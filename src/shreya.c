/**
 * Name:							Tučková Martina, Tussupová Kymbat, Lázňovský David, Drahník Lukáš
 * Project: 					IAL: náhradní projekt: 4. Nejkratší cesta v grafu
 * Date:							21.10.2017
 * Email:						  <xtucko00@stud.fit.vutbr.cz>, <xtussu00@stud.fit.vutbr.cz>, <xlazno00@stud.fit.vutbr.cz>, <xdrahn00@stud.fit.vutbr.cz>
 */

#include "shreya.h"

const char *HELP_MSG = {
  "The shorted path in graph between two vertices.\n\n"
  "Example of usage:\n\n"
  "./shreya [-h ] [-r ] [-i <graph_path as string>] <vertice_start> <vertice_end>\n\n"
  "Options:\n"
  "-r -- rated graph\n"
  "-o -- oriented graph\n"
  "-h -- show help message\n"
  "-i -- string contains graph_path (for example rated graph vertice0 -> 4 -> vertice1)\n"
  "<vertice> -- name of valid vertice (first is start, second is end)\n"
};

/**
 * Entry point of application.
 *
 * @param int argc
 * @param char *argv[]
 *
 * @return int
 */
int main(int argc, char *argv[]) {
  int ecode = EOK;

  // get params
  TParams params = getParams(argc, argv);
  if(params.ecode != EOK) {
    return params.ecode;
  }

  fprintf(stderr, "DEBUG: getParams() successfuly ended.\n\n");

  // help message
  if(params.show_help_message) {
    printf("%s", HELP_MSG);
    cleanParams(params);
    return ecode;
  }

  // get graph
  TGraph graph = getGraph(params);
  if(params.ecode != EOK) {
    cleanParams(params);
    return params.ecode;
  }

  fprintf(stderr, "DEBUG: vertices count: %i\n\n", graph.vertices_count);
  fprintf(stderr, "DEBUG: edges count: %i\n\n", graph.edges_count);

  fprintf(stderr, "\nDEBUG: getGraph() successfuly ended.\n\n");

  int start_position = getPositionOfVertice(graph, params.vertice_start);
  int end_position = getPositionOfVertice(graph, params.vertice_end);

  // contains negative edge (bellmann-ford algorithm)
  if(graph.contains_negative_edge) {

    TResults results = floydWarshall(graph);

    if(results.ecode != EOK) {
      fprintf(stderr, "Alloc problem.\n");
      cleanResults(results);
      return results.ecode;
    }

    print_distances(graph, results);

    fprintf(stdout, "\n");

    // TODO: more ways
    printPath(graph, results, start_position, end_position);

    fprintf(stdout, "\n");

    cleanResults(results);
  } else {
    // TODO:
  }

  cleanParams(params);

  return ecode;
}
