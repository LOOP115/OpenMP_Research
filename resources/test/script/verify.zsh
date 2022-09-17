#!/bin/zsh

for i in $(seq -f "%02g" 0 09)
do
  echo $i
  ./cmake.build/src/project1/Release/project1 -i "test/output/test$i.input" -t 8 -odot "test/output/test$i.result.dot" -otest "test/output/test$i.result.txt" > "test/output/test$i.stdout.txt"
  # Uncomment to generate SVGs of the resulting flows
  # dot -Tsvg -o "test/output/test$i.result.svg" "test/output/test$i.result.dot"
  sort "test/output/test$i.result.txt" -o "test/output/test$i.result.txt"
  diff "test/output/test$i.result.txt" "test/output/test$i.expected.result.txt"
done