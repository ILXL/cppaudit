#!/bin/bash
OS_NAME=`uname -s | tr A-Z a-z`

for file in "$@"
do
  echo -e "\n[Checking $file]"
  if [[ "$OS_NAME" != "darwin" ]]; then
    diff --suppress-common-lines --color=always -u1 <(cat $file) <(clang-format --style=Google $file)
  else
    diff --suppress-common-lines -U1 <(cat $file) <(clang-format $file)
  fi
done
exit 0
