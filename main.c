#include "commands.h"

int main(int argc, char* argv[]) {
  Menu menu = {0};
  for (int i = 1; i < argc; i++) {
    char* arg = argv[i];
    switch (i) {
      case 1:
        if (arg[0] == '-') {
          error(ERR_MISPLACED_ARGUMENT);
        }
        if (strcmp(arg, "nvim") == 0) {
          menu.mode = NVIM;
        } else if (strcmp(arg, "c") == 0 || strcmp(arg, "C") == 0) {
          menu.mode = CODING;
          menu.language = C;
        } else if (strcmp(arg, "py") == 0 || strcmp(arg, "Py") == 0 ||
                   strcmp(arg, "python") == 0 || strcmp(arg, "Python") == 0) {
          menu.mode = CODING;
          menu.language = PYTHON;
        } else if (strcmp(arg, "rust") == 0 || strcmp(arg, "Rust") == 0) {
          menu.mode = CODING;
          menu.language = RUST;
        }
        break;
      case 2:
        if (strcmp(arg, "cli") == 0) {
          menu.project = CLI;
        } else if (strcmp(arg, "bootdev") == 0 || strcmp(arg, "boot") == 0) {
          menu.project = BOOTDEV;
        }
        break;
      default:
        error(ERR_MISPLACED_ARGUMENT);
    }
  }
  char* home = getenv("HOME");
  char* path;
  path = "";
  switch (menu.mode) {
    case DEFAULT_PATH:
      break;
    case NVIM:
      path = "/.config/nvim/";
      break;
    case CODING:
      if (menu.project == CLI) {
        switch (menu.language) {
          case C:
            path = "/Documents/Coding/C/cli-pathing/";
            break;
          default:
            path = "/Documents/Coding/C/cli-pathing/";
            break;
        }
      } else if (menu.project == BOOTDEV) {
        switch (menu.language) {
          case C:
            path = "/Documents/Coding/C/bootdev/";
            break;
          case PYTHON:
            path = "/Documents/Coding/Py/bootdev/";
            break;
          default:
            path = "/Documents/Coding/";
            break;
        }
      } else {
        switch (menu.language) {
          case C:
            path = "/Documents/Coding/C/";
            break;
          case PYTHON:
            path = "/Documents/Coding/Py/";
            break;
          case RUST:
            path = "/Documents/Coding/Rust/";
            break;
          default:
            path = "/Documents/Coding/";
            break;
        }
      }
      break;
    default:
      error(ERR_BAD_ARGUMENT);
      return 1;
  }

  printf("%s%s\n", home, path);
  return 0;
}
