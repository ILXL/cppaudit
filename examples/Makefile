TARGETS = test stylecheck formatcheck all noskiptest grade

.PHONY: $(TARGETS)

$(TARGETS): 
	@$(MAKE) -C tools/cppaudit $(MAKECMDGOALS)

tools/cppaudit:
	@mkdir tools/cppaudit
	
tools/output:
	@mkdir tools/output

tools:
	@mkdir tools
	
cppaudit: tools tools/cppaudit tools/output 
	cp -R $(addprefix ../,$(shell ls ../ | grep -v examples)) tools/cppaudit
	
build: cppaudit
	@clang++ -std=c++17 *.cpp -o main

clean:
	@rm -rf tools/cppaudit
	@rm -rf tools/output
	@rm main
