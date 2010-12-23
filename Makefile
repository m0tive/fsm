SCONSPATH=$(shell python -c 'import os.path; print os.path.normpath("scons-local/scons.py")' )
SCONS=python $(SCONSPATH)

all:
	@$(SCONS) --test --doxygen

clean:
	@$(SCONS) -c --test

%:
	@$(SCONS) $@

