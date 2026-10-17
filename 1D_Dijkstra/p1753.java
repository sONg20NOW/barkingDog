package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p1753 {
	static class Node {
		int node, cost;
		Node(int node, int cost) {
			this.node = node;
			this.cost = cost;
		}
	}
	
	static int V, E, K;
	static List<Node>[] edges;
	
	public static void main(String[] args) {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			V = Integer.parseInt(st.nextToken());
			E = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(br.readLine());
			
			edges = new List[V+1];
			for (int i = 1; i <= V; i++) {
				edges[i] = new ArrayList<>();
			}
			
			while (E-- > 0) {
				st = new StringTokenizer(br.readLine());
				int u, v, w;
				u = Integer.parseInt(st.nextToken());
				v = Integer.parseInt(st.nextToken());
				w = Integer.parseInt(st.nextToken());
				edges[u].add(new Node(v, w));
			}
			
			int[] d = new int[V+1];
			for (int i = 1; i <= V; i++) {
				d[i] = Integer.MAX_VALUE;
			}
			
			PriorityQueue<Node> PQ = new PriorityQueue<>(
					(a, b) -> Integer.compare(a.cost, b.cost));
			PQ.add(new Node(K, 0));
			d[K] = 0;
			
			while (!PQ.isEmpty()) {
				Node cur = PQ.poll();
				if (d[cur.node] < cur.cost)	continue;
				for (Node adj : edges[cur.node]) {
					if (d[adj.node] > d[cur.node] + adj.cost) {
						d[adj.node] = d[cur.node] + adj.cost;
						PQ.add(new Node(adj.node, d[adj.node]));
					}
				}
			}
			
			for (int i = 1; i <= V; i++) {
				System.out.println(d[i] == Integer.MAX_VALUE ? "INF" : d[i]);
			}
		} catch (IOException e) {
			
		}
		

	}

}
