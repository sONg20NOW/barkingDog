package boj.dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p5719 {

	static class Cell {
		int next, cost;
		String path;
		Cell(int next, int cost, String path) {
			this.next = next;
			this.cost = cost;
			this.path = path;
		}
	}
	
	public static void main(String[] args) {
		
		try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			while(true) {
				int N, M;
				StringTokenizer st = new StringTokenizer(br.readLine());
				N = Integer.parseInt(st.nextToken());
				M = Integer.parseInt(st.nextToken());
				if (N == 0 && M == 0)	break;
				int S, D;
				st = new StringTokenizer(br.readLine());
				S = Integer.parseInt(st.nextToken());
				D = Integer.parseInt(st.nextToken());
				
				List<int[]>[] edges = new List[N];
				for (int i = 0; i < N; i++) {
					edges[i] = new ArrayList<int[]>();
				}
				
				while  (M-- > 0) {
					int u, v, p;
					st = new StringTokenizer(br.readLine());
					u = Integer.parseInt(st.nextToken());
					v = Integer.parseInt(st.nextToken());
					p = Integer.parseInt(st.nextToken());
					edges[u].add(new int[] {v, p});
				}
				
				int[] d = new int[N];
				for (int i = 0; i < N; i++) {
					d[i] = Integer.MAX_VALUE;
				}
				
				PriorityQueue<Cell> PQ = new PriorityQueue<>((a, b) -> Integer.compare(a.cost, b.cost));
				
				d[S] = 0;
				PQ.add(new Cell(S, 0, "" + S));
				
				List<String> min_paths = new ArrayList<>();
				int answer = -1;
				while (!PQ.isEmpty()) {
					Cell cur = PQ.poll();
					if (d[cur.next] < cur.cost)	continue;
					if (cur.next == D) {
						min_paths.add(cur.path);
						continue;
					}
					for (int[] adj : edges[cur.next]) {
						int node = adj[0];
						int new_cost = d[cur.next] + adj[1];
						if (new_cost <= d[node]) {
							d[node] = new_cost;
							PQ.add(new Cell(node, new_cost, cur.path + " " + node));
						}
					}
				}
				
				for (String path : min_paths) {
					st = new StringTokenizer(path);
					int prev = Integer.parseInt(st.nextToken());
					int next;
					while (prev != D) {
						next = Integer.parseInt(st.nextToken());
						// delete edge from prev to next
						for (int[] edge : edges[prev]) {
							if (edge[0] == next) {
								edge[1] = Integer.MAX_VALUE;
							}
						}
						
						prev = next;
					}
				}
				
				d = new int[N];
				for (int i = 0; i < N; i++) {
					d[i] = Integer.MAX_VALUE;
				}
				
				PQ = new PriorityQueue<>((a, b) -> Integer.compare(a.cost, b.cost));
				
				d[S] = 0;
				PQ.add(new Cell(S, 0, "" + S));
				
				while (!PQ.isEmpty()) {
					Cell cur = PQ.poll();
					if (d[cur.next] < cur.cost)	continue;
					if (cur.next == D) {
						break;
					}
					for (int[] adj : edges[cur.next]) {
						if (adj[1] == Integer.MAX_VALUE)	continue;
						int node = adj[0];
						int new_cost = d[cur.next] + adj[1];
						if (new_cost <= d[node]) {
							d[node] = new_cost;
							PQ.add(new Cell(node, new_cost, cur.path + " " + node));
						}
					}
				}
				
				System.out.println(d[D] == Integer.MAX_VALUE ? -1 : d[D]);
			}
		} catch (IOException e) {
			
		}

	}

}
