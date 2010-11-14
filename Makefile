SCONS=python scons/scons.py

all:
	@$(SCONS) -Q

clean:
	@$(SCONS) -Qc

%:
	@$(SCONS) $@

