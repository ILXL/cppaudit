TARGETS = build test stylecheck formatcheck all clean noskiptest grade

.PHONY: $(TARGETS)

$(TARGETS): 
	@$(MAKE) -C tools/cppaudit $(MAKECMDGOALS)
