TARGETS = test stylecheck formatcheck all noskiptest grade

.PHONY: $(TARGETS)

$(TARGETS):
	@$(MAKE) -C tools/cppaudit $(MAKECMDGOALS)

tools/output:
	@mkdir -p tools/output

# SETUP ONLY. Do not copy below this line into the problem makefile.

tools/cppaudit:
	@mkdir -p tools/cppaudit

cppaudit: tools tools/cppaudit tools/output
	cp -R $(addprefix ../,$(shell ls ../ | grep -v examples)) tools/cppaudit

build: cppaudit
	@clang++ -std=c++17 *.cpp -o main

tclean:
	$(MAKE) -C tools/cppaudit clean

clean:
	@rm -rf tools/cppaudit
	@rm -rf tools/output
	@rm -f main
