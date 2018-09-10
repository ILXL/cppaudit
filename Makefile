TEST_PATH	:= test
EXECFILE	:= restaurant
FILENAMES 	:= restaurant.cc
SHELL		:= /bin/bash
HAS_CLANGTDY	:= $(shell command -v clang-tidy 2> /dev/null)
HAS_CLANGFMT	:= $(shell command -v clang-format 2> /dev/null)


.PHONY: test stylecheck formatcheck all clean

$(TEST_PATH)/unittest: $(TEST_PATH)/unittest.cc
	@g++ -std=c++17 $(TEST_PATH)/unittest.cc -o $(TEST_PATH)/unittest -pthread -lgtest

/usr/lib/libgtest.a:
	@echo -e "google test library not installed\n"
	@echo -e "Installing libgtest-dev. Please provide the password when asked\n"
	@sudo apt-get -y install libgtest-dev cmake
	@sudo apt-get install cmake # install cmake
	@echo -e "\nConfiguring libgtest-dev\n"
	@cd /usr/src/gtest; sudo cmake CMakeLists.txt; sudo make; sudo cp *.a /usr/lib
	@echo -e "Finished installing google test library\n"

test: /usr/lib/libgtest.a $(TEST_PATH)/unittest
	@echo -e "\n========================\nRunning unit test\n========================\n"
	@./$(TEST_PATH)/unittest --gtest_output="xml:test/unittest.xml"
	@echo -e "\n========================\nUnit test complete\n========================\n"

$(TEST_PATH)/compile_commands.json :
	@sh test/gen_ccjs.sh $(FILENAMES) $(EXECFILE)
ifndef HAS_CLANGTDY
	@echo -e "clang-tidy not installed\n"
	@echo -e "Installing clang-tidy. Please provide password when asked\n"
	@sudo apt-get -y install clang-tidy
	@echo -e "Finished installing clang-tidy\n"
endif

stylecheck: $(TEST_PATH)/compile_commands.json
	@echo -e "========================\nRunning style checker\n========================\n"
	@clang-tidy -p=$(TEST_PATH) -quiet -checks=*,-google-build-using-namespace -export-fixes=test/error.yaml $(FILENAMES)
	@echo -e "========================\nStyle checker complete\n========================\n"

formatcheck:
ifndef HAS_CLANGFMT
	@echo -e "clang-format not installed.\n"
	@echo -e "Installing clang-format. Please provide the password when asked\n"
	@sudo apt-get -y install clang-format
	@echo -e "Finished installing clang-format\n"
endif
	@echo -e "========================\nRunning format checker\n========================\n"
	@diff --suppress-common-lines --color=always -u1 <(cat $(FILENAMES)) <(clang-format $(FILENAMES)) || exit 0
	@clang-format $(FILENAMES) -output-replacements-xml > format.xml
	@echo -e "========================\nFormat checking complete\n========================\n"

all:	test stylecheck formatcheck

clean:
	@rm -f $(TEST_PATH)/unittest.xml
	@rm -f $(TEST_PATH)/error.yaml
	@rm -f $(TEST_PATH)/format.xml
	@rm -f $(TEST_PATH)/unittest
