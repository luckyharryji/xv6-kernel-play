#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "ProcessInfo.h"
 
int
main(int argc, char *argv[])
{
  if(argc > 1){
    printf(1, "usage: ps\n");
    exit();
  }

  struct ProcessInfo *procInfo = malloc(sizeof(struct ProcessInfo) * NPROC);
  int numProcs;
  
  numProcs = getprocs(procInfo);

  if (numProcs < 0) {
    printf(1, "error for ps command\n");
    exit();
  }

  char states [6][16]= {
    {"UNUSED"},
    {"EMBRYO"}, 
    {"SLEEPING"},
    {"RUNNABLE"},
    {"RUNNING"},
    {"ZOMBIE"}
  };

  int i;
  for (i = 0; i < numProcs; i++) {
    printf(1, "%d  %d  %s  %d  %s\n", procInfo->pid, procInfo->ppid, states[procInfo->state],  procInfo->sz, procInfo->name);
    procInfo += 1;
  }

  free(procInfo);
  exit();
}