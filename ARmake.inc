###########################################################################
#
#  Program:         ARPACK
#
#  Module:          ARmake.inc
#
#  Purpose:         Top-level Definitions
#
#  Creation date:   February 22, 1996
#
#  Send bug reports, comments or suggestions to arpack@caam.rice.edu
#
############################################################################
#
#  ARPACK build directory.
#
ARPACKdir    = $(HOME)/arpack
#
#  The communication library ( need for parallel library only ).
#  Current availible platforms are: BLACS or MPI.
#
COMMLIB      = MPI
#
#  The directories to find the various pieces of ARPACK.
#
BLASdir      = $(ARPACKdir)/BLAS
LAPACKdir    = $(ARPACKdir)/LAPACK
UTILdir      = $(ARPACKdir)/UTIL
SRCdir       = $(ARPACKdir)/SRC
PUTILdir     = $(ARPACKdir)/PARPACK/UTIL/$(COMMLIB)
PSRCdir      = $(ARPACKdir)/PARPACK/SRC/$(COMMLIB)
#
DIRS         = $(BLASdir) $(LAPACKdir) $(UTILdir) $(SRCdir)
#
#  The name of the libraries to be created/linked to.
#
ARPACKLIB    = $(ARPACKdir)/libarpack.a
PARPACKLIB   = $(ARPACKdir)/libparpack.a
#
ALIBS        = $(ARPACKLIB)
#
# Default command.
#
.DEFAULT:
	@$(ECHO) "Unknown target $@, try:  make help"
#
#  Various compilation programs and flags.
#  You need to make sure these are correct
#  for your system.
#
FC           = f77
FFLAGS	     = -fpic
#
PFC          = mpif77
PFFLAGS      = -fpic
#
LDFLAGS      =
#
CD	     = cd
ECHO         = echo
MAKE         = make
#
#   The archiver and the flag(s) to use when building an archive
#   (library).  Also the ranlib routine.  If your system has no
#   ranlib, set RANLIB = touch.
#
AR           = ar
ARFLAGS      = rv
RANLIB       = ranlib
#
#  This is the general help target.
#
help:
	@$(ECHO) "usage: make ?"
