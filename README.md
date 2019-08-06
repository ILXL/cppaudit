# CPP Code Analyzer

[![gtest-extension v0.1.1-beta](https://img.shields.io/badge/gtest--extension-v0.1.1--beta-brightgreen.svg)](https://github.com/ILXL/gtest-extension)

**Current version**: v0.3-beta

**Availability**: Linux

# Docker
You can use docker to setup an environment with googletest that you can use for this library. Use the following steps to setup the environment.

1. Create a docker image
```docker build -t pinventado/gtestenv:latest -t pinventado/gtestenv:1.0 .```

1. Run the docker container
Pattern
```docker run -it -d --name <name> <image name>```

Example
```docker run -it -d --name gtest gtestenv```

Alternatively, you can also attach it to a volume to allow editing files from the host OS.
Pattern
```docker run -it -d -v <absolute path in local machine>:<path in container> --name <name> <image name>```

Example
```docker run -it -d -v /Users/pinventado/Dropbox\ \(CSU\ Fullerton\)/Research/ILXL/CPP/volume/:/home/ --name gtest```

1. Connect to the docker container
Pattern
```docker attach <id or name>```

Example
```docker attach gtest```

1. Disconnect from the docker container
You can disconnect from the container to go back to your host OS, but keep it running in the background. Press the following keys from inside the docker container.

<kbd>CTRL</kbd>+<kbd>P</kbd>+<kbd>Q</kbd>

1. Shutdown the docker container
If you are done using the docker container, you can exit out of it and this will shutdown the container. Take note that you will lose all data in the container when you shut it down. Running the container using the same image will open an entirely new instance. Type the following command from inside the docker container.
```exit```