TARGETS = build test stylecheck formatcheck all clean noskiptest

.PHONY: $(TARGETS)

$(TARGETS): 
	echo $(ROOT_DIR)
	$(MAKE) -C tools/cppaudit $(MAKECMDGOALS)
