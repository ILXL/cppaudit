#Download base image ubuntu
FROM ubuntu

# Update Software repository
RUN apt-get update 

# Install apps necessary to run unit test
RUN apt-get install -y clang git clang-tidy clang-format make cmake nano

# Additional installation instructions to run google test
RUN cd /tmp/; git clone https://github.com/google/googletest.git; cd googletest; cmake CMakeLists.txt; make; cp -r googletest/include/. /usr/include; cp -r googlemock/include/. /usr/include; cp lib/*.a /usr/lib; cd ..; rm -rf googletest
