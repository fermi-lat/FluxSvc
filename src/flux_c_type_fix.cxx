/*
Author: Emmanuel Cephas (ecephas@slac.stanford.edu)

This file is needed to resolve the following error:
	lib/redhat4-i686-32bit/libFluxSvc.so: undefined reference to `__ctype_b' 

Basicaly, the shared library, FluxSvc, has to be linked against this object file.  See http://oss.sgi.com/projects/inventor/mail/info-inventor-dev/msg00512.html

*/
 #include <ctype.h>

    extern "C" {
    __const unsigned short int **__wrap___ctype_b (void) {
      return __ctype_b_loc();
    }
    }

