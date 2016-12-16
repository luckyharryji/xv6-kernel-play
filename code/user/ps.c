#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "ProcessInfo.h"
 
int
main(int argc, char *argv[])
{
  struct ProcessInfo *procInfo = malloc(sizeof(struct ProcessInfo) * NPROC);
  int numProcs;
  
  numProcs = getprocs(procInfo);

  printf(1, "There are total %d process\n", numProcs);
  
  free(procInfo);
  exit();
}