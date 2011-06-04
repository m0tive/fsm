SCONSPATH=$(shell python -c 'import os.path; print os.path.normpath("site_scons/local/scons.py")' )
SCONS=python $(SCONSPATH)

all:
	@$(SCONS) --test --doxygen --tags

clean:
	@$(SCONS) -c --test

configure:
	@$(SCONS) --configure --test --doxygen --tags

%:
	@$(SCONS) $@

