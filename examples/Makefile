TARGETS = test stylecheck formatcheck all noskiptest grade clean

.PHONY: $(TARGETS)

tools/output:
	@mkdir -p tools/output

$(TARGETS): tools/output
	@$(MAKE) -C tools/cppaudit $(MAKECMDGOALS)

build:
	clang++ -std=c++17 $(DRIVER) $(IMPLEMS) cpputils/graphics/image.cc -o main $(COMPILE_FLAGS)
