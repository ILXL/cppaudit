#!/bin/bash
WD=`pwd`
OUTPUT_PATH=$1
EXECFILE=$2
DRIVER=$3
IMPLEMS=$4
HEADERS=$5
ENTRIES="[\n"

ENTRIES=${ENTRIES}"  {\n   \"directory\" : \"$WD\",\n"
ENTRIES=${ENTRIES}"    \"command\" : \"clang++ -std=c++17 $DRIVER -o $2\",\n"
ENTRIES=${ENTRIES}"    \"file\" : \"$WD/$DRIVER\"\n  },\n"

for implem in $IMPLEMS
do
  ENTRIES=${ENTRIES}"  {\n   \"directory\" : \"$WD\",\n"
  ENTRIES=${ENTRIES}"    \"command\" : \"clang++ -std=c++17 $implem -o $2\",\n"
  ENTRIES=${ENTRIES}"    \"file\" : \"$WD/$IMPLEMS\"\n  },\n"
done

for header in $HEADERS
do
  ENTRIES=${ENTRIES}"  {\n   \"directory\" : \"$WD\",\n"
  ENTRIES=${ENTRIES}"    \"command\" : \"clang++ -std=c++17 $header -o $2\",\n"
  ENTRIES=${ENTRIES}"    \"file\" : \"$WD/$HEADERS\"\n  },\n"
done
ENTRIES=${ENTRIES}"]"
echo -e "$OUTPUT_PATH/compile_commands.json"
echo -e $ENTRIES >> $OUTPUT_PATH/compile_commands.json
