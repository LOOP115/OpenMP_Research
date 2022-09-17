#!python

import networkx as nx
import sys

with open(sys.argv[1], 'r') as of:
  of.readline()
  G = nx.read_edgelist(of, create_using=nx.DiGraph(), data=(("capacity", int), ("cost", int),))

min_max_flow = sys.float_info.max
for u in G.nodes:
	for v in G.nodes:
		if u == v:
			continue

		flow_value, flow_dict = nx.maximum_flow(G, u, v)
		print(u + ", " + v + ": " + str(flow_value))

		if flow_value > 0:
			min_max_flow = min(min_max_flow, flow_value)

print(min_max_flow)
