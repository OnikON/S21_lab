#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "logger.h"

FILE* log_init(char* filename) {
  FILE* new_file = fopen(filename, "wb+");
  return new_file;
}
int logcat(FILE* log_file, char* message, enum log_level level) {
  char l_level[8] = "\0";
  switch (level) {
    case debug:
      strcat(l_level, "debug");
      break;
    case trace:
      strcat(l_level, "trace");
      break;
    case info:
      strcat(l_level, "info");
      break;
    case warning:
      strcat(l_level, "warning");
      break;
    case error:
      strcat(l_level, "error");
      break;
  }
  time_t t = time(NULL);
  struct tm* nTM = localtime(&t);
  char timed[11] = "\0";
  timed[0] = '\0';
  sprintf(timed, " %02d:%02d:%02d ", nTM->tm_hour, nTM->tm_min, nTM->tm_sec);
  char res[77777] = "\0";

  strcat(res, "[\0");
  strcat(res, l_level);
  strcat(res, "]\0");
  strcat(res, timed);
  strcat(res, message);

    for (size_t i = 0; i < strlen(res); i++) {
      fputc(res[i], log_file);
    }

  return 1;
}

int log_close(FILE* log_file) { return fclose(log_file); }