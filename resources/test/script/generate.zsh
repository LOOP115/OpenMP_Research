#!/bin/zsh

NODES=10
EDGES=50

for i in $(seq -f "%02g" 0 09)
do
  echo $i
  ./cmake.build/src/graph-generate/Release/graph-generate -n ${NODES} -e ${EDGES} -lcap 200 -o "test/output/test$i"
  ./test/script/verify.py "test/output/test$i.input" > "test/output/test$i.expected.result.txt"
  sort "test/output/test$i.expected.result.txt" -o "test/output/test$i.expected.result.txt"
done