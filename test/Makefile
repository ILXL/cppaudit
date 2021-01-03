BASE_FILES := diff_format.sh  gen_ccjs.sh  gtest_ext.h  LICENSE  README.md  termcolor

test:
	for file in $(BASE_FILES); do \
		 cp -R ../$$file . ; \
	done

clean:
	rm -rf $(BASE_FILES)
	rm -rf main
