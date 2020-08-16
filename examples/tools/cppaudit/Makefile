include ../settings/config.mk

OS_NAME 			:= $(shell uname -s | tr A-Z a-z)
SHELL         		:= /bin/bash
OUTPUT_PATH			:= ../output
SETTINGS_PATH		:= ../settings
ROOT_PATH			:= $(shell printf "%q" "$(PWD)")
CPP_AUDIT_PATH		:= $(shell printf "%q" "$$(pwd)")
CPPAUDIT_FROM_ROOT 	:= $(shell realpath --relative-to=$(ROOT_PATH) $(CPP_AUDIT_PATH))
REL_ROOT_PATH		:= $(shell realpath --relative-to=$(CPP_AUDIT_PATH) $(ROOT_PATH))
OUTPUT_FROM_ROOT 	:= $(shell realpath --relative-to=$(ROOT_PATH) $(OUTPUT_PATH))
FILES         		:= $(DRIVER) $(IMPLEMS) $(HEADERS)
HAS_CLANGTDY  		:= $(shell command -v clang-tidy 2> /dev/null)
HAS_CLANGFMT  		:= $(shell command -v clang-format 2> /dev/null)
# Google test library location in Ubuntu
GTEST_LOC			:= /usr/lib/libgtest.a

# Google test library location in MacOSX
ifeq ($(OS_NAME),darwin)
  GTEST_LOC=/usr/local/lib/libgtest.a
endif

.PHONY: test stylecheck formatcheck all clean noskiptest

$(OUTPUT_PATH)/unittest: $(SETTINGS_PATH)/unittest.cpp $(addprefix $(REL_ROOT_PATH)/, $(DRIVER) $(IMPLEMS) $(HEADERS))
	@clang++ -std=c++17 -fsanitize=address $(addprefix $(REL_ROOT_PATH)/, $(IMPLEMS)) $(SETTINGS_PATH)/unittest.cpp -o $(OUTPUT_PATH)/unittest -pthread -lgtest

$(GTEST_LOC):
	@echo -e "google test not installed\n"
ifeq ($(OS_NAME), darwin)
	@echo -e "Installing cmake. Please provide the password when asked\n"
	@brew install cmake
	@echo -e "\nDownloading and installing googletest\n"
	@cd /tmp/; git clone https://github.com/google/googletest; cd googletest; mkdir build; cd build; cmake .. -DCMAKE_CXX_STANDARD=17; make; make install
	@echo -e "Finished installing google test\n"
else
	@echo -e "Installing cmake. Please provide the password when asked\n"
	@sudo apt-get install cmake # install cmake
	@echo -e "\nDownloading and installing googletest\n"
	@sudo apt-get install libgtest-dev libgmock-dev
	@echo -e "Finished installing google test\n"
endif

test: $(GTEST_LOC) $(OUTPUT_PATH)/unittest
	@echo -e "\n========================\nRunning unit test\n========================\n"
	@cd $(REL_ROOT_PATH)/ && ./$(OUTPUT_FROM_ROOT)/unittest --gtest_output="xml:$(OUTPUT_FROM_ROOT)/unittest.xml"
	@echo -e "\n========================\nUnit test complete\n========================\n"

noskiptest: /usr/lib/libgtest.a $(TEST_PATH)/unittest
	@echo -e "\n========================\nRunning unit test\n========================\n"
	@cd $(REL_ROOT_PATH)/ && ./$(OUTPUT_FROM_ROOT)/unittest --noskip --gtest_output="xml:$(OUTPUT_FROM_ROOT)/unittest.xml"
	@echo -e "\n========================\nUnit test complete\n========================\n"

$(OUTPUT_PATH)/compile_commands.json :
	cd $(ROOT_PATH)/ && bash $(CPP_AUDIT_PATH)/gen_ccjs.sh $(OUTPUT_FROM_ROOT) $(EXECFILE) $(DRIVER) $(IMPLEMS) $(HEADERS)

stylecheck: $(OUTPUT_PATH)/compile_commands.json
ifndef HAS_CLANGTDY
	@echo -e "clang-tidy not installed\n"
	@echo -e "Installing clang-tidy. Please provide password when asked\n"
	ifeq ($(OS_NAME),darwin)
		@echo -e "WARNING: Installing llvm to provide stylecheck functionality will take about an hour."
		@brew install llvm
		@ln -s "$(brew --prefix llvm)/bin/clang-tidy" "/usr/local/bin/clang-tidy"
	else
		@sudo apt-get -y install clang-tidy
		@echo -e "Finished installing clang-tidy\n"
	endif
endif
	@echo -e "========================\nRunning style checker\n========================\n"
	cd $(REL_ROOT_PATH)/ && clang-tidy -p=$(OUTPUT_FROM_ROOT) -quiet -checks=$(CLANGTDY_CHKS) -header-filter=.* -export-fixes=$(OUTPUT_FROM_ROOT)/style.yaml $(IMPLEMS) $(HEADERS) $(DRIVER)
	# @clang-tidy -p=$(TEST_PATH) -quiet -checks=$(CLANGTDY_CHKS) -header-filter=.* -export-fixes=test/style.yaml $(IMPLEMS) $(HEADERS) $(DRIVER)
	@echo -e "========================\nStyle checker complete\n========================\n"

formatcheck:
ifndef HAS_CLANGFMT
ifeq ($(OS_NAME),darwin)
	@echo -e "clang-format not installed.\n"
	@echo -e "Installing clang-format. Please provide the password when asked\n"
	@brew install clang-format
	@echo -e "Finished installing clang-format\n"
else
	@echo -e "clang-format not installed.\n"
	@echo -e "Installing clang-format. Please provide the password when asked\n"
	@sudo apt-get -y install clang-format
	@echo -e "Finished installing clang-format\n"
endif
endif
	@echo -e "========================\nRunning format checker\n========================"
	@cd $(REL_ROOT_PATH)/ && bash $(CPPAUDIT_FROM_ROOT)/diff_format.sh $(FILES)
	@cd $(REL_ROOT_PATH)/ && clang-format $(FILES) -output-replacements-xml > $(OUTPUT_FROM_ROOT)/format.xml
	@echo -e "========================\nFormat checking complete\n========================\n"

all:	test stylecheck formatcheck

clean:
	# echo $(CPP_AUDIT_PATH)
	# echo $(ROOT_PATH)
	# echo $(OS_NAME)
	# echo $(GTEST_LOC)
	@rm -f $(OUTPUT_PATH)/unittest.xml
	@rm -f $(OUTPUT_PATH)/style.yaml
	@rm -f $(OUTPUT_PATH)/format.xml
	@rm -f $(OUTPUT_PATH)/compile_commands.json
	@rm -f $(OUTPUT_PATH)/unittest
