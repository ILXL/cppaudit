TARGETS = build test stylecheck formatcheck all clean noskiptest

.PHONY: $(TARGETS)

$(TARGETS): 
	@$(MAKE) -C tools/cppaudit $(MAKECMDGOALS)
