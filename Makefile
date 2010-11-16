SCONS=python scons-local/scons.py

all:
	@$(SCONS) -Q

clean:
	@$(SCONS) -Qc

%:
	@$(SCONS) $@

