import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as animation

class DFSTreeVisualizer:
    def __init__(self, tree):
        self.tree = tree
        self.visited_nodes = set()
        self.edges = []
        self.fig, self.ax = plt.subplots()
        self.pos = None
        self.animation = None

    def dfs_visit(self, node, parent=None):
        self.visited_nodes.add(node)
        if parent is not None:
            self.edges.append((parent, node))
        for child in self.tree[node]:
            if child not in self.visited_nodes:
                self.dfs_visit(child, node)

    def update_graph(self, frame):
        if frame < len(self.edges):
            edge = self.edges[frame]
            self.ax.clear()
            nx.draw_networkx_nodes(self.tree, pos=self.pos, ax=self.ax)
            nx.draw_networkx_edges(self.tree, pos=self.pos, edgelist=self.edges[:frame+1], ax=self.ax, edge_color='r', width=2)
            nx.draw_networkx_labels(self.tree, pos=self.pos, ax=self.ax)
            self.ax.set_title(f"DFS Step {frame + 1}/{len(self.edges)}")

    def visualize_dfs(self, start_node):
        self.dfs_visit(start_node)
        self.pos = nx.layout.spring_layout(self.tree)
        self.animation = animation.FuncAnimation(self.fig, self.update_graph, frames=len(self.edges), interval=1000, repeat=False)
        plt.show()

# Example usage:
# Create a sample tree
tree_edges = [(1, 2), (1, 3), (2, 4), (2, 5), (3, 6), (3, 7)]
tree = nx.Graph(tree_edges)

# Create DFSTreeVisualizer and visualize DFS starting from node 1
tree_visualizer = DFSTreeVisualizer(tree)
tree_visualizer.visualize_dfs(1)


