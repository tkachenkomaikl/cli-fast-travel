#include "commands.h"

void error(int errorcode) {
  switch (errorcode) {
    case ERR_BAD_ARGUMENT:
      fprintf(stderr, "ERROR: Unknown argument.\n");
      break;
    case ERR_MEMORY:
      fprintf(stderr, "ERROR: Out of memory.\n");
      break;
    case ERR_MISPLACED_ARGUMENT:
      fprintf(stderr, "ERROR: Argument doesn't belong there.\n");
      break;
    case ERR_NULL_FIELD:
      fprintf(stderr,
              "ERROR: One of the required fields (maybe mode or language) "
              "ended up as NULL or an unallowed value.\n");
      break;
    default:
      fprintf(stderr, "ERROR: Something went wrong...\n");
      break;
  }
  exit(errorcode);
}

void help_default(void) {
  printf(
      "Use -h or --help to get here!\nYou can also use [argument] -h to get "
      "help on that specific argument!\n");
}
