TARGETS = build test stylecheck formatcheck all noskiptest grade

BASE_FILES := diff_format.sh  gen_ccjs.sh  gtest_ext.h  LICENSE  Makefile README.md  termcolor

.PHONY: $(TARGETS)

tools/cppaudit:
	@mkdir -p tools/cppaudit
	@for file in $(BASE_FILES); do \
		 cp -R ../$$file tools/cppaudit ; \
	done

$(TARGETS): tools/cppaudit
	@$(MAKE) -C tools/cppaudit $(MAKECMDGOALS)

clean:
	@rm -rf tools/cppaudit
	@rm -rf tools/output
