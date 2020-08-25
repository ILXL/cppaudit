TARGETS = build test stylecheck formatcheck all noskiptest grade clean

.PHONY: $(TARGETS)

tools/output:
	@mkdir -p tools/output

$(TARGETS): tools/output
	@$(MAKE) -C tools/cppaudit $(MAKECMDGOALS)


## For example dir only!
tools/cppaudit:
	@mkdir -p tools/cppaudit

cppaudit: tools tools/cppaudit tools/output
	cp -R $(addprefix ../,$(shell ls ../ | grep -v examples)) tools/cppaudit

tclean:
	$(MAKE) -C tools/cppaudit clean

clean:
	@rm -rf tools/cppaudit
	@rm -rf tools/output
	@rm -f main
