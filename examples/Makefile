TARGETS = test stylecheck formatcheck all noskiptest grade

.PHONY: $(TARGETS)

$(TARGETS): 
	@$(MAKE) -C tools/cppaudit $(MAKECMDGOALS)

output:
	@mkdir tools/output

tools:
	@mkdir tools
	
cppaudit: tools output
	@cp -R ../cppaudit tools
	
build: cppaudit
	@clang++ -std=c++17 *.cpp -o main

clean:
	@rm -rf tools/cppaudit
	@rm -rf tools/output
	@rm main
