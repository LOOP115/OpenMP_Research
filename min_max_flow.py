import networkx as nx
import sys


def get_min_max_flow():
    # Generate graph
    input_path = "inputs/input1.txt"
    if len(sys.argv) > 1:
        input_path = sys.argv[1]
    with open(input_path, 'r') as input_file:
        input_file.readline()
    graph = nx.read_edgelist(input_path, create_using=nx.DiGraph(), data=(("capacity", float),))

    # Compute the minimum of the maximum flows between all pairs of vertices
    min_max_flow = sys.float_info.max
    print(f"\nMax Flow")
    for u in graph.nodes:
        for v in graph.nodes:
            if u == v:
                continue
            flow_value, flow_dict = nx.maximum_flow(graph, u, v)
            if flow_value > 0:
                print(f"{u} to {v}: {str(flow_value)}")
                min_max_flow = min(min_max_flow, flow_value)
    return min_max_flow


print(f"\nMin Max Flow: {get_min_max_flow()}")
