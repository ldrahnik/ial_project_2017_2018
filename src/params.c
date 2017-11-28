/**
 * Name:							Tučková Martina, Tussupová Kymbat, Lázňovský David, Drahník Lukáš
 * Project: 					IAL: náhradní projekt: 4. Nejkratší cesta v grafu
 * Date:							21.10.2017
 * Email:						  <xtucko00@stud.fit.vutbr.cz>, <xtussu00@stud.fit.vutbr.cz>, <xlazno00@stud.fit.vutbr.cz>, <xdrahn00@stud.fit.vutbr.cz>
 */

#include "params.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

/**
 * Get TParams structure from terminal options, option arguments and vertices.
 *
 * @return TParams
 */
TParams getParams(int argc, char *argv[]) {

  TParams params = {
  	.show_help_message = 0,
    .ecode = EOK,
    .is_graph_rated = 0,
    .contains_negative_edge = 0,
    .is_graph_oriented = 0,
    .input = 0,
  };

  // don't want getopt() writing to stderr
  opterr = 0;

  // file
  FILE *file;
  long length;

  // getopt
  int c;
  while ((c = getopt(argc, argv, "orhi:")) != -1) {
    switch (c) {
      case 'h':
        params.show_help_message = 1;
        break;
      case 'r':
        if(params.is_graph_rated) {
          fprintf(stderr, "Option -r has been already set.\n");
          params.ecode = EOPT;
          return params;
        }
        params.is_graph_rated = 1;
        break;
      case 'o':
        if(params.is_graph_oriented) {
          fprintf(stderr, "Option -o has been already set.\n");
          params.ecode = EOPT;
          return params;
        }
        params.is_graph_oriented = 1;
        break;
      case 'i':
        if(params.input) {
          fprintf(stderr, "Option -i has been already set.\n");
          params.ecode = EOPT;
          return params;
        }

        file = fopen(optarg,"rb");
        if(file != NULL) {
          if(fseek(file, 0, SEEK_END) != 0) {
            params.ecode = EFILE;
            return params;
          }
          length = ftell(file);
          if(length == -1) {
            params.ecode = EFILE;
            return params;
          }
          if(fseek(file, 0, SEEK_SET) != 0) {
            params.ecode = EFILE;
            return params;
          }
          params.input = malloc(length);
          if(params.input  == NULL) {
            params.ecode = EALLOC;
            return params;
          }
          if(params.input ) {
            fread(params.input, 1, length, file);
          }
          fclose(file);
        } else {
          params.input  = malloc(strlen(optarg));
          if(params.input  == NULL) {
            params.ecode = EALLOC;
            return params;
          }
          strcpy(params.input, optarg);
        }
        break;
      case '?':
        if(optopt == 'i') {
          fprintf(stderr, "Option -%c requires an argument.\n", optopt);
        } else if(isprint (optopt)) {
          fprintf(stderr, "Unknown option `-%c'.\n", optopt);
        } else {
          fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        }
        params.ecode = EOPT;
        break;
      default:
        fprintf(stderr, "Options error.\n");
        params.ecode = EOPT;
        break;
    }
  }

  if(argv[optind] == NULL) {
    fprintf(stderr, "vertice_start is missing.\n");
    params.ecode = EOPT;
    return params;
  }
  if(argv[optind + 1] == NULL) {
    fprintf(stderr, "vertice_end is missing.\n");
    params.ecode = EOPT;
    return params;
  }

  params.vertice_start = argv[optind];
  params.vertice_end = argv[optind + 1];

  return params;
}

/**
 * Clean the mess.
 */
void cleanParams(TParams params) {
  free(params.input);
  free(params.graph_route);
}
