## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project2

project2_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	GDU.c GDU.h \
	election.c election.h \
	reclamation.c reclamation.h \
	BV.c BV.h \
	electionsfat.c elections1.h

project2_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

