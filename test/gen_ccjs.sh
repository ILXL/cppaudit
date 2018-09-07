#!/bin/bash
WD=`pwd`
cat << EOF > $WD/test/compile_commands.json
[{
  "directory" : "$WD",
  "command" : "g++ -std=c++17 $1 -o $2",
  "file" : "$WD/$1"
}]
EOF
