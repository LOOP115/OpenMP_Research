Test files for verifying algorithm correctness.

## Workflow

- Run ./script/generate.zsh to:
  - Generate a bunch of sample input files
  - Run them through the verifier provided by subject staff and save the output
  - For each generated graph, you should get
    - Sample output (with file suffix `expected.result.txt`)
    - Graphviz file (suffix `.dot`)
    - Input data file (suffix `.input`)
    - SVG image file generated from the `.dot` file (suffix `.svg`)

- Run ./script/verify.zsh to:
  - Run your solution on all the sample input files
  - Diff the resulting output against that of the verifier
  - Produce a `.dot` and `.svg` file pair showing the minimum maximum flow found

## Hacking

You'll probably need to change the paths to the graph generator and solution so that they match your setup.

Additionally the input file format might be different to what you're using.

In brief, the input file format here is:

```
num_nodes num_edges
edge_origin edge_destination capacity cost
```