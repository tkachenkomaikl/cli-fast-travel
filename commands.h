#pragma once
// include stuff
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define error codes
#define ERR_BAD_ARGUMENT 2
#define ERR_MISPLACED_ARGUMENT 101
#define ERR_MEMORY 12
#define ERR_FILE_MISSING 66
#define ERR_NULL_FIELD 102

// enum
typedef enum { DEFAULT_PATH, NVIM, CODING } Mode;
typedef enum { ERR_LANG, C, PYTHON, RUST } Language;
typedef enum { DEFAULT, CLI, BOOTDEV } Project;

// struct
typedef struct {
  Mode mode;
  Language language;
  Project project;
} Menu;

// initialize.
int* init(void);

// Help functions.
void help(const char* name);
void help_default(void);

// error
void error(int errcode);
