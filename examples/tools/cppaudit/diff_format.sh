#!/bin/bash

for file in "$@"
do
  echo -e "\n[Checking $file]"
  # diff --suppress-common-lines --color=always -u1 <(cat $file) <(clang-format $file)
  diff --suppress-common-lines -U1 <(cat $file) <(clang-format $file)
  echo -e "done"
done
exit 0
